#ifndef DEPO_H
#define DEPO_H
#include "ListOfAutosInPlane.h"

using namespace std;

template <class T> T* NewVehicle(T*, const unsigned);
template <class T> void InTXT(ifstream &, T*, unsigned);
template <class T> void OutTXT(ofstream &, T*, unsigned);
template <class T> void InBIN(ifstream &, T*, unsigned);
template <class T> void OutBIN(ofstream &, T*, unsigned);
template <class T> void Show(T*, unsigned);

template <class VEHICLE, class AUTO, class PLANE, class AUTOINPLANE>
class Depo
{
private:
	VEHICLE* vehicles;
	AUTO* autos;
	PLANE* planes;
	AUTOINPLANE* AutosInPlanes;
	unsigned size;
public:
	Depo();
	Depo(unsigned);
	void Print(unsigned);
	int ToTXT(char*, unsigned);
	int ToBIN(char*, unsigned);
	int FromBIN(char*, unsigned);
	int FromTXT(char*, unsigned);

	~Depo();
};



template<class VEHICLE, class AUTO, class PLANE, class AUTOINPLANE>
inline Depo<VEHICLE, AUTO, PLANE, AUTOINPLANE>::Depo()
{
	vehicles = new VEHICLE;
	vehicles->InitField();
	autos = new AUTO;
	autos->InitField();
	planes = new PLANE;
	planes->InitField();
	AutosInPlanes = new AUTOINPLANE;
	AutosInPlanes->InitField();
}

template<class VEHICLE, class AUTO, class PLANE, class AUTOINPLANE>
inline Depo<VEHICLE, AUTO, PLANE, AUTOINPLANE>::Depo(unsigned size): size(size)
{
	vehicles = new VEHICLE[size];
	autos = new AUTO[size];
	planes = new PLANE[size];
	AutosInPlanes = new AUTOINPLANE[size];

	for (unsigned i = 0; i < size; i++)
	{
		vehicles[i].InitField();
		autos[i].InitField();
		planes[i].InitField();
		AutosInPlanes[i].InitField();
	}
	vehicles = NewVehicle(vehicles, size);
	autos = NewVehicle(autos, size);
	planes = NewVehicle(planes, size);
	AutosInPlanes = NewVehicle(AutosInPlanes, size);
	size++;
}

template<class VEHICLE, class AUTO, class PLANE, class AUTOINPLANE>
inline void Depo<VEHICLE, AUTO, PLANE, AUTOINPLANE>::Print(unsigned size)
{
	Show(vehicles, size);
	Show(autos, size);
	Show(planes, size);
	Show(AutosInPlanes, size);
}

template<class VEHICLE, class AUTO, class PLANE, class AUTOINPLANE>
inline int Depo<VEHICLE, AUTO, PLANE, AUTOINPLANE>::ToTXT(char *path, unsigned size)
{
	ofstream out(path, ios::out);
	if (!out)
	{
		cout << "Failed to open file!" << endl;
		out.close();
		return -1;
	}
	OutTXT(out, vehicles, size);
	OutTXT(out, autos, size);
	OutTXT(out, planes, size);
	OutTXT(out, AutosInPlanes, size);

	out.close();
	return 0;
}

template<class VEHICLE, class AUTO, class PLANE, class AUTOINPLANE>
inline int Depo<VEHICLE, AUTO, PLANE, AUTOINPLANE>::ToBIN(char *path, unsigned size)
{
	ofstream out(path, ios::binary | ios::out);
	if (!out)
	{
		cout << "Failed to open file!" << endl;
		out.close();
		return -1;
	}

	OutBIN(out, vehicles, size);
	OutBIN(out, autos, size);
	OutBIN(out, planes, size);
	OutBIN(out, AutosInPlanes, size);

	out.close();
	return 0;
}

template<class VEHICLE, class AUTO, class PLANE, class AUTOINPLANE>
inline int Depo<VEHICLE, AUTO, PLANE, AUTOINPLANE>::FromBIN(char *path, unsigned size)
{
	ifstream in(path, ios::binary | ios::in);
	if (!in)
	{
		cout << "Failed to open file!" << endl;
		in.close();
		return - 1;
	}

	InBIN(in, vehicles, size);
	InBIN(in, autos, size);
	InBIN(in, planes, size);
	InBIN(in, AutosInPlanes, size);

	in.close();
	return 0;
}

template<class VEHICLE, class AUTO, class PLANE, class AUTOINPLANE>
inline int Depo<VEHICLE, AUTO, PLANE, AUTOINPLANE>::FromTXT(char *path, unsigned size)
{
	ifstream in(path, ios::in);
	if (!in)
	{
		cout << "Failed to open file!" << endl;
		in.close();
		return -1;
	}

	InTXT(in, vehicles, size);
	InTXT(in, autos, size);
	InTXT(in, planes, size);
	InTXT(in, AutosInPlanes, size);

	in.close();
	return 0;
}

template<class T>
inline T* NewVehicle(T *arr, const unsigned size)
{
	T *temp = new T[size+1];
	assert(temp);
	for (unsigned i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}

	temp[size].InitField();
	arr = new T[size+1];
	arr = temp;
	return arr;
}

template<class T>
inline void InTXT(ifstream &in, T *arr, unsigned size)
{
	unsigned count = 0;
	in.read(reinterpret_cast<char*>(T), sizeof(T));
	T *temp = new T[in.gcount()];
	T *temp1 = new T[size];

	for (unsigned i = 0; i < size; i++)
	{
		temp1[i] = arr[i];
	}
	delete[] arr;

	size += in.gcount();
	while (!in.eof())
	{
		in >> temp[count];
		count++;
	}
	
	arr = new T[size];
	for (unsigned i = 0; i < size; i++)
	{
		if (i < size - count)
		{
			arr[i] = temp1[i];
		}
		else arr[i] = temp[i];
	}
	delete[] temp;
	temp = NULL;
	delete[] temp1;
	temp1 = NULL;
}

template<class T>
inline void OutTXT(ofstream &out, T *arr, unsigned size)
{
	for (unsigned i = 0; i < size; i++)
	{
		out << setw(3) << i + 1 << endl << arr[i] << endl;
	}
}

template<class T>
inline void InBIN(ifstream &in, T *arr, unsigned size)
{
	for (unsigned i = 0; i < size; i++)
	{
		in.read((char*)arr[i], sizeof(T));
	}
}

template<class T>
inline void OutBIN(ofstream &out, T *arr, unsigned size)
{
	for (unsigned i = 0; i < size; i++)
	{
		out.write((char*)arr[i], sizeof(T));
	}
}

template<class T>
inline void Show(T *arr, unsigned size)
{
	for (unsigned i = 0; i < size; i++)
	{
		cout << i + 1 << '.' << endl;
		cout << arr[i] << endl;
	}
}

template<class VEHICLE, class AUTO, class PLANE, class AUTOINPLANE>
inline Depo<VEHICLE, AUTO, PLANE, AUTOINPLANE>::~Depo()
{
	cout << "This is Depo destructor xD" << endl;
	if (vehicles && autos && planes && AutosInPlanes)
	{
		for (unsigned i = 0; i < this->size; i++)
		{
			AutosInPlanes[i].~AUTOINPLANE();
		}
	}
}

#endif // !DEPO_H