#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const int n = 3;
	int array[n][n];
	cout << "Заполните массив: " << "\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> array[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << "[" << i << "]" << "[" << j << "] = " << array[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nПерестановка элемента с наибольшим значением в правый нижний угол: \n\n";
	int max = array[0][0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (array[i][j] > max)
			{
				max = array[i][j];
			}
		}
	}
	cout << "Max= " << max << "\n\n";
	cout << "Перестановка строк: \n\n";
	int tempHorizontal = 0;
	int tempVertical = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (array[i][j] == max)
			{
				for (int k = i; k < i + 1; ++k)
				{
					for (int p = 0; p < n; ++p)
					{
						tempHorizontal = array[k][p];
						array[k][p] = array[n - 1][p];
						array[n-1][p] = tempHorizontal;
					}
				}
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << "[" << i << "]" << "[" << j << "] = " << array[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "Перестановка столбцов: \n\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (array[i][j] == max)
			{
				for (int p = j; p < j + 1; ++p)
				{
					for (int k = 0; k < n; ++k)
					{
						tempVertical = array[k][p];
						array[k][p] = array[k][n-1];
						array[k][n-1] = tempVertical;
					}
				}
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << "[" << i << "]" << "[" << j << "] = " << array[i][j] << " ";
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}
