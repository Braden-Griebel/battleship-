# Add the main executable target
add_executable(battleship battleship.cpp)

# Set the battleship target to be output to the main build directory
# rather than the src subdirectory
set_target_properties(battleship PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# Add the battleship game library (bsgl) subdirectory
add_subdirectory(bsgl)

# Link the main executable with the cli11 library
target_link_libraries(battleship PRIVATE CLI11::CLI11)
target_link_libraries(battleship PRIVATE bsgl)