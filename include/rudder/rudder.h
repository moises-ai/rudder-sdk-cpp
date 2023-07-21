#pragma once

#include <string>

#include "rudder/message.h"

namespace rudder {

class Rudder {
public:
    explicit Rudder(const std::string& writeKey, const std::string& dataPlaneUrl);

    void send(std::unique_ptr<Message> message) const;

private:
    std::string mWriteKey;
    std::string mDataPlaneURL;
};

} // namespace rudder;
