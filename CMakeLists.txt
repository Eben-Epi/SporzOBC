project(SporzOBC)
cmake_minimum_required(VERSION 2.8.12)
add_definitions("-fPIC")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

#file(COPY build/qt.conf DESTINATION build/bin)

include_directories(
        ${CMAKE_INCLUDE_PATH}
        include)
add_executable(sporz_obc_client
        "src/main.cpp"
        )

if (WIN32)
    file(COPY ${CMAKE_BINARY_DIR}/qt.conf DESTINATION ${CMAKE_BINARY_DIR}/bin)
    target_link_libraries(sporz_obc_client ${CONAN_LIBS} Qt5::Widgets Qt5::Core)
endif (WIN32)

if (UNIX)
    target_link_libraries(sporz_obc_client ${CONAN_LIBS} Qt5::Widgets Qt5::Core)
endif (UNIX)
