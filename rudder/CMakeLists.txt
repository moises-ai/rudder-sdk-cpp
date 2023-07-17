cmake_minimum_required(VERSION 3.24.1)

add_library(rudder-sdk-cpp
    timestamp.cpp
    message.cpp
    identify.cpp
    track.cpp
    page.cpp
    screen.cpp
    )

add_library(rudder ALIAS rudder-sdk-cpp)

target_link_libraries(
    rudder-sdk-cpp
    PUBLIC
    nlohmann_json::nlohmann_json
    )

# Set version for shared libraries.
set_target_properties(rudder-sdk-cpp
        PROPERTIES
        VERSION ${${PROJECT_NAME}_VERSION}
        SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR})

install(TARGETS rudder-sdk-cpp
                RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
                ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
