#include "ListOfAutosInPlane.h"

ListOfAutosInPlane::ListOfAutosInPlane()
{
	arr = 0;
}

ListOfAutosInPlane::ListOfAutosInPlane(int s) :size(s)
{
	if (size > 0 && size < UINT_MAX)
	{
		arr = new AutoInPlane[size];
	}
	else arr = 0;
	this->InitField();
}

void ListOfAutosInPlane::InitField()
{
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i].InitField();
	}
}

void ListOfAutosInPlane::Show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << "Auto in Plane #" << i + 1 << endl;
		this->arr[i].Show();
		cout << endl;
	}
}

AutoInPlane& ListOfAutosInPlane::operator[](int index)
{
	if (index > 0 && index < size)
	{
		return arr[index];
	}
	else cout << "INDEX ERROR" << endl;
	return arr[0];
}

AutoInPlane * ListOfAutosInPlane::GetArr()
{
	return this->arr;
}

int ListOfAutosInPlane::GetSize()
{
	return this->size;
}

ostream & operator<<(ostream &cout, ListOfAutosInPlane &obj)
{
	for (int i = 0; i < obj.GetSize(); i++)
	{
		cout << obj.GetArr()[i] << endl;
	}
	return cout;
}

ListOfAutosInPlane::~ListOfAutosInPlane()
{
	cout << "This is the ListOfAutosInPlane destructor :)" << endl;
	for (int i = 0; i < this->size; i++)
	{
		arr[i].~AutoInPlane();
	}
	system("pause");
}
