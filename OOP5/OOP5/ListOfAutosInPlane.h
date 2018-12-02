#ifndef LIST_OF_AUTOS_IN_PLANE_H
#define LIST_OF_AUTOS_IN_PLANE_H
#include "AutoInPlane.h"
class ListOfAutosInPlane : public AutoInPlane
{
	friend ostream& operator<<(ostream &, ListOfAutosInPlane&);
private:
	AutoInPlane * arr;
	int size;
public:
	ListOfAutosInPlane();
	ListOfAutosInPlane(int);
	void InitField();
	void Show() const;
	AutoInPlane& operator[](int);
	AutoInPlane* GetArr();
	int GetSize();


	virtual ~ListOfAutosInPlane();
};

#endif // LIST_OF_AUTOS_IN_PLANE_H
