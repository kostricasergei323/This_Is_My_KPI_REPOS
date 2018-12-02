#ifndef PLANE_H
#define PLANE_H
#include "Vehicle.h"

class Plane :public Vehicle
{
	friend ostream& operator<<(ostream &, Plane&);
private:
	double flight_distance;
	double flight_weight;
	double flight_height;
	char *aerodinamic;
public:
	Plane();
	Plane(const Plane &);
	Plane(double, int, char*, double, double, double, const char[]);
	void InitField();
	void Show() const;
	double GetFlightDistance();
	double GetFlightWeight();
	double GetFlightHeight();
	char *GetAerodinamic();


	virtual ~Plane();
};

#endif // PLANE_H