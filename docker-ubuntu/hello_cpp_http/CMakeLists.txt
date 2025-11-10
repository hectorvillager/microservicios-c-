cmake_minimum_required(VERSION 3.9)
project(hello_cpp_http)
# Set our project to use C++ 17
set(CMAKE_CXX_STANDARD 17)
# Set our source files as just the main.cpp
set(SOURCE_FILES main.cpp)

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)
# Create our executable file from our source files
add_executable(httpserver_run ${SOURCE_FILES})
target_link_libraries(httpserver_run PkgConfig::Pistache)