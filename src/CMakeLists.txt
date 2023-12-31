# arondinaeng/src

add_library(arondinaeng 

    leetcode_set_0.cpp
    math_util.cpp
    projecteuler_set_0.cpp

)

target_include_directories(arondinaeng PUBLIC ${CMAKE_SOURCE_DIR}/include)