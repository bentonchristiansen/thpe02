cmake_minimum_required(VERSION 3.10.0)

project(thpe02)

find_package( Catch2 3 REQUIRED )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
if( NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(stringtest)

target_sources(stringtest PRIVATE src/stringtracker.h)
target_sources(stringtest PRIVATE src/stringtracker1.cpp)
target_sources(stringtest PRIVATE src/stringtracker2.cpp)
target_sources(stringtest PRIVATE src/stringtrackertests1.cpp)
target_sources(stringtest PRIVATE src/stringtrackertests2.cpp)
target_sources(stringtest PRIVATE src/insttests.cpp)

target_compile_options(stringtest PRIVATE -g -Wall -Wextra -Wshadow 
-Wpedantic -std=gnu++20 -Werror)
target_link_libraries(stringtest PRIVATE Catch2::Catch2WithMain)

add_executable(functiontest)

target_sources(functiontest PRIVATE src/stringtracker.h)
target_sources(functiontest PRIVATE src/stringtracker1.cpp)
target_sources(functiontest PRIVATE src/stringtracker2.cpp)
target_sources(functiontest PRIVATE src/thpe02.h)
target_sources(functiontest PRIVATE src/thpe02fn.cpp)
target_sources(functiontest PRIVATE src/thpe02fntests.cpp)

target_compile_options(functiontest PRIVATE -g -Wall -Wextra -Wshadow 
-Wpedantic -std=gnu++20 -Werror)
target_link_libraries(functiontest PRIVATE Catch2::Catch2WithMain)

add_executable(thpe02)

target_sources(thpe02 PRIVATE src/stringtracker.h)
target_sources(thpe02 PRIVATE src/stringtracker1.cpp)
target_sources(thpe02 PRIVATE src/stringtracker2.cpp)
target_sources(thpe02 PRIVATE src/thpe02.h)
target_sources(thpe02 PRIVATE src/thpe02.cpp)
target_sources(thpe02 PRIVATE src/thpe02fn.cpp)

target_compile_options(thpe02 PRIVATE -g -Wall -Wextra -Wshadow 
-Wpedantic -std=gnu++20) # -Werror)
target_link_libraries(thpe02 PRIVATE)

include( Catch )
catch_discover_tests( stringtest )
catch_discover_tests( functiontest )
enable_testing()

set(TarFile "${PROJECT_NAME}.tgz")
set(TarSourceFiles
    src/*
    .vscode/*
    CMakeLists.txt
)

add_custom_target(CreateTGZ
    COMMAND tar -zcvf ${TarFile} ${TarSourceFiles}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Create a tgz for submission"
)