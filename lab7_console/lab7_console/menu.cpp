#include "drawmenu.h"
#include <windows.h>
#include <iostream>
#include <cmath>
#include "menu.h"

using namespace std;

extern HANDLE hOut; // Дескриптор консольного окна
extern CONSOLE_SCREEN_BUFFER_INFO csbInfo; // Информация о консольном окне
extern SMALL_RECT consolRect; // Координаты углов консоли
extern WORD woкkWindowAttributes; // Параметры окна

int main() {
  system("chcp 1251");
  SetConsoleTitle("Графика в консоли");

  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hOut == INVALID_HANDLE_VALUE) {
    MessageBox(NULL, "Ошибка получения дескриптора", "Ошибка", MB_OK | MB_ICONERROR);
    return 1;
  }

  showCursor(false);
  GetConsoleScreenBufferInfo(hOut, &csbInfo);
  consolRect = csbInfo.srWindow; //координаты углов консоли
  SetConsoleTextAttribute(hOut, woкkWindowAttributes);
  system("cls");
  DrawMenu();
  return 0;
}

void Graph() {
  double x;
  double xO = 700, yO = 500; // Начало координат
  double xBeg = -8.0, xEnd = 15.0;
  double xScale =20, yScale = 20; // масштаб по осям X и Y
  cout << "Вы выбрали меню 'График'\n";
  cout << "\n\n\n\n	y = ln(x)\n";
  HDC hdc = GetDC(GetConsoleWindow());

  HPEN Pen = CreatePen(PS_SOLID, 3, RGB(0, 100, 255));
  SelectObject(hdc, Pen);
  MoveToEx(hdc, xO - 400, yO, NULL);
  LineTo(hdc, xO + 400, yO);
  MoveToEx(hdc, xO + 390, yO - 10, NULL);
  LineTo(hdc, xO + 400, yO);
  LineTo(hdc, xO + 390, yO + 10);

  MoveToEx(hdc, xO, yO + 400, NULL);
  LineTo(hdc, xO, yO - 400);
  MoveToEx(hdc, xO - 10, yO - 390, NULL);
  LineTo(hdc, xO, yO - 400);
  LineTo(hdc, xO + 10, yO - 390);


  Pen = CreatePen(PS_SOLID, 3, RGB(120, 130, 245));
  SelectObject(hdc, Pen);
  for (int i = -8; i < 400 / xScale; i++)
  {
    MoveToEx(hdc, xO + xScale * i, yO - 5, NULL);
    LineTo(hdc, xO + xScale * i, yO + 5);
    MoveToEx(hdc, xO - xScale * i, yO - 5, NULL);
    LineTo(hdc, xO - xScale * i, yO + 5);
  }
  for (int i = -8; i < 400 / yScale; i++)
  {
    MoveToEx(hdc, xO - 5, yO + yScale * i, NULL);
    LineTo(hdc, xO + 5, yO + yScale * i);
    MoveToEx(hdc, xO - 5, yO - yScale * i, NULL);
    LineTo(hdc, xO + 5, yO - yScale * i);
  }



  Pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
  SelectObject(hdc, Pen);


  MoveToEx(hdc, xO + xScale - 5, yO + 15, NULL);
  LineTo(hdc, xO + xScale, yO + 10);
  LineTo(hdc, xO + xScale, yO + 25);

  MoveToEx(hdc, xO - 15, yO - yScale + 5, NULL);
  LineTo(hdc, xO - 15, yO - yScale - 10);
  LineTo(hdc, xO - 20, yO - yScale - 5);

  MoveToEx(hdc, xO + 390, yO + 10, NULL);
  LineTo(hdc, xO + 400, yO + 25);
  MoveToEx(hdc, xO + 400, yO + 10, NULL);
  LineTo(hdc, xO + 390, yO + 25);

  MoveToEx(hdc, xO + 15, yO - 400, NULL);
  LineTo(hdc, xO + 21, yO - 390);
  MoveToEx(hdc, xO + 27, yO - 400, NULL);
  LineTo(hdc, xO + 21, yO - 390);
  LineTo(hdc, xO + 21, yO - 380);

  MoveToEx(hdc, xO + xScale * xBeg, yO - yScale * log(xBeg), NULL);
  for (x = xBeg; x < 0; x += 0.01f)
  {
    LineTo(hdc, xO + xScale * x, yO - yScale * log(x)); 
  }
  x = 0.1;
  while (log(x) > 400 / yScale)
  {
    x += 0.01f;
  }
  MoveToEx(hdc, xO + xScale * x, yO - yScale * log(x), NULL);
  for (; x <= xEnd; x += 0.01f)
  {
    LineTo(hdc, xO + xScale * x, yO - yScale * log(x));
  }


}


