/**********************************************************************************************************/
/*** 									                Лабороторна робота №1 										                        ***/
/*** 										                   Варiант №10		 										                          ***/
/*** 								  		                   	З курсу		 											                          ***/
/*** 								                  		Чисельнi методи 										                        	***/
/*** 							              		ОБЧИСЛЕННЯ ФУНКЦІОНАЛЬНИХ РЯДІВ								                     	***/
/*** 							                    				Завдання: 								 				                        ***/
/***	Для ряду f(x) = Е (a(i)). Обчислити його наближене значення при х э [0, 1] з кроком h = 0.05.   	***/
/***	Обчислення припинити, якщо | ai | < e = 0.001 для двох послідовних членів ряду. Задане точне 	    ***/
/***	значення ряду fточ(х). Вивести кількість ітерацій N(x, e), при яких була досягнута точність e.	  ***/
/***	Побудувати таблицю. Побудувати на одному полі графіки функцій y = f(x), y = fточ(x).		        	***/
/***	Для х = 0.5 побудувати графік аi(i).														                                 	***/
/***																Виконав:	Костриця Сергій ТР-71                                   	***/
/***																Перевiрив:	Сiгайов А. О.			                                      ***/
/**********************************************************************************************************/

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

HDC hdc = GetDC(GetConsoleWindow());

int xO = 1000, yO = 675; // Початок координат графiку 1
int xl = 200, yl = 930;  // Початок координат графiку 2
int Scalex = 450;		     // Множник масштабування x
int Scaley = 100;		     // Множник масштабування y

void Graph();             // Функцiя малювання координатних вiсей графiкiв

int main() {

  double x = 0.05;
  double h = 0.05;											                          // Крок
  double eps = 0.001;										                        	// Точнiсть обчислень

  double prev;											                            	// Попереднiй елемент суми
  double cur;												                            	// Поточний елемент суми
  double sum;													                            // Значення суми ряду
  double a = exp(2);
  int n;														                              // Кiлькiсть iтерацiй

  Graph();													                              // Функцiя малювання координатних вiсей графiкiв
  SelectObject(hdc, CreatePen(PS_SOLID, 5, RGB(125, 0, 250)));    // Вибiр нового пензлика фіолетового кольору
  MoveToEx(hdc, xO, yO - Scaley, NULL);								            // Перехiд на початок координат графiка 1

                                                                  // Вивiд графiку функцii tan(x)
  for (double x = 0; x < 1; x += 0.01)
  {
    LineTo(hdc, xO + Scalex * x, yO - pow(a, x) * Scaley);
  }

  SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(125, 0, 0)));	     // Вибiр нового пензлика червоного кольору
  MoveToEx(hdc, xO, yO - Scaley, NULL);								             // Перехiд на початок координат графiка 1

  // Вивiд обрамлення таблицi
  cout << fixed << "      x    |     f(x)    |    ft(x)     |       %        |	n" << endl << endl;

  // Вивiд рядкiв таблицi i графiка суми ряду
  do
  {
    n = 0;													                                              // Онулення значення iтерацiй
    sum = 1;												                                              // Онулення суми ряда				
    prev = cur = 1;							                                                	// Попереднiй пресет значень

    //Обчислення суми ряда за рекурентною формулою, обчислення припинити, якщо останнi два члена менше епсiлона
    while ((fabs(cur) > eps || fabs(prev) > eps)) {
      n++;
      prev = cur;											                                            // Запам'ятовування попереднього елемента суми ряда
      cur *= x * log(a) / n;
      sum += cur;											                                            // Додання поточного елемента до суми
    }
    
    // Вивiд результатiв у таблицю
    cout << "    " << setw(3) << setprecision(2) << x << setw(15) << setprecision(6) << sum << setw(14) << pow(a, x)
      << "	   " << setw(9) << (sum - pow(a, x)) / sum * 100 << "%";
    cout << setw(12) << n << endl; 

    // Вивiд графiка суми ряда
    LineTo(hdc, xO + Scalex * x, yO - sum * Scaley);

    x += h;
  } while (x <= 1.01);

  // Вивiд графiка залежностi елементiв суми ряду вiд iтератора при x = 0.5
  SelectObject(hdc, CreatePen(PS_SOLID, 7, RGB(0, 20, 250)));	  // Вибiр нового пензлика синього кольору
  cur = 1;											                  	            // Задання пресетiв
  MoveToEx(hdc, xl, yl, NULL);							                  	// Перехiд на початок координат графiка 2
  for (int i = 1; i < 8; i++)
  {
    cur *= x * log(a) / n;
    LineTo(hdc, xl + i * 80, yl - cur * 400);				            // Вивiд графiка
  }

  getchar();	                                                  // Затримка екрану
  return 0;
}

