#include "Timestamp.h"

Timestamp Timestamp::now() {
    time_t now;
    time(&now);

    char buffer[30];
    strftime(buffer, sizeof(buffer), "%FT%TZ", gmtime(&now));

    return Timestamp(std::string(buffer));
}

std::string Timestamp::getValue() const {
    return mValue;
}

Timestamp::Timestamp(const std::string& timepoint) : mValue(timepoint) {}

