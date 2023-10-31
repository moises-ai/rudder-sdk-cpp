#include "rudder/page.h"
#include "rudder/utils.h"

namespace rudder {

nlohmann::json Page::compose() {
    validateUserId();
    validateAndUpdateContext();

    auto json = Message::compose();

    json["name"] = mName;

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
    if (const auto& properties = mProperties) {
        json["properties"] = *properties;
    }
    if (const auto& integrations = mIntegrations) {
        json["integrations"] = *integrations;
    }

    return json;
}

Page::Page() : Message(MessageType::Page) {}

PageBuilder::PageBuilder(const std::string& name) {
    mPage.mName = name;
}

PageBuilder& PageBuilder::withUserId(const std::string& userId) {
    mPage.mUserId = userId;
    return *this;
}

PageBuilder& PageBuilder::withAnonymousId(const std::string& anonymousId) {
    mPage.mAnonymousId = anonymousId;
    return *this;
}

PageBuilder& PageBuilder::withProperties(const nlohmann::json& properties) {
    mPage.mProperties = properties;
    return *this;
}

PageBuilder& PageBuilder::withTimestamp(const Timestamp& timestamp) {
    mPage.mTimestamp = timestamp;
    return *this;
}

PageBuilder& PageBuilder::withContext(const nlohmann::json& context) {
    mPage.mContext = context;
    return *this;
}

PageBuilder& PageBuilder::withIntegrations(const nlohmann::json& integrations) {
    mPage.mIntegrations = integrations;
    return *this;
}

std::unique_ptr<Page> PageBuilder::build() {
    auto ptr = std::unique_ptr<Page>(new Page(mPage));
    ptr->insertTimestamp();
    return std::move(ptr);
}

} // namespace rudder;

