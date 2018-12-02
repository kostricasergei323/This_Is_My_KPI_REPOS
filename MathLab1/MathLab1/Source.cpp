/**********************************************************************************************************/
/*** 									                ����������� ������ �1 										                        ***/
/*** 										                   ���i��� �10		 										                          ***/
/*** 								  		                   	� �����		 											                          ***/
/*** 								                  		�������i ������ 										                        	***/
/*** 							              		���������� ����ֲ�������� ��Ĳ�								                     	***/
/*** 							                    				��������: 								 				                        ***/
/***	��� ���� f(x) = � (a(i)). ��������� ���� ��������� �������� ��� � � [0, 1] � ������ h = 0.05.   	***/
/***	���������� ���������, ���� | ai | < e = 0.001 ��� ���� ���������� ����� ����. ������ ����� 	    ***/
/***	�������� ���� f���(�). ������� ������� �������� N(x, e), ��� ���� ���� ��������� ������� e.	  ***/
/***	���������� �������. ���������� �� ������ ��� ������� ������� y = f(x), y = f���(x).		        	***/
/***	��� � = 0.5 ���������� ������ �i(i).														                                 	***/
/***																�������:	�������� ����� ��-71                                   	***/
/***																�����i���:	�i����� �. �.			                                      ***/
/**********************************************************************************************************/

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

HDC hdc = GetDC(GetConsoleWindow());

int xO = 1000, yO = 675; // ������� ��������� ����i�� 1
int xl = 200, yl = 930;  // ������� ��������� ����i�� 2
int Scalex = 450;		     // ������� ������������� x
int Scaley = 100;		     // ������� ������������� y

void Graph();             // �����i� ��������� ������������ �i��� ����i�i�

int main() {

  double x = 0.05;
  double h = 0.05;											                          // ����
  double eps = 0.001;										                        	// ����i��� ���������

  double prev;											                            	// ��������i� ������� ����
  double cur;												                            	// �������� ������� ����
  double sum;													                            // �������� ���� ����
  double a = exp(2);
  int n;														                              // �i���i��� i�����i�

  Graph();													                              // �����i� ��������� ������������ �i��� ����i�i�
  SelectObject(hdc, CreatePen(PS_SOLID, 5, RGB(125, 0, 250)));    // ���i� ������ �������� ����������� �������
  MoveToEx(hdc, xO, yO - Scaley, NULL);								            // �����i� �� ������� ��������� ����i�� 1

                                                                  // ���i� ����i�� �����ii tan(x)
  for (double x = 0; x < 1; x += 0.01)
  {
    LineTo(hdc, xO + Scalex * x, yO - pow(a, x) * Scaley);
  }

  SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(125, 0, 0)));	     // ���i� ������ �������� ��������� �������
  MoveToEx(hdc, xO, yO - Scaley, NULL);								             // �����i� �� ������� ��������� ����i�� 1

  // ���i� ���������� ������i
  cout << fixed << "      x    |     f(x)    |    ft(x)     |       %        |	n" << endl << endl;

  // ���i� ����i� ������i i ����i�� ���� ����
  do
  {
    n = 0;													                                              // �������� �������� i�����i�
    sum = 1;												                                              // �������� ���� ����				
    prev = cur = 1;							                                                	// ��������i� ������ �������

    //���������� ���� ���� �� ����������� ��������, ���������� ���������, ���� ������i ��� ����� ����� ���i����
    while ((fabs(cur) > eps || fabs(prev) > eps)) {
      n++;
      prev = cur;											                                            // �����'���������� ������������ �������� ���� ����
      cur *= x * log(a) / n;
      sum += cur;											                                            // ������� ��������� �������� �� ����
    }
    
    // ���i� ���������i� � �������
    cout << "    " << setw(3) << setprecision(2) << x << setw(15) << setprecision(6) << sum << setw(14) << pow(a, x)
      << "	   " << setw(9) << (sum - pow(a, x)) / sum * 100 << "%";
    cout << setw(12) << n << endl; 

    // ���i� ����i�� ���� ����
    LineTo(hdc, xO + Scalex * x, yO - sum * Scaley);

    x += h;
  } while (x <= 1.01);

  // ���i� ����i�� ���������i �������i� ���� ���� �i� i�������� ��� x = 0.5
  SelectObject(hdc, CreatePen(PS_SOLID, 7, RGB(0, 20, 250)));	  // ���i� ������ �������� ������� �������
  cur = 1;											                  	            // ������� ������i�
  MoveToEx(hdc, xl, yl, NULL);							                  	// �����i� �� ������� ��������� ����i�� 2
  for (int i = 1; i < 8; i++)
  {
    cur *= x * log(a) / n;
    LineTo(hdc, xl + i * 80, yl - cur * 400);				            // ���i� ����i��
  }

  getchar();	                                                  // �������� ������
  return 0;
}

// �����i� ��������� ������������ �i��� ����i�i�
void Graph() {
  SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 0)));
  // ���i� ����i�� 1
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

  // ���i� ����i�� 2
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