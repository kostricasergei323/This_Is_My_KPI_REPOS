/*********************************************************/
/***              Модульна контрольна робота           ***/
/***             Обчислення оберненої матриці          ***/
/***                       Варіант 11                  ***/
/*** Для матрицi A, наведеної у лаб. роботi №2, знайти ***/
/*** матрицю A^-1 ={z ij} таким методом: сформувати    ***/
/*** таблицю n*2n та розв'язати одночасно n систем     ***/
/*** рівнянь методом Жордана. Вивести вихiдну та       ***/
/*** обернену матрицi у виглядi таблицi, а також       ***/
/*** добутки A^-1 * A та A * A -1. Потім за допомогою  ***/
/*** A^-1 знайти розв'язок системи Ax=B (x=A^-1 * B)   ***/
/*** та порiвняти з результатами лаб. робiт №2,3.      ***/
/***                          Виконав: Костриця С.В    ***/
/*********************************************************/

#define N 4
#include <iostream>
#include <conio.h>
#include <cmath>
#include <iomanip>
#include <assert.h>
using namespace std;

// Заповнення матриці
void init(double **A, double **A1, double **C)
{
	for (int i = 0; i < N; i++)
	{
		A[i] = new double[N];
		assert(A[i]);
		A1[i] = new double[N];
		assert(A1[i]);
	}
	for (int i = 0; i < 2 * N; i++)
	{
		C[i] = new double[N];
		assert(C[i]);
	}
	A[0][0] = 1;	A[0][1] = 5;	A[0][2] = 100;    A[0][3] = 90;
	A[1][0] = 2;   A[1][1] = 0;    A[1][2] = -7;    A[1][3] = 8;
	A[2][0] = 100;	A[2][1] = 8;	A[2][2] = 0;	 A[2][3] = 5;
	A[3][0] = 1000;	A[3][1] = 9;    A[3][2] = 9;    A[3][3] = 10;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				A1[i][j] = 1;
			}
			else
			{
				A1[i][j] = 0;
			}
		}
	}
}

// Вивід вигляду матриці
void PrintMatrix(double **A, int sizeX = N, int sizeY = N)
{
	for (int i = 0; i < sizeX; i++)
	{
		cout << "| ";
		for (int j = 0; j < sizeY; j++)
		{
			cout << fixed << setprecision(0) << setw(5) << A[i][j] << ' ';
		}
		cout << "|" << endl;
	}
	cout << endl;
}
void MatrixTogether(double **A, double **A1, double **C)
{
	int k;
	for (int i = 0; i < N; i++)
	{
		k = 0;
		for (int j = 0; j < 2 * N; j++)
		{
			if (j < N)
			{
				C[i][j] = A[i][j];
			}
			else
			{
				C[i][j] = A1[i][k++];
			}
		}
	}

}
// Метод Жордана
void Jordan(double **A, double **A1)
{
	float R;
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i != k)
			{
				R = A[i][k] / A[k][k];
				for (int j = k; j < N; j++)
				{
					A[i][j] -= A[k][j] * R;
				}
			}
		}
	}

}

int main()
{
	double **A = new double*[N]; // Матриця коефіцієнтів A
	assert(A);
	double **A1 = new double*[N]; // Обернена матриця А
	assert(A);
	double **C = new double*[N];
	assert(A);
	init(A, A1, C);
	cout << "Matrix A:" << endl;
	PrintMatrix(A);
	cout << "Matrix A1:" << endl;
	PrintMatrix(A1);
	cout << "Matrix A and A1 together:" << endl;
	MatrixTogether(A, A1, C);
	PrintMatrix(C, N, 2 * N);
	for (int i = 0; i < 2 * N; i++)
	{
		if (i < N)
		{
			delete[] A[i];
			delete[] A1[i];
		}
		delete[] C[i];
	}
	delete[] A;
	delete[] A1;
	delete[] C;
	system("pause");
	return 0;
}