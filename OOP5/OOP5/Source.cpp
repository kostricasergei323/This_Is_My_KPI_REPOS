#include <iostream>
#include "Depo.h"
using namespace std;
template <class T>
double CalculateAvarageSpeed(T*, int);

int main()
{
	srand(time(NULL));
	ListOfAutosInPlane list_1(3);
	list_1.InitField();
	cout << list_1;
	Auto* Park = new Auto[10];
	for (int i = 0; i < 10; i++)
	{
		Park[i].InitField();
		cout << "Auto #" << i + 1 << endl;
		Park[i].Show();
	}
	cout << "Avarage speed of Autos = " << CalculateAvarageSpeed<Auto>(Park, 10) << endl;

	Depo<Vehicle, Auto, Plane, AutoInPlane> depo(3);
	depo.Print(3);
	system("pause");
  return 0;
}

template <class T>
double CalculateAvarageSpeed(T* array, int size)
{
	double avarage = 0;
	for (int i = 0; i < size; i++)
	{
		avarage += array[i].GetSpeed();
	}
	return avarage / size;
}