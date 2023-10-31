#include "rudder/identify.h"
#include "rudder/utils.h"

namespace rudder {

nlohmann::json Identify::compose() {
    validateUserId();
    validateAndUpdateContext();

    auto json = Message::compose();

    if (const auto& userId = mUserId) {
        json["userId"] = *userId;
    }
    if (const auto& anonymousId = mAnonymousId) {
        json["anonymousId"] = *anonymousId;
    }
    if (const auto& context = mContext) {
        json["context"] = *context;
    }
    if (const auto& timestamp = mTimestamp) {
        json["timestamp"] = (*timestamp).getValue();
    }
    if (const auto& traits = mTraits) {
        json["traits"] = *traits;
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
    ptr->insertTimestamp();
    return std::move(ptr);
}

} // namespace rudder;