void Art() {
  HWND hwnd = GetConsoleWindow();
  HDC hdc = GetDC(hwnd);
  int x = 10;
  Sleep(100);

  SelectObject(hdc, CreatePen(PS_SOLID, 5, RGB(255, 225, 95)));
  SelectObject(hdc, CreateSolidBrush(RGB(200, 70, 140)));
  Ellipse(hdc, 572, 172, 868, 468);
  RECT rct = { 108 * x, 29 * x, 115 * x, 30 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 107 * x, 55 * x, 130 * x, 60 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 104 * x, 58 * x, 135 * x, 65 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 103 * x, 59 * x, 138 * x, 65 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 102 * x, 60 * x, 139 * x, 65 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 100 * x, 61 * x, 140 * x, 65 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 99 * x, 62 * x, 140 * x, 65 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 98 * x, 63 * x, 140 * x, 65 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 106 * x, 56 * x, 135 * x, 59 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 115 * x, 65 * x, 135 * x, 66 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 123 * x, 66 * x, 134 * x, 67 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 97 * x, 65 * x, 105 * x, 67 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 97 * x, 65 * x, 98 * x, 68 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 105 * x, 55 * x, 120 * x, 56 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(50, 40, 135)));
  rct = { 110 * x, 52 * x, 128 * x, 58 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(110, 10, 35)));
  rct = { 105 * x, 41 * x, 120 * x, 44 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(100, 15, 30)));
  rct = { 108 * x, 45 * x, 116 * x, 44 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(100, 15, 30)));
  rct = { 107 * x, 30 * x, 116 * x, 31 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 106 * x, 31 * x, 117 * x, 35 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 107 * x, 33 * x, 115 * x, 41 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 110 * x, 41 * x, 115 * x, 45 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 108 * x, 33 * x, 109 * x, 34 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 109 * x, 32 * x, 114 * x, 33 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 110 * x, 32 * x, 111 * x, 33 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 115 * x, 33 * x, 117 * x, 39 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 115 * x, 39 * x, 116 * x, 40 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 108 * x, 40 * x, 109 * x, 42 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 109 * x, 41 * x, 113 * x, 43 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 116 * x, 47 * x, 122 * x, 57 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(50, 40, 135)));
  rct = { 119 * x, 57 * x, 122 * x, 61 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 119 * x, 56 * x, 120 * x, 57 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 118 * x, 59 * x, 119 * x, 60 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 109 * x, 39 * x, 112 * x, 40 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 112 * x, 40 * x, 113 * x, 42 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 109 * x, 42 * x, 112 * x, 43 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 110 * x, 41 * x, 111 * x, 42 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 107 * x, 35 * x, 109 * x, 36 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 109 * x, 36 * x, 110 * x, 37 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 112 * x, 35 * x, 114 * x, 36 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 111 * x, 36 * x, 112 * x, 37 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(0, 0, 0)));
  rct = { 108 * x, 45 * x, 109 * x, 46 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(100, 15, 30)));
  rct = { 115 * x, 36 * x, 116 * x, 38 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 108 * x, 36 * x, 109 * x, 38 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(5, 110, 135)));
  rct = { 112 * x, 36 * x, 113 * x, 38 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(5, 110, 135)));
  rct = { 103 * x, 41 * x, 105 * x, 42 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 104 * x, 42 * x, 107 * x, 43 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 105 * x, 43 * x, 107 * x, 44 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 106 * x, 44 * x, 108 * x, 46 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 107 * x, 46 * x, 108 * x, 47 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 111 * x, 45 * x, 112 * x, 46 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 215, 156)));
  rct = { 108 * x, 46 * x, 116 * x, 60 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 107 * x, 49 * x, 108 * x, 55 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(30, 20, 110)));
  rct = { 102 * x, 49 * x, 107 * x, 55 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(50, 40, 135)));
  rct = { 99 * x, 49 * x, 102 * x, 54 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(50, 40, 135)));
  rct = { 97 * x, 49 * x, 99 * x, 53 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(50, 40, 135)));
  rct = { 89 * x, 49 * x, 98 * x, 52 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 89 * x, 45 * x, 92 * x, 51 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 90 * x, 44 * x, 91 * x, 45 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 92 * x, 48 * x, 93 * x, 49 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 214, 156)));
  rct = { 109 * x, 44 * x, 110 * x, 46 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 110 * x, 45 * x, 111 * x, 46 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 112 * x, 45 * x, 116 * x, 46 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 114 * x, 44 * x, 116 * x, 45 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 120 * x, 41 * x, 122 * x, 42 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 118 * x, 42 * x, 121 * x, 43 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 117 * x, 43 * x, 120 * x, 44 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 116 * x, 44 * x, 119 * x, 45 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 116 * x, 45 * x, 118 * x, 47 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 103 * x, 48 * x, 107 * x, 49 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 105 * x, 47 * x, 108 * x, 49 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 105 * x, 48 * x, 107 * x, 49 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 255, 180)));
  rct = { 106 * x, 47 * x, 107 * x, 48 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 255, 180)));
  rct = { 108 * x, 48 * x, 109 * x, 50 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 255, 180)));
  rct = { 116 * x, 47 * x, 117 * x, 49 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 255, 180)));
  rct = { 109 * x, 50 * x, 112 * x, 54 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 255, 180)));
  rct = { 113 * x, 50 * x, 114 * x, 51 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 255, 180)));
  rct = { 114 * x, 48 * x, 116 * x, 50 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 255, 180)));
  rct = { 115 * x, 47 * x, 117 * x, 49 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 255, 180)));
  rct = { 117 * x, 47 * x, 122 * x, 49 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 118 * x, 48 * x, 123 * x, 50 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 120 * x, 49 * x, 124 * x, 51 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 122 * x, 50 * x, 125 * x, 52 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 123 * x, 51 * x, 127 * x, 53 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 124 * x, 52 * x, 130 * x, 54 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 126 * x, 53 * x, 132 * x, 55 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 128 * x, 54 * x, 134 * x, 56 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 132 * x, 55 * x, 135 * x, 57 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 132 * x, 55 * x, 135 * x, 57 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 108 * x, 51 * x, 113 * x, 53 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(255, 255, 180)));
  rct = { 109 * x, 51 * x, 112 * x, 53 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(50, 110, 20)));
  rct = { 110 * x, 51 * x, 111 * x, 52 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(100, 208, 92)));
  rct = { 106 * x, 63 * x, 118 * x, 65 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 103 * x, 64 * x, 119 * x, 66 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 112 * x, 65 * x, 120 * x, 67 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 116 * x, 57 * x, 117 * x, 60 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 102 * x, 66 * x, 110 * x, 67 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(40, 5, 90)));
  rct = { 108 * x, 59 * x, 117 * x, 62 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(20, 10, 10)));
  rct = { 109 * x, 60 * x, 117 * x, 61 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(70, 60, 45)));
  rct = { 110 * x, 59 * x, 111 * x, 61 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 155, 40)));
  rct = { 108 * x, 62 * x, 117 * x, 64 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(20, 10, 10)));
  rct = { 108 * x, 62 * x, 115 * x, 63 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(70, 60, 45)));
  rct = { 110 * x, 63 * x, 111 * x, 64 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 155, 40)));
  rct = { 112 * x, 62 * x, 113 * x, 64 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 155, 40)));
  rct = { 114 * x, 62 * x, 115 * x, 64 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 155, 40)));
  rct = { 117 * x, 62 * x, 118 * x, 64 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 155, 40)));
  rct = { 115 * x, 61 * x, 117 * x, 62 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 155, 40)));

  rct = { 115 * x, 64 * x, 117 * x, 65 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 155, 40)));
  rct = { 134 * x, 56 * x, 136 * x, 58 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 135 * x, 57 * x, 137 * x, 59 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 136 * x, 58 * x, 138 * x, 60 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 137 * x, 59 * x, 138 * x, 61 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 138 * x, 60 * x, 139 * x, 62 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 139 * x, 61 * x, 140 * x, 63 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 140 * x, 63 * x, 141 * x, 64 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 140 * x, 64 * x, 142 * x, 66 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));
  rct = { 141 * x, 66 * x, 142 * x, 68 * x };
  FillRect(hdc, &rct, CreateSolidBrush(RGB(220, 55, 55)));

  SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(120, 200, 100)));
  MoveToEx(hdc, 90 * x, 53 * x, NULL);
  LineTo(hdc, 85 * x, 50 * x);
  LineTo(hdc, 86 * x, 44 * x);
  LineTo(hdc, 91 * x, 42 * x);
  LineTo(hdc, 95 * x, 45 * x);
  LineTo(hdc, 94 * x, 51 * x);
  LineTo(hdc, 90 * x, 53 * x);

  MoveToEx(hdc, 120 * x, 64 * x, NULL);
  LineTo(hdc, 117 * x, 63 * x);
  LineTo(hdc, 115 * x, 61 * x);
  LineTo(hdc, 115 * x, 56 * x);
  LineTo(hdc, 117 * x, 54 * x);
  LineTo(hdc, 120 * x, 53 * x);
  LineTo(hdc, 123 * x, 54 * x);
  LineTo(hdc, 125 * x, 56 * x);
  LineTo(hdc, 125 * x, 61 * x);
  LineTo(hdc, 123 * x, 63 * x);
  LineTo(hdc, 120 * x, 64 * x);

  MoveToEx(hdc, 120 * x, 63 * x, NULL);
  LineTo(hdc, 116 * x, 59 * x);
  LineTo(hdc, 120 * x, 54 * x);
  LineTo(hdc, 124 * x, 59 * x);
  LineTo(hdc, 120 * x, 63 * x);
  SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(90, 220, 100)));
  MoveToEx(hdc, 85 * x, 54 * x, NULL);
  LineTo(hdc, 91 * x, 40 * x);
  LineTo(hdc, 95 * x, 54 * x);
  LineTo(hdc, 83 * x, 45 * x);
  LineTo(hdc, 97 * x, 46 * x);
  LineTo(hdc, 85 * x, 54 * x);
  LineTo(hdc, 83 * x, 51 * x);
  LineTo(hdc, 83 * x, 45 * x);
  LineTo(hdc, 87 * x, 41 * x);
  LineTo(hdc, 91 * x, 40 * x);
  LineTo(hdc, 95 * x, 42 * x);
  LineTo(hdc, 97 * x, 46 * x);
  LineTo(hdc, 97 * x, 50 * x);
  LineTo(hdc, 95 * x, 54 * x);
  LineTo(hdc, 90 * x, 55 * x);
  LineTo(hdc, 85 * x, 54 * x);
}

//Функция меню <Выход> - завершение программы
void Exit() {
  int resp;
  cout << "Вы уверены, что хотите выйти из программы? (y/n)";
  resp = getchar();
  if (resp == 'y' || resp == 'Y') {
    cls();
    exit(0);
  }
}