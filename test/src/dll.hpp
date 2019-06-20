#pragma once 
#include <windows.h>
#include <gtest/gtest.h>
#include "../../Lib/LIB_lib/Read_Write_lib.hpp"
#include <iostream>

typedef void(*Sort_merge_func) (std::vector<int> *in_mass, int left_board, int right_board);

