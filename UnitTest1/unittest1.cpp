#include "stdafx.h"
#include "CppUnitTest.h"
#include "..//ALG11SparseMatrix/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
SparseMatrix add(int size, float sparse)
{
	srand(time(0));
	int **matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	add_matrix(matrix, size, sparse);
	SparseMatrix test(matrix, size);
	return test;
}
namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			SparseMatrix test1 = add(20, 0.1);
			test1.add_element(15, 5, 5);
			Assert::AreEqual(test1.find_value(5, 5), 15);
			test1.delete_element_row_column(0, 0);
			Assert::AreEqual(test1.find_value(0,0), 0);
		}
		TEST_METHOD(Test2)
		{
			SparseMatrix test2 = add(40, 0.05);
			test2.delete_all_elements_value(17);
			pair<int, int> res(-1, -1), res_pr = test2.find_row_column(17);
			Assert::IsTrue(res_pr == res);
		}
		TEST_METHOD(Test3)
		{
			SparseMatrix test3 = add(50, 0.2);
			test3.add_element(23, 15, 15);
			test3.delete_element_row_column(15, 15);
			Assert::AreEqual(test3.find_value(15, 15), 0);
		}
		TEST_METHOD(Test4)
		{
			SparseMatrix test4 = add(100, 0.07);
			int i = rand() % 100;
			int j = rand() % 100;
			test4.add_element(47, i, j);
			Assert::IsTrue(test4.find_value(i, j));
		}
		TEST_METHOD(Test5)
		{
			SparseMatrix test5 = add(70, 0.15);
			int i = rand() % 100;
			int j = rand() % 100;
			int value = rand() % 1000;
			test5.add_element(value, i, j);
			Assert::IsTrue(test5.delete_all_elements_value(value));
		}
	};
}