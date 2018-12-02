#define _CRT_SECURE_NO_WARNINGS
#include "Auto.h"

Auto::Auto() : Vehicle()
{
	this->Vehicle::Vehicle();
	this->torque = 0.0;
	this->breaking_distance = 0.0;
	this->transmission = 0.0;
	this->walk_part = new char[50];
	assert(this->walk_part);
	strcpy(this->walk_part, "");
}

Auto::Auto(const Auto &exAuto)
{
	torque = exAuto.torque;
	breaking_distance = exAuto.breaking_distance;
	transmission = exAuto.transmission;
	walk_part = new char[strlen(exAuto.walk_part) + 1];
	strcpy(walk_part, exAuto.walk_part);
}

Auto::Auto(double sp, int wg, char* type, double torq, double br_dis, double trans, char* w_p) :Vehicle(sp, wg, type), torque(torq), breaking_distance(br_dis), transmission(trans)
{
	this->Vehicle::InitField();
	this->walk_part = new char[strlen(w_p)+1];
	assert(this->walk_part);
	strcpy(this->walk_part, w_p);
}

void Auto::InitField()
{
	this->Vehicle::InitField();
	this->torque = (rand() % 20) / 2 + 1;
	this->breaking_distance = (rand() % 300) / 2 + 1;
	this->transmission = (rand() % 20) / 2 + 1;
	int k = rand() % 10 + 2;
	this->walk_part = new char[k];
	for (int i = 0; i < k - 1; i++)
	{
		this->walk_part[i] = (char)(rand() % 26 + 65);
	}
	this->walk_part[k - 1] = '\0';
}

void Auto::Show() const
{
	this->Vehicle::Show();
	cout << "Auto:" << endl;
	cout << "Torque: " << this->torque << endl;
	cout << "Breaking distance: " << this->breaking_distance << endl;
	cout << "Transmission: " << this->transmission << endl;
	cout << "Walk part: " << this->walk_part << endl << endl;
}

double Auto::GetTorque()
{
	return this->torque;
}

double Auto::GetBreakingDistance()
{
	return this->breaking_distance;
}

double Auto::GetTransmission()
{
	return this->transmission;
}

char * Auto::GetWalkPart()
{
	return this->walk_part;
}

ostream & operator<<(ostream &cout, Auto &obj)
{
	cout << "Vehicle:" << endl;
	cout << "----------------------------------" << endl;
	cout << "|       Speed     | " << setw(12) << obj.GetSpeed() << " |" << endl;
	cout << "|       Weight    | " << setw(12) << obj.GetWeight() << " |" << endl;
	cout << "| Type of Vehicle | " << setw(12) << obj.GetType() << " |" << endl;
	cout << "----------------------------------" << endl << endl;

	cout << "Auto:" << endl;
	cout << "-----------------------------------" << endl;
	cout << "|       Torque      | " << setw(11) << obj.GetTorque() << " |" << endl;
	cout << "| Breaking distance | " << setw(11) << obj.GetBreakingDistance() << " |" << endl;
	cout << "|    Transmission   | " << setw(11) << obj.GetTransmission() << " |" << endl;
	cout << "|      Walk part    | " << setw(11) << obj.GetWalkPart() << " |" << endl;
	cout << "-----------------------------------" << endl << endl;
	return cout;
}

Auto::~Auto()
{
	cout << "Auto destructor is here xD" << endl;
	Vehicle::~Vehicle();
	if (walk_part != 0)
	{
		delete[] walk_part;
		walk_part = 0;
	}
}