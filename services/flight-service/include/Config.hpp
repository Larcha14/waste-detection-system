#pragma once

#include <string>

namespace waste_detection::flight_service::db_config {

struct Config {
    std::string host;
    int port;
    std::string user;
    std::string password;
    std::string dbName;
};

Config loadJobsDbConfig();

}