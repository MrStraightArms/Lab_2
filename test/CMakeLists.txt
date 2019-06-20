cmake_minimum_required(VERSION 2.8.8)

project(test_main)


set(SOURSE 
	src/t_main.cpp
)

add_executable(test_exe ${SOURSE})

target_link_libraries(test_exe PUBLIC gtest)
target_link_libraries(test_exe PUBLIC stat_lib)
#target_link_libraries(test_exe PUBLIC dll_lib)