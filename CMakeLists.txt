cmake_minimum_required(VERSION 3.5.1)

#project(EventQueue.v2 LANGUAGES CXX )
project(GamePhysics.v2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -pthread")

include_directories(PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers/
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/
)

set(SOURCES
    main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/ConsoleOutput.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/GameEngine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/MicroStopwatch.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/MovingObject.cpp
)

add_executable(GamePhysics.v2 ${SOURCES})
