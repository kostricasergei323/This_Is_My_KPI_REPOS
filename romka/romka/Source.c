#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void processing();
int exitFunction();

// ������� �����i�
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

// �����i� �������
void processing() {
	float x1;   // �i�� ���� ����i��� 
	float x2;   // ����� ���� ����i���
	float step; // ����
	float result;  // ��������� �����i�
	float curElem; // current Element
	double eps; // ����i���
	int n;

	x1 = 0;
	x2 = 5;
	step = 0.05;
	eps = 1e-8; // 0,00000001

	printf("\n      x    |   f(x)   |   ln(x)  |  i�����i�\n");
	// ���������� �������� ����
	do
	{
		// ������������ ������i�
		n = 2;
		result = x1 - 1;
		curElem = x1 - 1;
		// ���������� ����
		while (fabs(curElem) > eps)
		{
			curElem *= -(x1 - 1) * (n - 1) / n;
			result += curElem;
			n++;
		}
		// ���i� ���������i�
		printf("   %6.2f    %8.5f   %8.5f      %3d\n", x1, result, log(x1), n - 1);
		x1 += step;
	} while (x1 <= x2);
}

//���i� � ��������
int exitFunction() {
	char v; // v - �i����i�� �����������
	while (getchar() != '\n');
	do
	{
		printf("\n������ ����������? (y/n) : ");
		scanf_s("%c", &v);
		while (getchar() != '\n');
		if (v == 'y' || v == 'Y')
		{
			return 1; // ����������� ������
		}
		else
		{
			if (v == 'n' || v == 'N')
			{
				return 0;  // ���������� ������
			}
			else
			{
				printf("*** �������! ������� �i����i�� � ������i y/n!  ***\n");
			}
		}
	} while (1);
}
