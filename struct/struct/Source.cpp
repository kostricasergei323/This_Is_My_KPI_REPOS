#include <iostream>
using namespace std;

struct Name
{
  char name[30];
  char surname[30];
  char secondname[30];
};
struct Birthday
{
  int year;
  int month;
  int day;
};
struct Adress
{
  char country[30];
  char city[20];
  char street[30];
};
struct Metrix
{
  int height;
  int weight;
};
struct Human
{
  Name name;
  Birthday date;
  Adress adress;
  Metrix metrix;
  int age;
};
void setData(Human &Obj)
{
  cout << "Enter name: ";
  cin.getline(Obj.name.name, 30);
  fflush(stdin);
  cout << "Enter surname: ";
  cin.getline(Obj.name.surname, 30);
  fflush(stdin);
  cout << "Enter secondname: ";
  cin.getline(Obj.name.secondname, 30);
  fflush(stdin);
  cout << "Enter year of birth: ";
  cin >> Obj.date.year;
  fflush(stdin);
  cout << "Enter month of birth: ";
  cin >> Obj.date.month;
  fflush(stdin);
  cout << "Enter day of birth: ";
  cin >> Obj.date.day;
  fflush(stdin);
  cout << "Enter name of your country: ";
  cin >> Obj.adress.country;
  fflush(stdin);
  cout << "Enter name of your city: ";
  cin >> Obj.adress.city;
  fflush(stdin);
  cout << "Enter name of your street: ";
  cin >> Obj.adress.street;
  fflush(stdin);
  cout << "Enter your height: ";
  cin >> Obj.metrix.height;
  fflush(stdin);
  cout << "Enter your weight: ";
  cin >> Obj.metrix.weight;
  fflush(stdin);
  cout << "Enter your age: ";
  cin >> Obj.age;
  while (cin.get() != '\n');
}

Human *addStructure(Human *Obj, int &n, const int index)
{
  n++;
  Human *temp = new Human[n];
  for (int i = 0; i < index; i++)
  {
    temp[i] = Obj[i];
  }
  while (cin.get() != '\n');
  setData(temp[index]);
  for (int i = index + 1; i < n - 1; i++)
  {
    temp[i] = Obj[i];
  }
  delete[] Obj;
  return temp;
}
Human *deleteStructure(Human *Obj, int &n, const int index)
{
  n--;
  Human *temp = new Human[n];
  for (int i = index; i < n; i++)
  {
    Obj[i] = Obj[i + 1];
  }
  for (int i = 0; i < n; i++)
  {
    temp[i] = Obj[i];
  }
  delete[] Obj;
  return temp;
}
void showData(Human *Obj, const int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << i + 1 << endl;
    cout << "Full name: " << Obj[i].name.name << ' ' << Obj[i].name.surname << ' ' << Obj[i].name.secondname << endl;
    cout << "Date if birth: " << Obj[i].date.day << '.' << Obj[i].date.month << '.' << Obj[i].date.year << endl;
    cout << "Adress: " << Obj[i].adress.country << ", " << Obj[i].adress.city << ", " << Obj[i].adress.street << endl;
    cout << "Metrix: " << Obj[i].metrix.height << "cm, " << Obj[i].metrix.weight << "kg" << endl;
    cout << "Age: " << Obj[i].age << endl;
    cout << endl;
  }
}
int main()
{
  int n = 2;
  int index;
  Human *people = new Human[n];
  for (int i = 0; i < n; i++)
  {
    setData(people[i]);
    cout << endl;
  }
  showData(people, n);
  cout << "Enter index of element to input: ";
  cin >> index;

  people = addStructure(people, n, index-1);
  showData(people, n);
  do
  {
    cout << "Enter index of element to delete: ";
    cin >> index;
    if (index<0 && index>n)
    {
      cout << "ERROR!!!" << endl;
    }
  } while (index<0 && index>n);
  
  people = deleteStructure(people, n, index-1);
  showData(people, n);
  system("pause");
  return 0;
}