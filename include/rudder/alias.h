#pragma once

#include <optional>
#include <string>

#include <nlohmann/json.hpp>

#include "rudder/message.h"
#include "rudder/timestamp.h"

namespace rudder {

class Alias final : public Message {
public:
    friend class AliasBuilder;

public:
    nlohmann::json compose() override;

private:
    Alias();

private:
    std::string mPreviousId;
    std::optional<nlohmann::json> mIntegrations;
    std::optional<nlohmann::json> mTraits;
};


class AliasBuilder {
public:
    AliasBuilder(const std::string& previousId);

public:
    AliasBuilder& withUserId(const std::string& userId);
    AliasBuilder& withContext(const nlohmann::json& context);
    AliasBuilder& withIntegrations(const nlohmann::json& integrations);
    AliasBuilder& withTraits(const nlohmann::json& traits);
    AliasBuilder& withTimestamp(const Timestamp& timestamp);

    std::unique_ptr<Alias> build();

private:
    Alias mAlias;
};

} // namespace rudder;


