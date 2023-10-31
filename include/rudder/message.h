#pragma once

#include <optional>
#include <string>

#include "rudder/messagetype.h"
#include "rudder/timestamp.h"

#include <nlohmann/json.hpp>

namespace rudder {

class Message {
public:
    Message(MessageType type);
    virtual ~Message() = default;

public:
    virtual nlohmann::json compose();

public:
    MessageType getType() const;
    void withEvent(const std::string& eventName);

protected:
    void insertTimestamp();
    void validateUserId() const;
    void validateAndUpdateContext();

protected:
    MessageType mMessageType;
    std::optional<Timestamp> mTimestamp;
    std::optional<std::string> mUserId;
    std::optional<std::string> mAnonymousId;
    std::optional<nlohmann::json> mContext;
    std::optional<std::string> mEvent;

};

} // namespace rudder;

