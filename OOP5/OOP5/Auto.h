#ifndef AUTO_H
#define AUTO_H
#include "Vehicle.h"

class Auto :public Vehicle
{
	friend ostream& operator<<(ostream &, Auto&);
private:
	double torque;
	double breaking_distance;
	double transmission;
	char *walk_part;
public:
	Auto();
	Auto(const Auto&);
	Auto(double, int, char*, double, double, double, char*);
	void InitField();
	void Show() const;
	double GetTorque();
	double GetBreakingDistance();
	double GetTransmission();
	char *GetWalkPart();


	virtual ~Auto();
};

#endif // AUTO_H