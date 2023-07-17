#pragma once

#include <array>
#include <nlohmann/json.hpp>

namespace rudder {
    inline std::array<const char*, 1> RESERVED_KEYS{"library"};
    inline const char* NAME = "rudder-sdk-cpp";
    inline const char* VERSION = "0.0.1";

    inline bool hasReservedKeys(const nlohmann::json& json) {
        for (const auto& key : RESERVED_KEYS) {
            if (json.contains(key)) {
                return true;
            }
        }
        return false;
    }

    inline nlohmann::json getDefaultContext() {
        return nlohmann::json{{
            "library", { 
                {"name", NAME},
                {"version", VERSION}
            }
        }};
    }
} // namespace rudder;
