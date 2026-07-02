#include "Config.hpp"
#include "EnvReader.hpp"
#include <cstdlib>

namespace  waste_detection::flight_service::db_config {

Config loadJobsDbConfig() {
    return Config{
        waste_detection::lib::getEnvRequired("FLIGHTS_DB_HOST"),
        waste_detection::lib::getEnvIntRequired("FLIGHTS_DB_PORT"),
        waste_detection::lib::getEnvRequired("FLIGHTS_DB_USER"),
        waste_detection::lib::getEnvRequired("FLIGHTS_DB_PASSWORD"),
        waste_detection::lib::getEnvRequired("FLIGHTS_DB_NAME")
    };
}

}