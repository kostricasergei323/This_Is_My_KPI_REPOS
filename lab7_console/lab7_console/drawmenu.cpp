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

// ������� ����
typedef struct { 
	int x, y;	 // ����������
	char *str;   // ���
	FUN f;	     // ����������� �������
} ITEM;

HANDLE hOut;
CONSOLE_SCREEN_BUFFER_INFO csbInfo;
SMALL_RECT consolRect; // ���� ����
COORD curspos = { 0,1 }; // ���������� �������
WORD wo�kWindowAttributes = 240; // ���� ���� 158
WORD inactiveItemAttributes = 31; // ���� ����������� ������ ����
WORD activeItemAttributes = 120; // ���� ���������� ������ ����
enum menuitems { M_GRAPH, M_ART, M_EXIT };
extern const int numMenu = 3; //���������� ������� ����

char line1[9] = " ������ ";
char line2[10] = " ������� ";
char line4[8] = " ����� ";

//��������� (x,y), ���������, ��������� �� �������
ITEM menu[numMenu] = { 
	{ 0, 0, line1, Graph },
	{ 8, 0, line2, Art },
	{ 17, 0, line4, Exit }
};

void DrawMenu() { //���������� ����
	menuitems sel = M_GRAPH; // ����� �������� ������ ����
	SetConsoleTextAttribute(hOut, inactiveItemAttributes);
	string s(90, ' '); cout << s.c_str(); //������ ��� ������ ����
	for (int i = 0; i < numMenu; i++) { //���������� ��������� ������� ����
		gotoxy(menu[i].x, menu[i].y);
		cout << menu[i].str;
	}
	itemMenu(sel, true); // �������� ����� ����
	fflush(stdin); //�������� ����� ����������
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
				gotoxy(curspos.X, curspos.Y); // ���������� ������ �� ������ ���� � ������� �������
				SetConsoleTextAttribute(hOut, wo�kWindowAttributes); // ���������� ���� ������� ���������
				showCursor(true);
				switch (sel)
				{
				case M_GRAPH:
					Graph();
					getCursorPosition(); // ��������� ��������� �������
					break;
				case M_ART:
					Art();
					getCursorPosition(); // ��������� ��������� �������
					break;
				case M_EXIT:
					int resp;
					cout << "�� �������, ��� ������ ����� �� ��������� ? (y / n) ? ";
						resp = getchar();
					if (resp == 'y' || resp == 'Y')
					{
						gotoxy(0, 0); 
						cls(); 
						exit(0);
					}
					getCursorPosition(); // ��������� ��������� �������, ���� �������� �����
					break;
				}
				fflush(stdin); //�������� ����� ����������
				gotoxy(menu[sel].x, menu[sel].y); // ������ � ������� ����� ����
				showCursor(false);
				break;
			case 120: case 88: case 27: // ����� �� ������� ESC, x, X
				gotoxy(0, 0);
				cls();
				exit(0); //���������� ���������
			}
		}
		Sleep(50);
	}
}

// ��������� ������ � ����� x,y
void gotoxy(int x, int y)
{
	COORD cursorPos = { x, y };
	SetConsoleCursorPosition(hOut, cursorPos);
}

// ������ �������� ��������� ���������� ������� � ���������� ���������� curspos
void getCursorPosition(void)
{
	GetConsoleScreenBufferInfo(hOut, &csbInfo);
	curspos = csbInfo.dwCursorPosition;
}

// ������� ������
void cls()
{
	string s(100, ' ');
	SetConsoleTextAttribute(hOut, wo�kWindowAttributes);
	gotoxy(0, 1);
 
	for (int i = 1; i < 26; i++) {
		cout << s.c_str(); // ������ ��� ������ ����
	}
	gotoxy(0, 0);
}

// �������� ����� ���� � ������� sel
void itemMenu(int sel, bool activate)
{
	WORD itemAttributes;
	if (activate) itemAttributes = activeItemAttributes;
	else itemAttributes = inactiveItemAttributes;
	gotoxy(menu[sel].x, menu[sel].y);
	SetConsoleTextAttribute(hOut, itemAttributes);
	cout << menu[sel].str;
}

// ������/�������� ��������� ������ � �������
void showCursor(bool visible)
{
	CONSOLE_CURSOR_INFO ccInfo;
	ccInfo.bVisible = visible;
	ccInfo.dwSize = 20;
	SetConsoleCursorInfo(hOut, &ccInfo);
}