#pragma once

#include "Config.hpp"

#include <optional>
#include <string>

namespace waste_detection::job_service::jobs {

struct Job {
    int id;
    std::string inputDir;
    std::string status;
    int totalImages;
    int processedImages;
    int failedImages;
};

class JobRepository {
public:
    explicit JobRepository(job_service::db_config::Config db);

    int createJob(const std::string& inputDir);
    std::optional<Job> findJobById(int jobId);

private:
    job_service::db_config::Config db_;

    std::string connectionString() const;
};

}