cmake_minimum_required(VERSION 3.1)
set( CMAKE_CXX_COMPILER "g++" )
# set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

project(digit_classifier)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)
set(THIRD_PARTY_LIBRARIES
    sfml-graphics
    sfml-audio 
    sfml-window 
    sfml-system
)

add_subdirectory( src )
add_subdirectory( test )