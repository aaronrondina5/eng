# arondinaprojecteuler/src

add_library(arondinaprojecteuler 

    math_util.cpp
    projecteuler_set_1_20.cpp

)

target_include_directories(arondinaprojecteuler PUBLIC ${CMAKE_SOURCE_DIR}/include)