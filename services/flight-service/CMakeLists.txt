find_package(Drogon CONFIG REQUIRED)
find_package(libpqxx CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

file(GLOB ORM_MODEL_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/models/*.cc
)



add_executable(flight-service
    src/main.cpp
    src/HealthRoutes.cpp
    src/FlightRoutes.cpp
    src/Config.cpp
    ${ORM_MODEL_SOURCES}
)


target_include_directories(flight-service
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(flight-service 
    PRIVATE
        shared
        Drogon::Drogon
        libpqxx::pqxx
        nlohmann_json::nlohmann_json
        spdlog::spdlog
        yaml-cpp::yaml-cpp
)