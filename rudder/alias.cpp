#include "rudder/alias.h"
#include "rudder/utils.h"

namespace rudder {

nlohmann::json Alias::compose() {
    validateUserId();
    validateAndUpdateContext();

    auto json = nlohmann::json();

    json["previousId"] = mPreviousId;

    if (const auto& userId = mUserId) {
        json["userId"] = *userId;
    }
    if (const auto& context = mContext) {
        json["context"] = *context;
    }
    if (const auto& integrations = mIntegrations) {
        json["integrations"] = *integrations;
    }
    if (const auto& traits = mTraits) {
        json["traits"] = *traits;
    }
    if (const auto& timestamp = mTimestamp) {
        json["timestamp"] = (*timestamp).getValue();
    }

    return json;
}

Alias::Alias() : Message(MessageType::Alias) {}


AliasBuilder::AliasBuilder(const std::string& previousId) {
    mAlias.mPreviousId = previousId;
}

AliasBuilder& AliasBuilder::withUserId(const std::string& userId) {
    mAlias.mUserId = userId;
    return *this;
}

AliasBuilder& AliasBuilder::withContext(const nlohmann::json& context) {
    mAlias.mContext = context;
    return *this;
}

AliasBuilder& AliasBuilder::withIntegrations(const nlohmann::json& integrations) {
    mAlias.mIntegrations = integrations;
    return *this;
}

AliasBuilder& AliasBuilder::withTraits(const nlohmann::json& traits) {
    mAlias.mTraits = traits;
    return *this;
}

AliasBuilder& AliasBuilder::withTimestamp(const Timestamp& timestamp) {
    mAlias.mTimestamp = timestamp;
    return *this;
}

std::unique_ptr<Alias> AliasBuilder::build() {
    auto ptr = std::unique_ptr<Alias>(new Alias(mAlias));
    ptr->insertTimestamp();
    return std::move(ptr);
}

} // namespace rudder;

