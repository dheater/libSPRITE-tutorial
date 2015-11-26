cmake_minimum_required(VERSION 2.8)

# I like to have the warning level set high.
add_definitions("-Wall -Wextra -Wparentheses -Wuninitialized -Wcomment -Wformat -Weffc++")

# Set target specific rules.
#set_property(SOURCE task/Hello.cpp APPEND_STRING PROPERTY COMPILE_FLAGS " -DNO_PRINT_INFO")

# Find libSPRITE and set flags.
find_package(libSPRITE REQUIRED)
include_directories(${libSPRITE_INCLUDE_DIRS})
link_directories(${libSPRITE_LINK_DIRS})
set(LIBS ${LIBS} ${libSPRITE_LIBRARIES})

# Find Lua and set paths to Lua.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIR})
set(LIBS ${LIBS} ${LUA_LIBRARIES})

# Add the source tree directory to the search path for include files.
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add the executable and it's source.
add_executable(sprite_main sprite_main.cpp
               task/Hello.cpp)

# Specify libraries to link.
target_link_libraries(sprite_main ${LIBS} pthread rt)

# Copy Lua scripts to the build directory.
file(COPY hello.lua DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
