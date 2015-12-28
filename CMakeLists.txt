cmake_minimum_required(VERSION 2.8)
ADD_DEFINITIONS(
    -std=c++11 
)

project( readRGBDdata )
find_package( OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable( readRGBDdata  readRGBDdata.cpp )
target_link_libraries( readRGBDdata ${OpenCV_LIBS} )
