#include "drawmenu.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include "menu.h"

using namespace std;

#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_ENTER 13

typedef void(*FUN) (void);

// Элемент меню
typedef struct { 
	int x, y;	 // Координаты
	char *str;   // Имя
	FUN f;	     // Исполняемая функция
} ITEM;

HANDLE hOut;
CONSOLE_SCREEN_BUFFER_INFO csbInfo;
SMALL_RECT consolRect; // Углы меню
COORD curspos = { 0,1 }; // Координаты курсора
WORD woкkWindowAttributes = 240; // Цвет фона 158
WORD inactiveItemAttributes = 31; // Цвет неактивного пункта меню
WORD activeItemAttributes = 120; // Цвет выбранного пункта меню
enum menuitems { M_GRAPH, M_ART, M_EXIT };
extern const int numMenu = 3; //количество пунктов меню

char line1[9] = " График ";
char line2[10] = " Рисунок ";
char line4[8] = " Выход ";

//положение (x,y), заголовок, указатель на функцию
ITEM menu[numMenu] = { 
	{ 0, 0, line1, Graph },
	{ 8, 0, line2, Art },
	{ 17, 0, line4, Exit }
};

void DrawMenu() { //Управление меню
	menuitems sel = M_GRAPH; // Номер текущего пункта меню
	SetConsoleTextAttribute(hOut, inactiveItemAttributes);
	string s(90, ' '); cout << s.c_str(); //залить фон строки меню
	for (int i = 0; i < numMenu; i++) { //Напечатать заголовки пунктов меню
		gotoxy(menu[i].x, menu[i].y);
		cout << menu[i].str;
	}
	itemMenu(sel, true); // выделить пункт меню
	fflush(stdin); //очистить буфер клавиатуры
	int iKey = 67;
	while (true)
	{
		if (_kbhit())
		{
			iKey = _getch();
			switch (iKey)
			{
			case KEY_RIGHT:
				itemMenu(sel, false);
				(sel < numMenu - 1) ? sel = (menuitems)(sel + 1) : sel = M_GRAPH;
				itemMenu(sel, true);
				showCursor(false);
				break;
			case KEY_LEFT:
				itemMenu(sel, false);
				(sel >0) ? sel = (menuitems)(sel - 1) : sel = M_EXIT; 
				itemMenu(sel, true);
				showCursor(false);
				break;
			case KEY_ENTER:
			//	cls();
				curspos = { 0,1 };
				gotoxy(curspos.X, curspos.Y); // Возвращаем курсор из строки меню в прежнюю позицию
				SetConsoleTextAttribute(hOut, woкkWindowAttributes); // Установить цвет рабочих сообщений
				showCursor(true);
				switch (sel)
				{
				case M_GRAPH:
					Graph();
					getCursorPosition(); // запомнить положение курсора
					break;
				case M_ART:
					Art();
					getCursorPosition(); // запомнить положение курсора
					break;
				case M_EXIT:
					int resp;
					cout << "Вы уверены, что хотите выйти из программы ? (y / n) ? ";
						resp = getchar();
					if (resp == 'y' || resp == 'Y')
					{
						gotoxy(0, 0); 
						cls(); 
						exit(0);
					}
					getCursorPosition(); // запомнить положение курсора, если отменили выход
					break;
				}
				fflush(stdin); //очистить буфер клавиатуры
				gotoxy(menu[sel].x, menu[sel].y); // курсор в текущий пункт меню
				showCursor(false);
				break;
			case 120: case 88: case 27: // выход по клавише ESC, x, X
				gotoxy(0, 0);
				cls();
				exit(0); //завершение программы
			}
		}
		Sleep(50);
	}
}

// Перевести курсор в точку x,y
void gotoxy(int x, int y)
{
	COORD cursorPos = { x, y };
	SetConsoleCursorPosition(hOut, cursorPos);
}

// Запись текущего положения текстового курсора в глобальную переменную curspos
void getCursorPosition(void)
{
	GetConsoleScreenBufferInfo(hOut, &csbInfo);
	curspos = csbInfo.dwCursorPosition;
}

// Очистка экрана
void cls()
{
	string s(100, ' ');
	SetConsoleTextAttribute(hOut, woкkWindowAttributes);
	gotoxy(0, 1);
 
	for (int i = 1; i < 26; i++) {
		cout << s.c_str(); // залить фон строки меню
	}
	gotoxy(0, 0);
}

// выделить пункт меню с номером sel
void itemMenu(int sel, bool activate)
{
	WORD itemAttributes;
	if (activate) itemAttributes = activeItemAttributes;
	else itemAttributes = inactiveItemAttributes;
	gotoxy(menu[sel].x, menu[sel].y);
	SetConsoleTextAttribute(hOut, itemAttributes);
	cout << menu[sel].str;
}

// скрыть/показать текстовый курсор в консоли
void showCursor(bool visible)
{
	CONSOLE_CURSOR_INFO ccInfo;
	ccInfo.bVisible = visible;
	ccInfo.dwSize = 20;
	SetConsoleCursorInfo(hOut, &ccInfo);
}