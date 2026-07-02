#include <drogon/drogon.h>
#include <spdlog/spdlog.h>

#include "Config.hpp"
#include "HealthRoutes.hpp"
#include "FlightRoutes.hpp"

using namespace waste_detection::flight_service;


int main() {
    try{
        spdlog::set_level(spdlog::level::info);

        spdlog::info("Starting detection-job-service...");

        spdlog::info("Reading config...");
        db_config::Config db;
        db = db_config::loadJobsDbConfig();
        spdlog::info("Config loaded successfully");

        spdlog::info("Registering routes...");
        routes::registerHealthRoutes();
        routes::registerJobRoutes();
        spdlog::info("Routes registered");

        spdlog::info("Starting HTTP server on 0.0.0.0:8080");
        drogon::app()
            .addListener("0.0.0.0", 8080)
            .setThreadNum(4)
            .run(); 
        // тоже самое что и  auto& app = drogon::app(); т.к. возвращает *this, поэтому можно сократить
        // app.addListener("0.0.0.0", 8080);
        // app.setThreadNum(4);
        // app.run();
    } catch (const std::exception& error) {
        spdlog::error("Failed to start detection-job-service: {}", error.what());
        return 1;
    }


}