#include "dll.hpp"

std::vector<int> vector_main = {0,1,2,3,4,5,6,7,8,9};
std::vector<int> vector_test_mess; 


TEST(tests, randomly_sort)
{
	std::vector<int> *REF_vector_test = &vector_test_mess;
	*REF_vector_test = {8,5,6,7,9,1,0,2,3,4};
	SortMarge_dll(REF_vector_test, 0, (*REF_vector_test).size() - 1);
	ASSERT_TRUE(vector_test_mess == vector_main);
}

TEST(tests, straight_sort)
{
	std::vector<int> *REF_vector_test = &vector_test_mess;
	*REF_vector_test = {0,1,2,3,4,5,6,7,8,9};
	SortMarge_dll(REF_vector_test, 0, (*REF_vector_test).size() - 1);
	ASSERT_TRUE(vector_test_mess == vector_main);
}

TEST(tests, back_sort)
{
	std::vector<int> *REF_vector_test = &vector_test_mess;
	*REF_vector_test = {9,8,7,6,5,4,3,2,1,0};
	SortMarge_dll(REF_vector_test, 0, (*REF_vector_test).size() - 1);
	ASSERT_TRUE(vector_test_mess == vector_main);
}


int main(int argc, char **argv)
{
	HINSTANCE Dll_Sort = LoadLibrary("../../Buld/lib/DLL_Lib/Debug/dll_Lib.dll");
	if (!Dll_Sort)
	{
		printf("Dll dase not found.=)\n");
	}

	SortMarge_dll = (void(*) (std::vector<int> *in_mass, int left_board, int right_board)) GetProcAddress(Dll_Sort, "Sort_Merge");

	if (!SortMarge_dll) // проверяем
	{
		printf("Function dase not found.*)\n");
	}
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}