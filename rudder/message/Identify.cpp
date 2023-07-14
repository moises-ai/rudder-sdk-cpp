#include "Identify.h"

namespace rudder {

nlohmann::json Identify::compose() {
    if (!mUserId.has_value() && !mAnonymousId.has_value()) {
        throw std::runtime_error("Only one user should be assigned at a time");
    }
    if (mContext.has_value()) {
        // Check if reserved key;
    }

    auto json = nlohmann::json();

    if (const auto& userId = mUserId) {
        json["user_id"] = *userId;
    }
    if (const auto& anonymousId = mAnonymousId) {
        json["anonymous_id"] = *anonymousId;
    }
    if (const auto& traits = mTraits) {
        json["traits"] = *traits;
    }
    if (const auto& timestamp = mTimestamp) {
        json["timestamp"] = (*timestamp).getValue();
    }
    if (const auto& context = mContext) {
        json["context"] = *context;
    }
    if (const auto& integrations = mIntegrations) {
        json["integrations"] = *integrations;
    }

    return json;
}

Identify::Identify() : Message(MessageType::Identify) {}

IdentifyBuilder& IdentifyBuilder::withUserId(const std::string& userId) {
    mIdentify.mUserId = userId;
    return *this;
}

IdentifyBuilder& IdentifyBuilder::withAnonymousId(const std::string& anonymousId) {
    mIdentify.mAnonymousId = anonymousId;
    return *this;
}

IdentifyBuilder& IdentifyBuilder::withTraits(const nlohmann::json& traits) {
    mIdentify.mTraits = traits;
    return *this;
}

IdentifyBuilder& IdentifyBuilder::withTimestamp(const Timestamp& timestamp) {
    mIdentify.mTimestamp = timestamp;
    return *this;
}

IdentifyBuilder& IdentifyBuilder::withContext(const nlohmann::json& context) {
    mIdentify.mContext = context;
    return *this;
}

IdentifyBuilder& IdentifyBuilder::withIntegrations(const nlohmann::json& integrations) {
    mIdentify.mIntegrations = integrations;
    return *this;
}

std::unique_ptr<Identify> IdentifyBuilder::build() {
    auto ptr = std::unique_ptr<Identify>(new Identify(mIdentify));
    return std::move(ptr);
}

} // namespace rudder;

