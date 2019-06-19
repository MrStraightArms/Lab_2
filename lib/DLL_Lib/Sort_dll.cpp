#include "Sort_dll.hpp"
void Sort_Merge(std::vector<int> *In_mass, int left_board, int right_board) // Функция сортировки слиянием 
{
	if (left_board == right_board) return; 

	int middle = (left_board + right_board) / 2; 

	Sort_Merge(In_mass, left_board, middle);
	Sort_Merge(In_mass, middle + 1, right_board);

	int i = left_board;  
	int j = middle + 1; 
	int* tmp = new int [right_board]; 

	for (int step = 0; step < right_board - left_board + 1; step++) 
	{
		if ((j > right_board) || ((i <= middle) && ((*In_mass)[i] < (*In_mass)[j])))
		{
			tmp[step] = (*In_mass)[i];
			i++;
		}
		else
		{
			tmp[step] = (*In_mass)[j];
			j++;
		}
	}
		
	for (int step = 0; step < right_board - left_board + 1; step++)
		(*In_mass)[left_board + step] = tmp[step];
	
}
