cmake_minimum_required(VERSION 3.24.1)

target_include_directories(rudder-sdk-cpp PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/rudder_generated_includes/>)

target_sources(cpr PRIVATE
    rudder/timestamp.h
    rudder/messagetype.h
    rudder/message.h
    rudder/identify.h
    rudder/track.h
    )

install(DIRECTORY rudder-sdk-cpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY ${PROJECT_BINARY_DIR}/rudder_generated_includes/rudder DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
