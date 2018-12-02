#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"

Vehicle::Vehicle()
{
	this->speed = 0.0;
	this->weight = 0;
	this->type = new char[50];
	assert(this->type);
	strcpy(this->type, "");
}

Vehicle::Vehicle(double sp, int wg, char* t) :speed(sp), weight(wg)
{
	this->type = new char[strlen(t)+1];
	assert(this->type);
	strcpy(this->type, t);
}

double Vehicle::GetSpeed()
{
	return this->speed;
}

int Vehicle::GetWeight()
{
	return this->weight;
}

char * Vehicle::GetType()
{
	return this->type;
}

void Vehicle::InitField()
{
	this->speed = (rand() % 1000) / 2 + 1;
	this->weight = (rand() % 20) / 2 + 1;

	int k = rand() % 10 + 2;
	this->type = new char[k];
	for (int i = 0; i < k - 1; i++)
	{
		this->type[i] = (char)(rand() % 26 + 65);
	}
	this->type[k - 1] = '\0';
}

void Vehicle::Show() const
{
	cout << "Vehicle:" << endl;
	cout << "Speed: " << this->speed << endl;
	cout << "Weight: " << this->weight << endl;
	cout << "Type of Vehicle: " << this->type << endl << endl;
}

ostream & operator<<(ostream &cout,  Vehicle &obj)
{
	cout << "Vehicle:" << endl;
	cout << "----------------------------------" << endl;
	cout << "|       Speed     | " <<setw(12)<< obj.GetSpeed() << " |" << endl;
	cout << "|       Weight    | " << setw(12)<<obj.GetWeight() << " |" << endl;
	cout << "| Type of Vehicle | " << setw(12) << obj.GetType() << " |" << endl;
	cout << "----------------------------------" << endl << endl;
	return cout;
}

Vehicle::~Vehicle()
{
	cout << "Vehicle destructor is here :-)" << endl;
	if (type != nullptr)
	{
		delete[] type;
		type = 0;
	}
}
