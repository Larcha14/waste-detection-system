#include "HealthRoutes.hpp"

#include <drogon/drogon.h>
#include <json/json.h>

namespace waste_detection::flight_service::routes {
    void registerHealthRoutes() {
        drogon::app().registerHandler(
            "/health",
            [](const drogon::HttpRequestPtr& req,
            std::function<void(const drogon::HttpResponsePtr&)>&& callback)
            {
                Json::Value json;
                json["status"] = "ok";

                auto response =
                    drogon::HttpResponse::newHttpJsonResponse(json);

                callback(response);
            },
            {drogon::Get}
        );
    }
}