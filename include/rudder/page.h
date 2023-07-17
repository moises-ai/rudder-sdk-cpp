#pragma once

#include <optional>
#include <string>

#include <nlohmann/json.hpp>

#include "rudder/message.h"
#include "rudder/timestamp.h"

namespace rudder {

class Page final : public Message {
public:
    friend class PageBuilder;

public:
    nlohmann::json compose() override;

private:
    Page();

private:
    std::string mName;
    std::optional<nlohmann::json> mIntegrations;
    std::optional<nlohmann::json> mProperties;
};


class PageBuilder {
public:
    PageBuilder(const std::string& name);

public:
    PageBuilder& withUserId(const std::string& userId);
    PageBuilder& withAnonymousId(const std::string& anonymousId);
    PageBuilder& withTimestamp(const Timestamp& timestamp);
    PageBuilder& withContext(const nlohmann::json& context);
    PageBuilder& withIntegrations(const nlohmann::json& integrations);
    PageBuilder& withProperties(const nlohmann::json& properties);

    std::unique_ptr<Page> build();

private:
    Page mPage;
};

} // namespace rudder;


