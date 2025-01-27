# Add all the files to the bsgl library
add_library(bsgl board.h board.cpp server.h server.cpp ships.h ships.cpp)

# Include the files
target_include_directories(bsgl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})