// Функцiя малювання координатних вiсей графiкiв
void Graph() {
  SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 0)));
  // Вивiд графiка 1
  MoveToEx(hdc, xO, yO, NULL);
  LineTo(hdc, xO + 600, yO);
  MoveToEx(hdc, xO + 590, yO - 10, NULL);
  LineTo(hdc, xO + 600, yO);
  LineTo(hdc, xO + 590, yO + 10);

  MoveToEx(hdc, xO, yO, NULL);
  LineTo(hdc, xO, yO - 600);
  MoveToEx(hdc, xO - 10, yO - 590, NULL);
  LineTo(hdc, xO, yO - 600);
  LineTo(hdc, xO + 10, yO - 590);

  for (int i = 1; i < 600 / Scalex; i++)
  {
    MoveToEx(hdc, xO + Scalex * i, yO - 5, NULL);
    LineTo(hdc, xO + Scalex * i, yO + 5);
    MoveToEx(hdc, xO - 5, yO - Scaley * i, NULL);
    LineTo(hdc, xO + 5, yO - Scaley * i);
  }

  MoveToEx(hdc, xO + Scalex - 5, yO + 15, NULL);
  LineTo(hdc, xO + Scalex, yO + 10);
  LineTo(hdc, xO + Scalex, yO + 25);

  MoveToEx(hdc, xO - 15, yO - Scaley + 5, NULL);
  LineTo(hdc, xO - 15, yO - Scaley - 10);
  LineTo(hdc, xO - 20, yO - Scaley - 5);

  MoveToEx(hdc, xO + 590, yO + 10, NULL);
  LineTo(hdc, xO + 600, yO + 25);
  MoveToEx(hdc, xO + 600, yO + 10, NULL);
  LineTo(hdc, xO + 590, yO + 25);

  MoveToEx(hdc, xO + 15, yO - 600, NULL);
  LineTo(hdc, xO + 21, yO - 590);
  MoveToEx(hdc, xO + 27, yO - 600, NULL);
  LineTo(hdc, xO + 21, yO - 590);
  LineTo(hdc, xO + 21, yO - 580);

  // Вивiд графiка 2
  MoveToEx(hdc, xl, yl, NULL);
  LineTo(hdc, xl + 600, yl);
  MoveToEx(hdc, xl + 590, yl - 10, NULL);
  LineTo(hdc, xl + 600, yl);
  LineTo(hdc, xl + 590, yl + 10);

  MoveToEx(hdc, xl, yl, NULL);
  LineTo(hdc, xl, yl - 230);
  MoveToEx(hdc, xl - 10, yl - 220, NULL);
  LineTo(hdc, xl, yl - 230);
  LineTo(hdc, xl + 10, yl - 220);

  MoveToEx(hdc, xl - 5, yl - 200, NULL);
  LineTo(hdc, xl + 5, yl - 200);

  for (int i = 1; i < 7; i++)
  {
    MoveToEx(hdc, xl + 80 * i, yl - 5, NULL);
    LineTo(hdc, xl + 80 * i, yl + 5);
  }
}