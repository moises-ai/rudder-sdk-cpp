#include "rudder/group.h"
#include "rudder/utils.h"

namespace rudder {

nlohmann::json Group::compose() {
    validateUserId();
    validateAndUpdateContext();

    auto json = nlohmann::json();

    json["groupId"] = mGroupId;

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

    return json;
}

Group::Group() : Message(MessageType::Group) {}

GroupBuilder::GroupBuilder(const std::string& groupId) {
    mGroup.mGroupId = groupId;
}

GroupBuilder& GroupBuilder::withUserId(const std::string& userId) {
    mGroup.mUserId = userId;
    return *this;
}

GroupBuilder& GroupBuilder::withAnonymousId(const std::string& anonymousId) {
    mGroup.mAnonymousId = anonymousId;
    return *this;
}

GroupBuilder& GroupBuilder::withTraits(const nlohmann::json& traits) {
    mGroup.mTraits = traits;
    return *this;
}

GroupBuilder& GroupBuilder::withTimestamp(const Timestamp& timestamp) {
    mGroup.mTimestamp = timestamp;
    return *this;
}

GroupBuilder& GroupBuilder::withContext(const nlohmann::json& context) {
    mGroup.mContext = context;
    return *this;
}

GroupBuilder& GroupBuilder::withIntegrations(const nlohmann::json& integrations) {
    mGroup.mIntegrations = integrations;
    return *this;
}

std::unique_ptr<Group> GroupBuilder::build() {
    auto ptr = std::unique_ptr<Group>(new Group(mGroup));
    ptr->insertTimestamp();
    return std::move(ptr);
}

} // namespace rudder;

