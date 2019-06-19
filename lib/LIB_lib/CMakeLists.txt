cmake_minimum_required(VERSION 2.8.8)

project(STAT)


set(CPP_src 
	Read_Write_lib.cpp
	)
set(HPP_src
	Read_Write_lib.hpp
	)

add_library(stat_lib STATIC ${CPP_src} ${HPP_src})