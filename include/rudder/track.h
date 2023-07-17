#pragma once

#include <optional>
#include <string>

#include <nlohmann/json.hpp>

#include "rudder/message.h"
#include "rudder/timestamp.h"

namespace rudder {

class Track final : public Message {
public:
    friend class TrackBuilder;
public:
    nlohmann::json compose() override;

private:
    Track();

private:
    std::optional<std::string> mEvent;
    std::optional<nlohmann::json> mProperties;
    std::optional<nlohmann::json> mIntegrations;
};


class TrackBuilder {
public:
    TrackBuilder& withUserId(const std::string& userId);
    TrackBuilder& withAnonymousId(const std::string& anonymousId);
    TrackBuilder& withEvent(const std::string& event);
    TrackBuilder& withTimestamp(const Timestamp& timestamp);
    TrackBuilder& withContext(const nlohmann::json& context);
    TrackBuilder& withProperties(const nlohmann::json& properties);
    TrackBuilder& withIntegrations(const nlohmann::json& integrations);

    std::unique_ptr<Track> build();

private:
    Track mTrack;
};

} // namespace rudder;


