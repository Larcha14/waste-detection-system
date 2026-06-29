# add_library(shared INTERFACE)

# target_include_directories(shared INTERFACE
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
# )

add_library(shared STATIC
    src/EnvReader.cpp
    # src/Logger.cpp
)


target_include_directories(shared PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# find_package(spdlog CONFIG REQUIRED)
# find_package(yaml-cpp CONFIG REQUIRED)
# find_package(nlohmann_json CONFIG REQUIRED)

# target_link_libraries(shared PUBLIC
#     spdlog::spdlog
#     yaml-cpp::yaml-cpp
#     nlohmann_json::nlohmann_json
# )