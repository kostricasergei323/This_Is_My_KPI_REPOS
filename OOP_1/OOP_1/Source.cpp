#include "graphics.h"	// Библiотека графiки для таблиць
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <ctime>

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);;

// Константнi змiннi
int a = 5;
int b = 3;

struct funcParams
{
  float x1, x2;				// Дiапазон
  float dx;					// Крок функцii
  int size;					// Кiлькiсть значень
  float *valArr;				// Масив значень
};


void  readParam(funcParams &Param);									// Створення структури парамерiв
void  randArray(funcParams &Param, float *randArr);					// Створення масиву середнiх значень
void  funcProcessing(funcParams &Param);							// Обробка значень
float sum(funcParams &Param);										// Обчислення суми парих елементiв
float average(funcParams &Param);									// Обчислення середнiх значень
void  gotoxy(int x, int y);											// Перенести курсор
void  print(float *arr, int size);									// Вивести графiк


int main() {
  printf("	  (a - b) ^ x,		x < 1\n");
  printf("F(x) =\n");
  printf("	  a * x - b / x,	x >= 1\n\n");

  // Створення структури параметрiв
  funcParams Param;
  readParam(Param);

  // Обробка значень
  funcProcessing(Param);

  // Створення масиву середнiх значень
  float *random = new float[Param.size];
  randArray(Param, random);

  // Вивiд основноi таблицi
  printTable(Param.x1, Param.valArr, random, Param.dx, Param.size);
  // Вивiд таблицi середнiх значень
  printSpecs(average(Param), sum(Param));
  // Вивiд графiка
  print(Param.valArr, Param.size);

  getchar();
  getchar();
  return 0;
}

// Функцiя введення параметрiв змiнних
void readParam(funcParams &Param) {
  // Введення значень границь х1 и х2
  float x1, x2;
  printf("Enter x1: ");
  scanf_s("%f", &x1);

  printf("Enter x2: ");
  scanf_s("%f", &x2);

  if (x1 > x2) { float t = x1; x1 = x2; x2 = t; }
  Param.x1 = x1;
  Param.x2 = x2;

  // Введення кроку dx
  float step;
  do {
    printf("Enter dx: ");
    scanf_s("%f", &step);
  } while (step == 0);
  Param.dx = fabs(step);

  // Обчислення кiлькостi майбутнiх значень
  Param.size = round(fabs((x2 - x1) / step) + 1);
  Param.valArr = new float[Param.size];
}

// Обчислення значень функцii
void funcProcessing(funcParams &Param) {
  float res;
  float x;
  int index = 0;

  x = Param.x1;
  while (x <= Param.x2) {
    (x < 1) ? res = pow(a - b, x) : res = a * x - b / x;
    Param.valArr[index] = res;
    index++;
    x += Param.dx;
  }
}

// Сума всiх непарних eлементiв
float sum(funcParams &Param) {
  float sum = 0;
  for (int i = 0; i < Param.size; i++) {
    sum += Param.valArr[i];
    i++;
  }
  return sum;
}

// Середне арифметичне елементiв, парних п'яти
float average(funcParams &Param) {
  float sum = 0;
  int amount = 0;
  for (int i = 4; i < Param.size; i += 5) {
    sum += Param.valArr[i];
    amount++;
  }
  return (amount > 0) ? sum / amount : 0;
}

// Створення масиву середнiх значень
void randArray(funcParams &Param, float *randArr) {
  srand(time(NULL));
  for (int i = 0; i < Param.size - 1; i++) {
    randArr[i] = Param.valArr[i] + (Param.valArr[i + 1] - Param.valArr[i]) * (rand() % 10 / 10.);
  }
  randArr[Param.size - 1] = Param.valArr[Param.size - 1];
}

// Перевести курсор в точку x,y
void gotoxy(int x, int y)
{
  COORD cursorPos = { x, y };
  SetConsoleCursorPosition(hOut, cursorPos);
}

// Вивiд графiка
void print(float *arr, int size) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  int columns, rows;
  GetConsoleScreenBufferInfo(hOut, &csbi);
  columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

  if (columns < 50) return;

  float max, min;									// Максимальний, мiнiмальний елемент
  float value;									// Цiна подiлки

  int N;											// Кiлькiсть можливих стовпцiв в графiку
  N = (columns - 50) / 3;
  if (size < N) N = size;

  // Пошук max, min
  max = min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max)
    {
      max = arr[i];
    }
    else if (arr[i] < min)
    {
      min = arr[i];
    }
  }

  value = (max - min) / rows;

  //Вивiд стовпчикiв
  SetConsoleTextAttribute(hOut, 130);
  for (int i = 0; i < N; i++) {
    int k = (arr[i] - min) / value;
    gotoxy(50 + i * 3, rows - 1);
    printf("%c", (char)219);
    for (int j = 1; j < k; j++)
    {
      gotoxy(50 + i * 3, rows - j - 1);
      printf("%c", (char)219);
    }
  }
  SetConsoleTextAttribute(hOut, 240);
}