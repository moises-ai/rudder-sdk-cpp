#include "rudder/rudder.h"

#include <ctime>
#include <iostream>
#include "cpr/auth.h"
#include "cpr/cpr.h"

#define TIMEOUT_DURATION 10'000

namespace rudder {
    Rudder::Rudder(
        const std::string& writeKey, 
        const std::string& dataPlaneUrl
    ) : mWriteKey(writeKey), mDataPlaneURL(dataPlaneUrl) {}

    void Rudder::send(std::unique_ptr<Message> message) const {
        const auto payload = message->compose();
        const auto response = cpr::Post(
            cpr::Url { mDataPlaneURL + "/v1/" + message->getType().to_string() },
            cpr::Authentication{mWriteKey, "", cpr::AuthMode::BASIC},
            cpr::Header {
                { "Content-Type", "application/json" }
            },
            cpr::Timeout { TIMEOUT_DURATION },
            cpr::Body { payload.dump() }
        );

        if (response.status_code != 200) {
            throw std::runtime_error("Failed with code: " + std::to_string(response.status_code));
        }

    }
} // namespace rudder;
