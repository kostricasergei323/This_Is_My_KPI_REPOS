#pragma once
void DrawMenu(); // Отрисовка верхней панели меню
void gotoxy(int x, int y); // Перевод курсора в точку x,y
void itemMenu(int sel, bool activate); // Выделить пункт меню
void cls(); // Очистка консоли
void getCursorPosition(void); // Запомнить положение курсора
void showCursor(bool visible);// скрыть/показать курсор