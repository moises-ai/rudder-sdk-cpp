#pragma once

#include "Message.h"
#include "Timestamp.h"

namespace rudder {

class Identify final : public Message {
public:
    friend class IdentifyBuilder;
public:
    nlohmann::json compose() override;

private:
    Identify();

private:
    std::optional<std::string> mUserId;
    std::optional<std::string> mAnonymousId;
    std::optional<nlohmann::json> mTraits;
    std::optional<Timestamp> mTimestamp;
    std::optional<nlohmann::json> mContext;
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


