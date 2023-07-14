#pragma once

#include <ctime>
#include <string>

class Timestamp {
public:
    static Timestamp now();

    [[nodiscard]] std::string getValue() const;

private:
    Timestamp(const std::string& timepoint);

    std::string mValue;
};
