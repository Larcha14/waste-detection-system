cmake_minimum_required(VERSION 3.24)

project(waste_detection_system LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/shared)
add_subdirectory(services/detection-job-service)
# add_subdirectory(services/detection-worker)