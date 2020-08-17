#pragma once
#include <list> 
#include <fstream>
#include <time.h>

using namespace std;

void add_matrix(int**& Matrix, int size, float sparse)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Matrix[i][j] = 0;
		}
	}
	int sparse_size = sparse * size * size;
	for (int k = 0; k < sparse_size; k++)
	{
		int i = rand() % size;
		int j = rand() % size;
		Matrix[i][j] = rand() % 100;
	}
}

void print_matrix(int** Matrix, int size, ostream& out)
{
	//out.clear();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			out.width(3);
			out << left << Matrix[i][j];
		}
		out << endl;
	}
}

class SparseMatrix
{
private:
	struct Node
	{
		int value;
		int row;
		int column;
		Node(int v, int r, int c) :value(v), row(r), column(c) {}
	};
	list<Node> matrix;
public:
	SparseMatrix(int** Matrix, int size)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Matrix[i][j] != 0)
				{
					Node node(Matrix[i][j], i, j);
					matrix.push_back(node);
				}
			}
		}
	}

	void add_element(int val, int ro, int co)
	{
		auto it = matrix.begin();
		while ((*it).row < ro)
		{
			it++;
		}
		while ((*it).column < co)
		{
			it++;
		}
		Node node(val, ro, co);
		matrix.insert(it, node);
	}

	bool delete_all_elements_value(int val)
	{
		bool is = false;
		for (auto it = matrix.begin(); it != matrix.end(); it++)
		{
			if ((*it).value == val)
			{
				is = true;
				matrix.erase(it);
				it = matrix.begin();
			}
		}
		return is;
	}

	bool delete_element_row_column(int ro, int co)
	{
		for (auto it = matrix.begin(); it != matrix.end(); it++)
		{
			if ((*it).column == co && (*it).row == ro)
			{
				matrix.erase(it);
				return true;
			}
		}
		return false;
	}

	int find_value(int ro, int co)
	{
		for (auto it = matrix.begin(); it != matrix.end(); it++)
		{
			if ((*it).column == co && (*it).row == ro)
			{
				return (*it).value;
			}
		}
		return 0;
	}

	pair<int,int> find_row_column(int val)
	{
		for (auto it = matrix.begin(); it != matrix.end(); it++)
		{
			if ((*it).value == val)
			{
				return pair<int,int>((*it).row, (*it).column);
			}
		}
		return pair<int, int>(-1, -1);
	}

	void print(int size, ostream & out)
	{
		//out.clear();
		auto it = matrix.begin();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (it != matrix.end() && i == (*it).row && j == (*it).column)
				{
					out.width(3);
					out << left << (*it).value;
					it++;
				}
				else
				{
					out.width(3);
					out << left << 0;
				}
			}
			out << endl;
		}
	}
};