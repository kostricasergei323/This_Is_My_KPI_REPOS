#include <fstream>
#include <cmath>
using namespace std;
double Area(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3)
{
  return fabs((x1 - x3)*(y2 - y3) - (x2 - x3)*(y1 - y3)) / 2;
}
bool OnLine(const double* Rect)
{
  double line1 = (Rect[0] - Rect[2])*(Rect[5] - Rect[3]) / (Rect[4] - Rect[2])+Rect[3];
  double line2 = (Rect[0] - Rect[2])*(Rect[9] - Rect[3]) / (Rect[9] - Rect[2])+Rect[3];
  if (line1 == line2 && line1 ==  Rect[1])
    return true;
  return false;
}
double AreaRect(const double* Rect)
{
  double a, b;
  a = sqrt((Rect[2] - Rect[4])*(Rect[2] - Rect[4]) + (Rect[3] - Rect[5])*(Rect[3] - Rect[5]));

  b = sqrt((Rect[2] - Rect[8])*(Rect[2] - Rect[8]) + (Rect[3] - Rect[9])*(Rect[3] - Rect[9]));
  return a * b;
}
double AreaTrin(const double* Rect)
{
  return Area(Rect[0], Rect[1], Rect[2], Rect[3], Rect[4], Rect[5]) + Area(Rect[0], Rect[1], Rect[2], Rect[3], Rect[8], Rect[9]) + Area(Rect[0], Rect[1], Rect[4], Rect[5], Rect[6], Rect[7]) + Area(Rect[0], Rect[1], Rect[6], Rect[7], Rect[8], Rect[9]);
}

int main()
{
  int N, sum = 0;
  ifstream in("INPUT.TXT");
  ofstream out("OUTPUT.TXT");
  in >> N;
  double **Rect = new double *[N]; // выделения памяти под N строк

  for (int i = 0; i<N; i++)
  {
    *(Rect + i) = new double[10]; // выделение памяти под столбцы
  }

  for (int i = 0; i<N; i++)
  {
    for (int j = 0; j<10; j++)
    {
      in >> Rect[i][j];
    }
  }

  for (int i = 0; i<N; i++)
  {
    if (AreaRect(Rect[i]) == AreaTrin(Rect[i])|| OnLine(Rect[i]))
    {
      sum++;
    }
  }
  out << sum;
  for (int i = 0; i<N; i++)
  {
    delete[] * (Rect + i); 
  }
  return 0;
}