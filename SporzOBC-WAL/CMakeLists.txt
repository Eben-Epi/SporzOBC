cmake_minimum_required(VERSION 3.5)

project(SporzOBC-WAL LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS code/resources)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
file(GLOB_RECURSE SOURCES_CPP ${PROJECT_SOURCE_DIR}/code/src/*.cpp)
file(GLOB_RECURSE SOURCES_HPP ${PROJECT_SOURCE_DIR}/code/include/*.hpp)
file(GLOB_RECURSE SOURCES_H ${PROJECT_SOURCE_DIR}/code/include/*.h)

include_directories(${PROJECT_SOURCE_DIR}/code/include)

if(ANDROID)
  add_library(SporzOBC-WAL SHARED ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_H}
        )
else()
  add_executable(SporzOBC-WAL ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_H}
        )
endif()

target_link_libraries(SporzOBC-WAL PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
