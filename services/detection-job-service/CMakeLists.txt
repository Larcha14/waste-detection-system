find_package(Drogon CONFIG REQUIRED)
find_package(libpqxx CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

add_executable(detection-job-service
    src/main.cpp
    src/HealthRoutes.cpp
    src/JobRoutes.cpp
    src/Config.cpp
)

target_include_directories(detection-job-service PRIVATE
    include
)

target_link_libraries(detection-job-service 
    PRIVATE
        shared
        Drogon::Drogon
        libpqxx::pqxx
        nlohmann_json::nlohmann_json
        spdlog::spdlog
        yaml-cpp::yaml-cpp
)