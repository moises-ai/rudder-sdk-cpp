#include "rudder/screen.h"
#include "rudder/utils.h"

namespace rudder {

nlohmann::json Screen::compose() {
    validateUserId();
    validateAndUpdateContext();

    auto json = nlohmann::json();

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

Screen::Screen() : Message(MessageType::Screen) {}

ScreenBuilder::ScreenBuilder(const std::string& name) {
    mScreen.mName = name;
}

ScreenBuilder& ScreenBuilder::withUserId(const std::string& userId) {
    mScreen.mUserId = userId;
    return *this;
}

ScreenBuilder& ScreenBuilder::withAnonymousId(const std::string& anonymousId) {
    mScreen.mAnonymousId = anonymousId;
    return *this;
}

ScreenBuilder& ScreenBuilder::withProperties(const nlohmann::json& properties) {
    mScreen.mProperties = properties;
    return *this;
}

ScreenBuilder& ScreenBuilder::withTimestamp(const Timestamp& timestamp) {
    mScreen.mTimestamp = timestamp;
    return *this;
}

ScreenBuilder& ScreenBuilder::withContext(const nlohmann::json& context) {
    mScreen.mContext = context;
    return *this;
}

ScreenBuilder& ScreenBuilder::withIntegrations(const nlohmann::json& integrations) {
    mScreen.mIntegrations = integrations;
    return *this;
}

std::unique_ptr<Screen> ScreenBuilder::build() {
    auto ptr = std::unique_ptr<Screen>(new Screen(mScreen));
    ptr->insertTimestamp();
    return std::move(ptr);
}

} // namespace rudder;

