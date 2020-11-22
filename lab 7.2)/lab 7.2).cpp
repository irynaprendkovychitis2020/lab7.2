// lab 7.2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Inverse(int** a, const int rowCount, const int colCount);
int SearchMinOdd(int** a, const int rowCount, const int colCount);
int SearchMaxOdd(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));
	int rowCount;
	int colCount;
	int Low = 7;
	int High = 65;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	Inverse(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;

}
void Inverse(int** a, const int rowCount, const int colCount)
{
	int min, max, imin, imax;
	for (int j = 1; j < colCount; j++)
	{
		imax = SearchMaxOdd(a, rowCount, j);
		max = a[imax][j];
		imin = SearchMinOdd(a, rowCount, j);
		min = a[imin][j];
		a[imax][j] = min;
		a[imin][j] = max;
	}
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int SearchMinOdd(int** a, const int rowCount, const int colCount)
{
	int min = a[0][colCount];
	int imin = 0;
	for (int i = 0; i < rowCount; i++)
	{
		if (a[i][colCount] < min)
		{
			min = a[i][colCount];
			imin = i;
		}
	}
	return imin;

}

int SearchMaxOdd(int** a, const int rowCount, const int colCount)
{
	int max = a[0][colCount];
	int imax = 0;
	for (int i = 0; i < rowCount; i++)
	{
		if (a[i][colCount] > max)
		{
			max = a[i][colCount];
			imax = i;
		}
	}
	return imax;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
