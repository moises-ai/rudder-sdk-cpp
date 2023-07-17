#pragma once

#include <optional>
#include <string>

#include <nlohmann/json.hpp>

#include "rudder/message.h"
#include "rudder/timestamp.h"

namespace rudder {

class Screen final : public Message {
public:
    friend class ScreenBuilder;

public:
    nlohmann::json compose() override;

private:
    Screen();

private:
    std::string mName;
    std::optional<nlohmann::json> mIntegrations;
    std::optional<nlohmann::json> mProperties;
};


class ScreenBuilder {
public:
    ScreenBuilder(const std::string& name);

public:
    ScreenBuilder& withUserId(const std::string& userId);
    ScreenBuilder& withAnonymousId(const std::string& anonymousId);
    ScreenBuilder& withTimestamp(const Timestamp& timestamp);
    ScreenBuilder& withContext(const nlohmann::json& context);
    ScreenBuilder& withIntegrations(const nlohmann::json& integrations);
    ScreenBuilder& withProperties(const nlohmann::json& properties);

    std::unique_ptr<Screen> build();

private:
    Screen mScreen;
};

} // namespace rudder;


