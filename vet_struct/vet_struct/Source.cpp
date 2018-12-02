#define N 7
#include <iostream>
#include <string>

using namespace std;

struct Metrix
{
  float weight;
  float height;
};

struct Cat
{
  Metrix met[N];
  string name;
};

struct Vet
{
  Cat *cats;
};

void SetData(Cat &cat);
void SetData(Cat *cats, const int &n);
void ShowData(const Cat &cat);
void ShowData(Cat *cats, const int &n);
float AverageWeight(Cat *cats, const int &pos, const int &n);
Cat *DeleteElem(Cat *cats, const int &pos, int &n);

int main()
{
  int n;
  int pos;
  float count;
  char choice;
  Vet *vet = new Vet;
  cout << "Enter quantity of cats:" << endl;
  cin >> n;
  vet->cats = new Cat[n];
  SetData(vet->cats, n);
  ShowData(vet->cats, n);

  do
  {
    cout << "Do you want to delete cat using position? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      do
      {
        cout << "Enter cat's position:" << endl;
        cin >> pos;
        if (pos > 0 && pos < n + 1)
        {
          vet->cats = DeleteElem(vet->cats, pos - 1, n);
          ShowData(vet->cats, n);
          break;
        }
        else cout << "Sorry, but you enter incorrect position" << endl;
      } while (true);
    }
  } while (choice == 'y' || choice == 'Y');
  do
  {
    cout << "Enter position of cat, to find out average weight for 7 days:" << endl;
    cin >> pos;
    if (pos > 0 && pos < n + 1)
    {
      count = AverageWeight(vet->cats, pos - 1, n);
      break;
    }
    else cout << "Sorry, but you enter incorrect position" << endl;
  } while (true);
  cout << "Average weight of Cat #" << pos << " = " << count << endl;
  system("pause");
  return 0;
}


void SetData(Cat &cat)
{
  cout << endl << "Enter cat's name:" << endl;
  cin >> cat.name;
  for (int i = 0; i < N; i++)
  {
    cout << "Enter weight of " << i + 1 << " day:" << endl;
    cin >> cat.met[i].weight;
    cout << "Enter height:" << endl;
    cin >> cat.met[i].height;
  }
}
void SetData(Cat *cats, const int &n)
{
  for (int i = 0; i < n; i++)
  {
    cout << endl << "Cat #" << i + 1 << endl;
    SetData(*(cats + i));
  }
}
void ShowData(const Cat &cat)
{
  cout << endl << "Name: " << cat.name << endl;
  for (int i = 0; i < N; i++)
  {
    cout << "Weight: " << cat.met[i].weight << endl;
    cout << "Height: " << cat.met[i].height << endl;
  }
  cout << endl;
}
void ShowData(Cat *cats, const int &n)
{
  for (int i = 0; i < n; i++)
  {
    ShowData(*(cats + i));
  }
}
float AverageWeight(Cat *cats, const int &pos, const int &n)
{
  float sum;
  sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += cats[pos].met[i].weight;
  }
  sum /= N;
  return sum;
}
Cat *DeleteElem(Cat *cats, const int &pos, int &n)
{
  n--;
  Cat *temp = new Cat[n];
  int i;
  i = 0;
  for (; i < pos; i++)
  {
    *(temp + i) = *(cats + i);
  }

  for (; i < n; i++)
  {
    *(temp + i) = *(cats + i);
  }
  delete[] cats;
  return temp;
}