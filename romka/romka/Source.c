#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void processing();
int exitFunction();

// головна функцiя
int main() {
	system("chcp 1251");
	do
	{
		system("cls");

		printf("       ___  (-1)^(n-1)(x - 1) ^ n\n");
		printf("f(x) = \\   ---------------------\n");
		printf("       /__           n\n\n");

		processing();
	} while (exitFunction());
	return 0;
}

// функцiя обробки
void processing() {
	float x1;   // Лiва межа промiжку 
	float x2;   // Права межа промiжку
	float step; // Крок
	float result;  // Результат функцiї
	float curElem; // current Element
	double eps; // Точнiсть
	int n;

	x1 = 0;
	x2 = 5;
	step = 0.05;
	eps = 1e-8; // 0,00000001

	printf("\n      x    |   f(x)   |   ln(x)  |  iтерацiй\n");
	// обчислення значення суми
	do
	{
		// встановлення пресетiв
		n = 2;
		result = x1 - 1;
		curElem = x1 - 1;
		// обчислення суми
		while (fabs(curElem) > eps)
		{
			curElem *= -(x1 - 1) * (n - 1) / n;
			result += curElem;
			n++;
		}
		// вивiд результатiв
		printf("   %6.2f    %8.5f   %8.5f      %3d\n", x1, result, log(x1), n - 1);
		x1 += step;
	} while (x1 <= x2);
}

//вихiд з програми
int exitFunction() {
	char v; // v - вiдповiдь користувача
	while (getchar() != '\n');
	do
	{
		printf("\nБажаєте продовжити? (y/n) : ");
		scanf_s("%c", &v);
		while (getchar() != '\n');
		if (v == 'y' || v == 'Y')
		{
			return 1; // продовження роботи
		}
		else
		{
			if (v == 'n' || v == 'N')
			{
				return 0;  // завершення роботи
			}
			else
			{
				printf("*** Помилка! Вводьте вiдповiдь у форматi y/n!  ***\n");
			}
		}
	} while (1);
}
