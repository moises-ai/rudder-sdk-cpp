#pragma once

#include <optional>
#include <string>

#include <nlohmann/json.hpp>

#include "rudder/message.h"
#include "rudder/timestamp.h"

namespace rudder {

class Identify final : public Message {
public:
    friend class IdentifyBuilder;
public:
    nlohmann::json compose() override;

private:
    Identify();

private:
    std::optional<nlohmann::json> mTraits;
    std::optional<nlohmann::json> mIntegrations;
};


class IdentifyBuilder {
public:
    IdentifyBuilder& withUserId(const std::string& userId);
    IdentifyBuilder& withAnonymousId(const std::string& anonymousId);
    IdentifyBuilder& withTraits(const nlohmann::json& traits);
    IdentifyBuilder& withTimestamp(const Timestamp& timestamp);
    IdentifyBuilder& withContext(const nlohmann::json& context);
    IdentifyBuilder& withIntegrations(const nlohmann::json& integrations);

    std::unique_ptr<Identify> build();

private:
    Identify mIdentify;
};

} // namespace rudder;


