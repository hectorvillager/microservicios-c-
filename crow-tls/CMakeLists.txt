cmake_minimum_required(VERSION 3.16)
project(CrowHTTPSExample)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  crow
  GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
  GIT_TAG v1.1.0
)
FetchContent_MakeAvailable(crow)

add_executable(server server.cpp)
target_link_libraries(server PRIVATE Crow::Crow ssl crypto)
