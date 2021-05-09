cmake_minimum_required(VERSION 3.5)

project(SporzOBC-WAL)
get_filename_component(DIR_ONE_ABOVE ../ ABSOLUTE)
set(PROJECT_SOURCE_DIR ${DIR_ONE_ABOVE}/code)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/resources)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

set(UI_RESOURCES ${PROJECT_SOURCE_DIR}/resources/assets.qrc)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup()

find_package(Qt5 COMPONENTS Core Widgets Gui Xml REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${CONAN_INCLUDE_DIRS})

file(COPY ${CMAKE_BINARY_DIR}/qt.conf DESTINATION ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES_CPP ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SOURCES_HPP ${PROJECT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE SOURCES_H ${PROJECT_SOURCE_DIR}/include/*.h)

message(${SOURCES_CPP})

add_executable(SporzOBC-WAL ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_H} ${UI_RESOURCES})
target_link_libraries(SporzOBC-WAL PUBLIC ${CONAN_LIBS} Qt5::Core Qt5::Gui)
