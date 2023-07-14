# 3.24.1 is bundled in Visual Studio 2022 v17.4
# 3.24.1 is also bundled in CLion as of 2023
cmake_minimum_required(VERSION 3.24.1)

set(PROJECT_NAME "rudder-sdk-cpp")

file(STRINGS VERSION CURRENT_VERSION)

project(${PROJECT_NAME} VERSION ${CURRENT_VERSION})


# Fetch libcpr
include(FetchContent)

FetchContent_Declare(cpr 
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba
    ) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)


FetchContent_Declare(json 
    URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
    )
FetchContent_MakeAvailable(json)

# Reads in VERSION file and sticks in it CURRENT_VERSION variable
# Be sure the file has no newlines

set(HeaderFiles
    rudder/message/MessageType.h
    rudder/message/Message.h
    rudder/message/Identify.h
    rudder/message/Timestamp.h
    )

set(SourceFiles
    rudder/message/Identify.cpp
    rudder/message/Timestamp.cpp
    rudder/message/Identify.h
    )

add_library(
    "${PROJECT_NAME}"
    SHARED
    ${SourceFiles}
    )

target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_17)

target_link_libraries(
    "${PROJECT_NAME}"
    PRIVATE
    nlohmann_json::nlohmann_json
    )

# target_link_libraries("${PROJECT_NAME}"
#     PRIVATE
#     cpr::cpr
#     )
# Color our warnings and errors
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options (-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options (-fcolor-diagnostics)
endif ()


