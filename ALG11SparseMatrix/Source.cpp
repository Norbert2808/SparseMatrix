#include "Header.h"

int main()
{
	//srand(time(NULL));
	ofstream out("Text.txt");
	const int size = 20;
	int **matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}
	add_matrix(matrix, size, 0.05);
	out << "-----------------------Start matrix------------------------\n\n";
	print_matrix(matrix, size, out);

	SparseMatrix one(matrix, size);
	one.add_element(7, 0, 0);
	out << "\n--------------After adding element[0;0] - 7----------------\n\n";
	one.print(size, out);

	if (one.delete_all_elements_value(47))
	{
		out << "\n--------------After deleting all elements 47---------------\n\n";
		one.print(size, out);
	}

	if (one.delete_element_row_column(2, 13))
	{
		out << "\n--------------After deleting element[2;13]-----------------\n\n";
		one.print(size, out);
	}

	int value = one.find_value(0, 9);
	out << "\n--------------Element[0;9] = " << value << "----------------------------\n\n";

	pair<int, int> find_12 = one.find_row_column(12);
	if (find_12.first != -1)
	{
		out << "\n--------------First element 12 - [" << find_12.first << ";" << find_12.second << "]--------------------\n\n";
	}
	system("pause");
	return 0;
}