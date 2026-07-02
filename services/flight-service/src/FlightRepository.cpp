// #include "JobRepository.hpp"

// #include <drogon/drogon.h>
// #include <drogon/orm/Mapper.h>
// #include <drogon/orm/Criteria.h>
// #include <drogon/orm/Exception.h>


// #include "models/JobImages.h"
// #include "models/Jobs.h"

// #include <pqxx/pqxx>

// // using namespace drogon_model;


// namespace waste_detection::flight_service::jobs {

// JobRepository::JobRepository(config::DbConfig dbConfig)
//     : dbConfig_(std::move(dbConfig)) {
// }

// std::string JobRepository::connectionString() const {
//     return
//         "host=" + dbConfig_.host +
//         " port=" + std::to_string(dbConfig_.port) +
//         " user=" + dbConfig_.user +
//         " password=" + dbConfig_.password +
//         " dbname=" + dbConfig_.dbName;
// }

// int JobRepository::createJob(const std::string& inputDir) {
//     pqxx::connection connection(connectionString());
//     pqxx::work tx(connection);

//     pqxx::result result = tx.exec_params(
//         "INSERT INTO jobs (input_dir, jobs_status) "
//         "VALUES ($1, 'queued') "
//         "RETURNING id",
//         inputDir
//     );

//     tx.commit();

//     return result[0][0].as<int>();
// }

// std::optional<Job> JobRepository::findJobById(int jobId) {
//     pqxx::connection connection(connectionString());
//     pqxx::work tx(connection);

//     pqxx::result result = tx.exec_params(
//         "SELECT id, input_dir, jobs_status, total_images, processed_images, failed_images "
//         "FROM jobs "
//         "WHERE id = $1",
//         jobId
//     );

//     tx.commit();

//     if (result.empty()) {
//         return std::nullopt;
//     }

//     const auto row = result[0];

//     return Job{
//         row["id"].as<int>(),
//         row["input_dir"].as<std::string>(),
//         row["jobs_status"].as<std::string>(),
//         row["total_images"].as<int>(),
//         row["processed_images"].as<int>(),
//         row["failed_images"].as<int>()
//     };
// }

// }