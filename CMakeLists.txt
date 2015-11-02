cmake_minimum_required(VERSION 2.8)

# I like to have the warning level set high.
add_definitions("-Wall -Wextra -Wparentheses -Wuninitialized -Wcomment -Wformat -Weffc++")

# Set target specific rules.
#set_property(SOURCE task/Hello.cpp APPEND_STRING PROPERTY COMPILE_FLAGS " -DNO_PRINT_INFO")

# Add the source tree directory to the search path for include files.
# Add the path to the libSPRITE header files.
include_directories(${CMAKE_CURRENT_SOURCE_DIR} "/usr/local/include/SPRITE")

# Set libSPRITE in the libraries path.
link_directories(/usr/local/lib/SPRITE)

# Add the executable and it's source.
add_executable(sprite_main sprite_main.cpp
               task/Hello.cpp)

# Specify libraries to link.
target_link_libraries(sprite_main SPRITE_SRTX rt pthread)
