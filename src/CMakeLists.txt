# arondinaeng/src

add_library(arondinaeng 

    math_util.cpp
    project_euler_problem_set_0.cpp

)

target_include_directories(arondinaeng PUBLIC ${CMAKE_SOURCE_DIR}/include)