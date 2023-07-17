#pragma once

#include <optional>
#include <string>

#include <nlohmann/json.hpp>

#include "rudder/message.h"
#include "rudder/timestamp.h"

namespace rudder {

class Group final : public Message {
public:
    friend class GroupBuilder;

public:
    nlohmann::json compose() override;

private:
    Group();

private:
    std::string mGroupId;
    std::optional<nlohmann::json> mTraits;
    std::optional<nlohmann::json> mIntegrations;
};


class GroupBuilder {
public:
    GroupBuilder(const std::string& groupId);

public:
    GroupBuilder& withAnonymousId(const std::string& anonymousId);
    GroupBuilder& withUserId(const std::string& userId);
    GroupBuilder& withContext(const nlohmann::json& context);
    GroupBuilder& withIntegrations(const nlohmann::json& integrations);
    GroupBuilder& withTraits(const nlohmann::json& traits);
    GroupBuilder& withTimestamp(const Timestamp& timestamp);

    std::unique_ptr<Group> build();

private:
    Group mGroup;
};

} // namespace rudder;


