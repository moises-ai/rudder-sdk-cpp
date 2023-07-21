#pragma once

#include <string>

namespace rudder {

class MessageType {
public:
    enum Value : uint8_t {
        Identify,
        Track,
        Page,
        Screen,
        Group,
        Alias
    };

public:
    MessageType() = default;
    constexpr MessageType(Value type) : mValue(type) { }

public:
    constexpr operator Value() const { return mValue; }
    explicit operator bool() const = delete;

    constexpr bool operator==(MessageType a) const { return mValue == a.mValue; }
    constexpr bool operator!=(MessageType a) const { return mValue != a.mValue; }

public:
    [[nodiscard]] std::string to_string() const {
        switch (mValue) {
            case Value::Identify:
                return "identify";
            case Value::Track:
                return "track";
            case Value::Page:
                return "page";
            case Value::Screen:
                return "screen";
            case Value::Group:
                return "group";
            case Value::Alias:
                return "alias";
        }
    }

private:
    Value mValue;
};

} // namespace rudder;
