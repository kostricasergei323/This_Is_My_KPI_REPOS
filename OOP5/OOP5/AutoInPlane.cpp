#include "AutoInPlane.h"

AutoInPlane::AutoInPlane() : Auto(), Plane()
{

}

AutoInPlane::AutoInPlane(Plane &Sy, Auto &Ford) : Plane(Sy), Auto(Ford) {}

void AutoInPlane::InitField()
{
	Auto::InitField();
	Plane::InitField();
}

void AutoInPlane::Show() const
{
	Auto::Show();
	Plane::Show();
}

ostream & operator<<(ostream &cout, AutoInPlane &obj)
{
	cout << "Vehicle:" << endl;
	cout << "----------------------------------" << endl;
	cout << "|       Speed     | " << setw(12) << obj.Auto::GetSpeed() << " |" << endl;
	cout << "|       Weight    | " << setw(12) << obj.Auto::GetWeight() << " |" << endl;
	cout << "| Type of Vehicle | " << setw(12) << obj.Auto::GetType() << " |" << endl;
	cout << "----------------------------------" << endl << endl;

	cout << "Auto:" << endl;
	cout << "-----------------------------------" << endl;
	cout << "|       Torque      | " << setw(11) << obj.GetTorque() << " |" << endl;
	cout << "| Breaking distance | " << setw(11) << obj.GetBreakingDistance() << " |" << endl;
	cout << "|    Transmission   | " << setw(11) << obj.GetTransmission() << " |" << endl;
	cout << "|      Walk part    | " << setw(11) << obj.GetWalkPart() << " |" << endl;
	cout << "-----------------------------------" << endl << endl;

	cout << "Vehicle:" << endl;
	cout << "----------------------------------" << endl;
	cout << "|       Speed     | " << setw(12) << obj.Plane::GetSpeed() << " |" << endl;
	cout << "|       Weight    | " << setw(12) << obj.Plane::GetWeight() << " |" << endl;
	cout << "| Type of Vehicle | " << setw(12) << obj.Plane::GetType() << " |" << endl;
	cout << "----------------------------------" << endl << endl;

	cout << "Plane:" << endl;
	cout << "----------------------------------" << endl;
	cout << "| Flight distance | " << setw(12) << obj.GetFlightDistance() << " |" << endl;
	cout << "|  Flight weight  |" << setw(13) << obj.GetFlightWeight() << " |" << endl;
	cout << "| Flight height   |" << setw(13) << obj.GetFlightHeight() << " |" << endl;
	cout << "| Aerodinamic     | " << setw(12) << obj.GetAerodinamic() << " |" << endl;
	cout << "----------------------------------" << endl << endl;
	return cout;
}

AutoInPlane::~AutoInPlane()
{
	cout << "This is AutoInPlane destructor _-_" << endl;
	Auto::~Auto();
	Plane::~Plane();
}
