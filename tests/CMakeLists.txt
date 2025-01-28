# Get Catch2
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0
)

# Make catch2 available
FetchContent_MakeAvailable(Catch2)

# UNCOMMENT BELOW WHEN ADDING EXECUTABLES
add_executable(tests test_ships.cpp)

# Link the tests with the main library
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain bsgl)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}.extras)
# Include CTest to run the tests
include(CTest)
# Include Catch to discover the tests
include(Catch)
# Discover the tests
catch_discover_tests(tests)