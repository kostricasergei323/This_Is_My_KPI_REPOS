#pragma once
void DrawMenu(); // ��������� ������� ������ ����
void gotoxy(int x, int y); // ������� ������� � ����� x,y
void itemMenu(int sel, bool activate); // �������� ����� ����
void cls(); // ������� �������
void getCursorPosition(void); // ��������� ��������� �������
void showCursor(bool visible);// ������/�������� ������