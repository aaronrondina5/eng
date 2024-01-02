# arondinaeng/src

add_library(arondinaeng 

    math_util.cpp
    projecteuler_set_1_20.cpp

)

target_include_directories(arondinaeng PUBLIC ${CMAKE_SOURCE_DIR}/include)