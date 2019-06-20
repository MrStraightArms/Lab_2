#include "dll.hpp"

std::vector<int> vector_main = {0,1,2,3,4,5,6,7,8,9};
std::vector<int> vector_test_mess; 
Sort_merge_func Sort_merge;

TEST(tests, randomly_sort)
{
	std::vector<int> *REF_vector_test = &vector_test_mess;
	*REF_vector_test = {8,5,6,7,9,1,0,2,3,4};
	Sort_merge(REF_vector_test, 0, (*REF_vector_test).size() - 1);
	ASSERT_TRUE(vector_test_mess == vector_main);
}

TEST(tests, straight_sort)
{
	std::vector<int> *REF_vector_test = &vector_test_mess;
	*REF_vector_test = {0,1,2,3,4,5,6,7,8,9};
	Sort_merge(REF_vector_test, 0, (*REF_vector_test).size() - 1);
	ASSERT_TRUE(vector_test_mess == vector_main);
}

TEST(tests, back_sort)
{
	std::vector<int> *REF_vector_test = &vector_test_mess;
	*REF_vector_test = {9,8,7,6,5,4,3,2,1,0};
	Sort_merge(REF_vector_test, 0, (*REF_vector_test).size() - 1);
	ASSERT_TRUE(vector_test_mess == vector_main);
}

TEST(tests, all_zero)
{
	std::vector<int> all_zero = { 0,0,0,0,0,0,0,0,0,0 };
	std::vector<int> *REF_vector_test = &vector_test_mess;
	*REF_vector_test = { 0,0,0,0,0,0,0,0,0,0 };
	ASSERT_NO_THROW(Sort_merge(REF_vector_test, 0, (*REF_vector_test).size() - 1));
	ASSERT_TRUE(vector_test_mess == all_zero);
}

TEST(tests, any_length)
{
	std::vector<int> any_length = {1,1,1,1,2,2,2,2,3,3,4,5,5,6,8,9};
	std::vector<int> *REF_vector_test = &vector_test_mess;
	*REF_vector_test = { 1,2,5,6,1,5,4,8,9,2,1,3,2,3,2,1 };
	ASSERT_NO_THROW(Sort_merge(REF_vector_test, 0, (*REF_vector_test).size() - 1));
	ASSERT_TRUE(vector_test_mess == any_length);
}

Sort_merge_func connect_dll_sort_merge(LPSTR dll_name, LPSTR func_name)
{
	Sort_merge_func dll_func;
	HINSTANCE dll = LoadLibrary(dll_name);
	if (!dll)
	{
		throw std::string("Dll dase not found.=)\n");
	}
	dll_func = (Sort_merge_func)GetProcAddress(dll, func_name);
	if (!dll_func)
	{
		throw std::string("Function dase not found.*)\n");
	}
	return dll_func;
}

int main(int argc, char **argv)
{
	try
	{
		Sort_merge = connect_dll_sort_merge("../../lib/DLL_Lib/Sort_Merge/dll_lib", "Sort_Merge");
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
	catch (const std::string& error)
	{
		std::cout << "ERROR :" << error << std::endl;
	}
}