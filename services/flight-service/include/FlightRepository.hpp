#pragma once

#include <drogon/orm/DbClient.h>

#include <optional>
#include <string>
#include <vector>

#include "models/Flights.h"
#include "models/FlightImages.h"


namespace waste_detection::flight_service::bd {

using FlightModel = drogon_model::flights_db::Flights;
using FlightImageModel = drogon_model::flights_db::FlightImages;

class FlightRepository {
public:
    explicit FlightRepository(drogon::orm::DbClientPtr dbClient);

    bool flightExistsByInputDir(const std::string& inputDir);

    int createFlight(
        const std::string& name,
        const std::string& inputDir,
        int totalImages
    );

    void createFlightImage(
        int flightId,
        const std::string& imageName,
        const std::string& imagePath
    );

    std::vector<FlightModel> findAllFlights();

    std::optional<FlightModel> findFlightById(int flightId);

    std::vector<FlightImageModel> findImagesByFlightId(int flightId);

private:
    drogon::orm::DbClientPtr dbClient_;
};

}