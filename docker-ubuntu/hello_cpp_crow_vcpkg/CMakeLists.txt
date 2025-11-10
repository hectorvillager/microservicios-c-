cmake_minimum_required(VERSION 3.8)

project(hello_cpp_crow_vcpkg)

include(/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(Crow CONFIG REQUIRED)

add_executable(exe_name "Main.cpp")

target_link_libraries(exe_name PUBLIC Crow::Crow)
