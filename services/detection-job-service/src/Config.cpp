#include "Config.hpp"
#include "EnvReader.hpp"
#include <cstdlib>

namespace  waste_detection::job_service::db_config {

Config loadJobsDbConfig() {
    return Config{
        waste_detection::lib::getEnvRequired("JOBS_DB_HOST"),
        waste_detection::lib::getEnvIntRequired("JOBS_DB_PORT"),
        waste_detection::lib::getEnvRequired("JOBS_DB_USER"),
        waste_detection::lib::getEnvRequired("JOBS_DB_PASSWORD"),
        waste_detection::lib::getEnvRequired("JOBS_DB_NAME")
    };
}

}