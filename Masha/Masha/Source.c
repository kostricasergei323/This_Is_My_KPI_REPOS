#define _CRT_SECURE_NO_WARNINGS
#define N 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void SortArray(char* addr[N], int size);
int main()
{
	char list[N][N];
	char* addr[N];
	int n_str;

	printf("Enter quantity of string: ");
	scanf_s("%d", &n_str);
	printf("Enter your strings:\n");
	while (getchar()!= '\n');
	for (int i = 0; i < n_str; i++)
	{
		gets(list[i]);
		addr[i] = list[i];
	}
	SortArray(addr, n_str);
	printf("Sorted list:\n");
	for (int i = 0; i < n_str; i++)
	{
		printf("%s\n", addr[i]);
	}
	system("pause");
	return 0;
}
void SortArray(char* addr[N], int size)
{
	char temp[N];
	int exit = 0;
	while (!exit)
	{
		exit = 1;
		for (int i = 0; i < size - 1; i++)
		{
			if (strcmp(addr[i], addr[i+1])>0)
			{
				strcpy(temp, addr[i]);
				strcpy(addr[i], addr[i + 1]);
				strcpy(addr[i + 1], temp);
				exit = 0;
			}
		}
	}
}