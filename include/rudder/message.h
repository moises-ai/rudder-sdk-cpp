#pragma once

#include "rudder/messagetype.h"

#include <nlohmann/json.hpp>

namespace rudder {

class Message {
public:
    Message(MessageType type) : mMessageType(type) {}
    virtual ~Message() = default;

public:
    virtual nlohmann::json compose() = 0;

protected:
    MessageType mMessageType;

};

} // namespace rudder;

