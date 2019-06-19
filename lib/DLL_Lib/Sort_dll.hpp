#include <iostream>
#include <vector>
extern "C"
{
	__declspec(dllexport) void Sort_Merge(std::vector<int> *In_mass, int left_board, int right_board);
}


