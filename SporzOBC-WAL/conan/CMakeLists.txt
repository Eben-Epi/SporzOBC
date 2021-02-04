cmake_minimum_required(VERSION 3.5)

project(SporzOBC-WAL LANGUAGES CXX)
get_filename_component(DIR_ONE_ABOVE ../ ABSOLUTE)
set(PROJECT_SOURCE_DIR ${DIR_ONE_ABOVE})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/resources)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup()

find_package(Qt5 COMPONENTS Core Widgets Gui Xml REQUIRED)

include_directories(client/include)
include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${CONAN_INCLUDE_DIRS})

file(COPY ${CMAKE_BINARY_DIR}/qt.conf DESTINATION ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES_CPP ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SOURCES_HPP ${PROJECT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE SOURCES_H ${PROJECT_SOURCE_DIR}/include/*.h)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_H})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${CONAN_LIBS} Qt5::Core Qt5::Gui)
