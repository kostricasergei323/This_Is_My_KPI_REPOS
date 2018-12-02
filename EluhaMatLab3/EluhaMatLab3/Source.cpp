#define n  4
#define m  5
#include <fstream>
#include <iostream>

using namespace std;

double matr[n][m];
double x[n] = {0};
double x_prev[n] = {0};

void init();
void miss();

int main()
{
	double eps = 0.0001;
	double sum;
	double first;
	double second;
	double y;

	int k = 0;
	
	ofstream fout("laba_3.txt");

	init();
	
	// Перестановка рядкiв матрицi щоб елементи головної дiагоналi були бiльше суми модулiв iнших елементiв рядка
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++) 
		{
			// Пошук суми елементiв рядка
			sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += fabs(matr[i][k]);
			}
			sum -= fabs(matr[i][j]);
			// Перестановка рядкiв якщо вони вiдповiдають умовi
			if (matr[i][j] > sum)
			{
				for (int l = 0; l < n; l++) 
				{
					swap(matr[j][l], matr[i][l]);
				}
				swap(matr[j][n], matr[i][n]);
			}
		}
	}

	do
	{
		k++; // итерации

		for (int i = 0; i < n; i++) // Сохранение х на предыдущей итерации
		{
			x_prev[i] = x[i];
		}

		for (int i = 0; i < n; i++)
		{
			first = 0;
			second = 0;
			for (int j = 1; j < i - 1; j++) // Подсчет первой суммы
			{
				first += matr[i][j] * x[j];
			}

			for (int j = i + 1; j < n; j++) // Подсчет второй суммы
			{
				second += matr[i][j] * x_prev[j];
			}
			x[i] = 1 / matr[i][i] * (matr[i][n] - first - second); // Подсчет х
		}

		y = x[0] - x_prev[0];
		fout << k << " " << y << endl; //запись в файл нужных для графика значений

	} while (fabs(x[0] - x_prev[0]) > eps && k < 40);

	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << " = " << x[i] << endl;
	}
	cout << "Kolichestvo iteratsii " << k << endl;
	miss();
	fout.close();

	system("pause");
	return 0;
}

//  Вычисление погрешности
void miss()
{
	init();
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "x[" << i + 1 << "] = " << x[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		double s = 0;								// Сума ряда
		for (int j = 0; j < n; j++)
		{
			s += matr[i][j] * x[j];
		}
		printf("a[%d] = %lf\n", i + 1, s - matr[i][n]);	// Вывод каждой погрешности
	}
}

void init() 
{
	matr[0][0] = 8.;   matr[0][1] = 1000.;  matr[0][2] = -1.;  	matr[0][3] = 900.; matr[0][4] = 1.;
	matr[1][0] = 10.;  matr[1][1] = 0.;     matr[1][2] = 500.; 	matr[1][3] = 5.;   matr[1][4] = 2.;
	matr[2][0] = 14.;  matr[2][1] = 2.;     matr[2][2] = 29.;  	matr[2][3] = 6.;   matr[2][4] = 34.;
	matr[3][0] = 1.;   matr[3][1] = 5.;     matr[3][2] = 13.;  	matr[3][3] = 47.;  matr[3][4] = 6.;
}