# 3.24.1 is bundled in Visual Studio 2022 v17.4
# 3.24.1 is also bundled in CLion as of 2023
cmake_minimum_required(VERSION 3.24.1)

set(PROJECT_NAME "rudder-sdk-cpp")

file(STRINGS VERSION CURRENT_VERSION)

project(${PROJECT_NAME} VERSION ${CURRENT_VERSION} LANGUAGES CXX)

if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
    set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
else()
    # Check required c++ standard of parent project
    if(CMAKE_CXX_STANDARD)
        set(PARENT_CXX_STANDARD ${CMAKE_CXX_STANDARD})
        message(STATUS "CXX standard of parent project: ${PARENT_CXX_STANDARD}")
    endif()
endif()


if (PARENT_CXX_STANDARD)
    # Don't set CMAKE_CXX_STANDARD if it is already set by parent project
    if (PARENT_CXX_STANDARD LESS 17)
        message(FATAL_ERROR "cpr ${cpr_VERSION} does not support ${PARENT_CXX_STANDARD}. Please use cpr <= 1.9.x")
    endif()
else()
    # Set standard version if not already set by potential parent project
    set(CMAKE_CXX_STANDARD 17)
endif()

# Color our warnings and errors
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options (-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options (-fcolor-diagnostics)
endif ()

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


add_subdirectory(rudder)
add_subdirectory(include)

# target_link_libraries(
#     "${PROJECT_NAME}"
#     PRIVATE
#     nlohmann_json::nlohmann_json
#     )

# target_link_libraries("${PROJECT_NAME}"
#     PRIVATE
#     cpr::cpr
#     )


