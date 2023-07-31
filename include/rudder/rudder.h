#pragma once

#include <string>

#include "rudder/message.h"
#include "rudder/alias.h"
#include "rudder/group.h"
#include "rudder/page.h"
#include "rudder/track.h"
#include "rudder/screen.h"
#include "rudder/identify.h"
#include "rudder/messagetype.h"

namespace rudder {

class Rudder {
public:
    explicit Rudder(const std::string& writeKey, const std::string& dataPlaneUrl);

    void send(const std::unique_ptr<Message>& message) const;

private:
    std::string mWriteKey;
    std::string mDataPlaneURL;
};

} // namespace rudder;
