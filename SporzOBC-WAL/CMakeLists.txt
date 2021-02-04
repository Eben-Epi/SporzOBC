cmake_minimum_required(VERSION 3.5)

project(SporzOBC-WAL LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
file(GLOB_RECURSE SOURCES_CPP ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SOURCES_HPP ${PROJECT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE SOURCES_H ${PROJECT_SOURCE_DIR}/include/*.h)

if(ANDROID)
  add_library(SporzOBC-WAL SHARED ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_H}
        )
else()
  add_executable(SporzOBC-WAL ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_H}
        )
endif()

target_link_libraries(SporzOBC-WAL PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
