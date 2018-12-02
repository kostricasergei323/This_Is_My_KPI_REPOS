#define _CRT_SECURE_NO_WARNINGS
#include "Plane.h"

Plane::Plane() : Vehicle()
{
	this->Vehicle::Vehicle();
	this->flight_distance = 0.0;
	this->flight_weight = 0.0;
	this->flight_height = 0.0;
	this->aerodinamic = new char[50];
	assert(this->aerodinamic);
	strcpy(this->aerodinamic, "");
}

Plane::Plane(const Plane &exPlane)
{
	flight_distance = exPlane.flight_distance;
	flight_weight = exPlane.flight_weight;
	flight_height = exPlane.flight_height;
	aerodinamic = new char[strlen(exPlane.aerodinamic) + 1];
	strcpy(aerodinamic, exPlane.aerodinamic);
}

Plane::Plane(double sp, int wg, char* type, double fl_dis, double fl_wg, double fl_hg, const char aer[]) :Vehicle(sp, wg, type), flight_distance(fl_dis), flight_weight(fl_wg), flight_height(fl_hg)
{
	this->Vehicle::InitField();
	this->aerodinamic = new char[50];
	assert(this->aerodinamic);
	strcpy(this->aerodinamic, aer);
}

void Plane::InitField()
{
	this->Vehicle::InitField();
	this->flight_distance = (rand() % 600) / 2 + 1;
	this->flight_weight = (rand() % 20) / 2 + 1;
	this->flight_height = (rand() % 3000) / 2 + 1;
	int k = rand() % 10 + 2;
	this->aerodinamic = new char[k];
	for (int i = 0; i < k - 1; i++)
	{
		this->aerodinamic[i] = (char)(rand() % 26 + 65);
	}
	this->aerodinamic[k - 1] = '\0';
}

void Plane::Show() const
{
	this->Vehicle::Show();
	cout << "Plane:" << endl;
	cout << "Flight distance: " << this->flight_distance << endl;
	cout << "Flight weight: " << this->flight_weight << endl;
	cout << "Flight height: " << this->flight_height << endl;
	cout << "Aerodinamic: " << this->aerodinamic << endl << endl;
}

double Plane::GetFlightDistance()
{
	return this->flight_distance;
}

double Plane::GetFlightWeight()
{
	return this->flight_weight;
}

double Plane::GetFlightHeight()
{
	return this->flight_height;
}

char * Plane::GetAerodinamic()
{
	return aerodinamic;
}

ostream & operator<<(ostream &cout, Plane& obj)
{
	cout << "Vehicle:" << endl;
	cout << "----------------------------------" << endl;
	cout << "|       Speed     | " << setw(12) << obj.GetSpeed() << " |" << endl;
	cout << "|       Weight    | " << setw(12) << obj.GetWeight() << " |" << endl;
	cout << "| Type of Vehicle | " << setw(12) << obj.GetType() << " |" << endl;
	cout << "----------------------------------" << endl << endl;

	cout << "Plane:" << endl;
	cout << "----------------------------------" << endl;
	cout << "| Flight distance | " << setw(12) << obj.GetFlightDistance() << " |" << endl;
	cout << "|  Flight weight  |" << setw(12) << obj.GetFlightWeight() << " |" << endl;
	cout << "| Flight height   |" << setw(12) << obj.GetFlightHeight() << " |" << endl;
	cout << "| Aerodinamic     | " << setw(12) << obj.GetAerodinamic() << " |" << endl;
	cout << "----------------------------------" << endl << endl;
	return cout;
}

Plane::~Plane()
{
	cout << "Plane destructor is here -_-" << endl;
	Vehicle::~Vehicle();
	if (aerodinamic != 0)
	{
		delete[] aerodinamic;
		aerodinamic = 0;
	}
}