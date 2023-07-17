#include "rudder/track.h"
#include "rudder/utils.h"

namespace rudder {

nlohmann::json Track::compose() {
    validateUserId();
    validateAndUpdateContext();

    auto json = nlohmann::json();

    if (const auto& userId = mUserId) {
        json["user_id"] = *userId;
    }
    if (const auto& anonymousId = mAnonymousId) {
        json["anonymous_id"] = *anonymousId;
    }
    if (const auto& context = mContext) {
        json["context"] = *context;
    }
    if (const auto& timestamp = mTimestamp) {
        json["timestamp"] = (*timestamp).getValue();
    }
    if (const auto& integrations = mIntegrations) {
        json["integrations"] = *integrations;
    }
    if (const auto& event = mEvent) {
        json["event"] = *event;
    }
    if (const auto& properties = mProperties) {
        json["properties"] = *properties;
    }

    return json;
}

Track::Track() : Message(MessageType::Identify) {}

TrackBuilder& TrackBuilder::withUserId(const std::string& userId) {
    mTrack.mUserId = userId;
    return *this;
}

TrackBuilder& TrackBuilder::withAnonymousId(const std::string& anonymousId) {
    mTrack.mAnonymousId = anonymousId;
    return *this;
}

TrackBuilder& TrackBuilder::withEvent(const std::string& event) {
    mTrack.mEvent = event;
    return *this;
}

TrackBuilder& TrackBuilder::withTimestamp(const Timestamp& timestamp) {
    mTrack.mTimestamp = timestamp;
    return *this;
}

TrackBuilder& TrackBuilder::withContext(const nlohmann::json& context) {
    mTrack.mContext = context;
    return *this;
}
TrackBuilder& TrackBuilder::withProperties(const nlohmann::json& properties) {
    mTrack.mProperties = properties;
    return *this;
}

TrackBuilder& TrackBuilder::withIntegrations(const nlohmann::json& integrations) {
    mTrack.mIntegrations = integrations;
    return *this;
}

std::unique_ptr<Track> TrackBuilder::build() {
    auto ptr = std::unique_ptr<Track>(new Track(mTrack));
    ptr->insertTimestamp();
    return std::move(ptr);
}

} // namespace rudder;

