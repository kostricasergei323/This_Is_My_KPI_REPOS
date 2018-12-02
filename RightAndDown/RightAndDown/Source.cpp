#include <iostream>
#include <time.h>
using namespace std;
void FillRand(int **arr, int N, int M);
int MaxOfTwo(int N, int M);
void ArrOutput(int **arr, int N, int M);
int CalculateWay(int **arr, int i, int j, int N, int M);
int main()
{
  int N, M;
  cout << "Enter size of Array: " << endl;
  cin >> N >> M;
  int **arr = new int*[N];
  for (int i = 0; i < N; i++)
  {
    arr[i] = new int[M];
  }
 // FillRand(arr, N, M);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cout << "Enter a[" << i << "][" << j << "]=";
      cin >> arr[i][j];
    }
  }
  arr[N - 1][M - 1] = 0;
  cout << endl << "ARRAY:" << endl; ArrOutput(arr, N, M);
  cout << endl << "Result = " << CalculateWay(arr, 0, 0, N, M) << endl;
  system("pause");
  return 0;
}
int MaxOfTwo(int N, int M)
{
  return N < M ? N : M;
}
void FillRand(int **arr, int N, int M)
{
  srand(time(NULL));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      arr[i][j] = rand() % MaxOfTwo(N, M) + 1;
    }
  }
}
void ArrOutput(int **arr, int N, int M)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}
int CalculateWay(int **arr, int i, int j, int N, int M)
{
  static int way = 0;
  while (arr[i][j])
  {
    if (arr[i][j] < M - j)
    {
      way = CalculateWay(arr, i, j + arr[i][j], N, M);
    }
    if (arr[i][j] < N - i)
    {
      return  way = CalculateWay(arr, i + arr[i][j], j, N, M);
    }
    break;
  }
  if (arr[i][j] == 0)
  {
    return ++way;
  }
  return way;
}