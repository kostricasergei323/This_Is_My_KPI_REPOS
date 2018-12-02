#ifndef AUTO_IN_PLANE_H
#define AUTO_IN_PLANE_H
#include "Auto.h"
#include "Plane.h"
class AutoInPlane :public Auto, public Plane
{
	friend ostream& operator<<(ostream &, AutoInPlane&);
public:
	AutoInPlane();
	AutoInPlane(Plane&, Auto&);
	void InitField();
	void Show() const;


	virtual ~AutoInPlane();
};

#endif // AUTO_IN_PLANE_H