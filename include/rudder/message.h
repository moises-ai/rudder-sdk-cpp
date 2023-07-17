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
    virtual nlohmann::json compose() = 0;

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

};

} // namespace rudder;

