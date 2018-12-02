#define N 4
#include <iostream>
#include <iomanip>

using namespace std;

double A[N][N];
double A1[N][N];
double B[N];

void init(int ind = 1)
{
	A[0][0] = 1;   A[0][1] = 5; A[0][2] = 100; A[0][3] = 90;
	A[1][0] = 2;	 A[1][1] = 0; A[1][2] = -7;  A[1][3] = 8;
	A[2][0] = 100; A[2][1] = 8; A[2][2] = 0;   A[2][3] = 5;
	A[3][0] = 1000; A[3][1] = 9; A[3][2] = 9;   A[3][3] = 10;

	B[0] = 23; B[1] = 49; B[2] = -3; B[3] = 5;

	if (ind)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				A1[i][j] = 0;
			}
			A1[i][i] = 1;
		}
	}
}

void printMatrix(int ind = 1)
{
	if (ind)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << setw(6) << fixed << setprecision(1) << A[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << setw(6) << fixed << setprecision(1) << A1[i][j] << ' ';
			}
			cout << endl;
		}
	}
	cout << endl;
}
void swap(double a, double b)
{
	double temp = a;
	a = b;
	b = temp;
}
void SwapRows(int row1, int row2)
{

	for (int i = 0; i < N; i++)
	{
		swap(A[row1][i], A[row2][i]);
		swap(A1[row1][i], A1[row2][i]);
	}
}

void SwapColumns(int column1, int column2)
{
	for (int i = 0; i < N; i++)
	{
		swap(A[i][column1], A[i][column2]);
		swap(A1[i][column1], A1[i][column2]);
	}
}
void SubRow(int row, int column, double k,int lim=0, int ind=1)
{
	if (ind)
	{
		for (int i = lim; i < N; i++)
		{
			A[column][i] -= A[row][i] * k;
		}
	}
	else
	{
		for (int i = lim; i < N; i++)
		{
			A1[column][i] -= A[row][i] * k;
		}
	}

}
void MainElement(int lim, int &row, int &column)
{
	row = column = lim;
	for (int i = lim; i < N; i++)
	{
		for (int j = lim; j < N; j++)
		{
			if (abs(A[row][column]) < abs(A[i][j]))
			{
				row = i;
				column = j;
			}
		}
	}
}
void reverseMatrix()
{
	int row;
	int column;

	for (int i = 0; i < N; i++)
	{
		MainElement(i, row, column);

		if (row != i)
		{
			SwapRows(i, row);
		}
		if (column != i)
		{
			SwapRows(i, column);
		}

		for (int j = i + 1; j < N; j++)
		{
			double k = A[j][i] / A[i][i];

			SubRow(i, j, k, i);
			SubRow(i, j, k, 0, 0);
		}
	}

	for (int i = 0; i < N; i++) 
	{
		double d = A[i][i];
		for (int j = 0; j < N; j++) 
		{
			A[i][j] /= d;
			A1[i][j] /= d;
		}
	}

	
	for (int i = N - 1; i >= 0; i--) 
	{
		for (int j = i - 1; j >= 0; j--) 
		{
			double k = A[j][i];

			SubRow(i, j, k);
			SubRow(i, j, k, 0, 0);
		}
	}
}
void MultiPlicationMatrix()
{
	double product[4][4];
	for (int row = 0; row < N; row++) 
	{
		for (int col = 0; col < N; col++) 
		{
			product[row][col] = 0;
			for (int inner = 0; inner < N; inner++) 
			{
				product[row][col] += A[row][inner] * A1[inner][col];
			}
			cout << setw(4) << setprecision(1) << product[row][col] << "  ";
		}
		cout << endl;
	}
}
int main()
{
	cout << "Started Matrix:" << endl << endl;
	init();
	printMatrix();
	reverseMatrix();
	cout << "Reversed Matrix:" << endl << endl;
	printMatrix(0);
	cout << "A^-1*E = " << endl << endl;
	init(0);
	MultiPlicationMatrix();
	system("pause");
	return 0;
}