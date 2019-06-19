#include "Read_Write_lib.hpp"

void Generic_File(int* rand_mass, int length_rand_mass)
{
	for(int i = 0; i < length_rand_mass; i++)
		rand_mass[i] = rand() % 9 + 0;	
}

void Read_File(std::string way_to_file, int length, int*  work_mass)
{
	std::ifstream read_file;
	read_file.open(way_to_file);

	for (int i = 0; i < length; i++)
		read_file >> work_mass[i];

	read_file.close();
}

void Write_File(std::string way_to_file, int length, int*  work_mass)
{
	std::ofstream file_to_write(way_to_file);

	for (int i = 0; i < length; i++)
		file_to_write << work_mass[i];

	file_to_write.close();
}