cmake_minimum_required(VERSION 3.5)

project(SporzOBC-WAL LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS code/resources)
set(ANDROID_PACKAGE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/android)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES_CPP ${PROJECT_SOURCE_DIR}/code/src/*.cpp)
file(GLOB_RECURSE SOURCES_HPP ${PROJECT_SOURCE_DIR}/code/include/*.hpp)
file(GLOB_RECURSE SOURCES_H ${PROJECT_SOURCE_DIR}/code/include/*.h)

include_directories(${PROJECT_SOURCE_DIR}/code/include)

if(ANDROID)
    find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets AndroidExtras REQUIRED)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets AndroidExtras REQUIRED)
    qt5_add_resources(UI_RESOURCES ${PROJECT_SOURCE_DIR}/code/resources/assets.qrc)
    add_library(SporzOBC-WAL SHARED ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_H} ${UI_RESOURCES} android/AndroidManifest.xml)
    target_link_libraries(SporzOBC-WAL PUBLIC Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::AndroidExtras)
else()
    find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
    qt5_add_resources(UI_RESOURCES ${PROJECT_SOURCE_DIR}/code/resources/assets.qrc)
    add_executable(SporzOBC-WAL ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_H} ${UI_RESOURCES})
    target_link_libraries(SporzOBC-WAL PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)

endif()
