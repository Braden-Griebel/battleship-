# Setup
cmake_minimum_required(VERSION 3.24...3.31)
project(Battleship VERSION 0.1 DESCRIPTION "Battleship Game" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use FetchContent to get dependencies
include(FetchContent)
# Declare FetchContent for cli11
FetchContent_Declare(
        cli11
        QUIET
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.3.2
)
# If cli11 hasn't been populated, populate it
FetchContent_MakeAvailable(cli11)
# Declare FetchContent for asio
FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG asio-1-32-0
)
# Make asio available
FetchContent_MakeAvailable(asio)


# Add asio as an interface library
add_library(asio INTERFACE)
# Include the asio include directory
target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
# Include Threads for Threading support (may not be needed)
find_package(Threads)
target_link_libraries(asio INTERFACE Threads::Threads)

# Add the src directory
add_subdirectory(src)

# For editor support
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)

# If building this project, and BUILD_TESTING is ON, add the tests subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
