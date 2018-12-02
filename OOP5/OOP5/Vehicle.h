#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;

class Vehicle
{
	friend ostream& operator<<(ostream &,  Vehicle &);
private:
	double speed;
	int weight;
	char *type;
public:
	virtual void InitField();
	virtual void Show() const;
	Vehicle();
	Vehicle(double, int, char*);
	double GetSpeed();
	int GetWeight();
	char* GetType();

	virtual ~Vehicle();
};

#endif // !VEHICLE_H