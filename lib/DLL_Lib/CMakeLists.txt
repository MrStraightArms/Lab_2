cmake_minimum_required(VERSION 2.8.8)

project(DLL)

set(CPP_src 
	Sort_dll.cpp
	)
set(HPP_src
	Sort_dll.hpp
	)

add_library(dll_lib SHARED ${CPP_src} ${HPP_src})