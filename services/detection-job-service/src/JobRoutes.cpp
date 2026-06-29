#include "JobRoutes.hpp"

#include "DbConfig.hpp"
#include "JobRepository.hpp"

#include <drogon/drogon.h>
#include <json/json.h>

namespace waste_detection::api::routes {

void registerJobRoutes() {
    const auto dbConfig = config::loadJobsDbConfig();

    drogon::app().registerHandler(
        "/jobs",
        [dbConfig](const drogon::HttpRequestPtr& req,
                   std::function<void(const drogon::HttpResponsePtr&)>&& callback)
        {
            auto body = req->getJsonObject();

            if (!body || !body->isMember("input_dir")) {
                Json::Value error;
                error["error"] = "input_dir is required";

                auto response = drogon::HttpResponse::newHttpJsonResponse(error);
                response->setStatusCode(drogon::k400BadRequest);
                callback(response);
                return;
            }

            jobs::JobRepository repository(dbConfig);

            const int jobId = repository.createJob((*body)["input_dir"].asString());

            Json::Value json;
            json["job_id"] = jobId;
            json["status"] = "queued";

            callback(drogon::HttpResponse::newHttpJsonResponse(json));
        },
        {drogon::Post}
    );

    drogon::app().registerHandler(
        "/jobs/{1}",
        [dbConfig](const drogon::HttpRequestPtr& req,
                   std::function<void(const drogon::HttpResponsePtr&)>&& callback,
                   int jobId)
        {
            jobs::JobRepository repository(dbConfig);

            auto job = repository.findJobById(jobId);

            if (!job.has_value()) {
                Json::Value error;
                error["error"] = "job not found";

                auto response = drogon::HttpResponse::newHttpJsonResponse(error);
                response->setStatusCode(drogon::k404NotFound);
                callback(response);
                return;
            }

            Json::Value json;
            json["job_id"] = job->id;
            json["input_dir"] = job->inputDir;
            json["status"] = job->status;
            json["total_images"] = job->totalImages;
            json["processed_images"] = job->processedImages;
            json["failed_images"] = job->failedImages;

            callback(drogon::HttpResponse::newHttpJsonResponse(json));
        },
        {drogon::Get}
    );
}

}