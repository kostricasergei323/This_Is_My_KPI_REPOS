#define ROW 3
#include <iostream>
#include <time.h>
using namespace std;
void RandFill(int **arr, int size);
void OutputMatrix(int **arr, int size1, int size2);
int CompressMatrix(int **arr, int **compact_arr, int n);
void SortMatrix(int **arr, int size);
int main()
{
  int **arr, **compact_arr;
  int size1, size2;
  cout << "Enter size of matrix:" << endl;
  cin >> size1;
  arr = new int*[size1];
  compact_arr = new int*[ROW];
  for (int i = 0; i < size1; i++)
  {
    *(arr + i) = new int[size1];
  }
  RandFill(arr, size1);
  cout << "Not compacted matrix:" << endl;
  OutputMatrix(arr, size1, size1);
  size2 = CompressMatrix(arr, compact_arr, size1);
  cout << "Compacted matrix:" << endl;
  OutputMatrix(compact_arr, ROW, size2);
  SortMatrix(arr, size1);
  cout << "Not compacted matrix:" << endl;
  OutputMatrix(arr, size1, size1);
  size2 = CompressMatrix(arr, compact_arr, size1);
  cout << "Compacted matrix:" << endl;
  OutputMatrix(compact_arr, ROW, size2);
  system("pause");
  return 0;
}

void RandFill(int **arr, int size)
{
  srand(time(NULL));
  int k; 
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      k = rand() % 10;
      if (k > 5)
      {
        arr[i][j] = k;
      }
      else arr[i][j] = 0;
    }
  }
}
void OutputMatrix(int **arr, int size1, int size2)
{
  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}

int CompressMatrix(int **arr, int **compact_arr, int n)
{
  int k;
  int size2;
  size2 = 0;
  k = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] != 0)
      {
        size2++;
      }
    }
  }
  for (int i = 0; i < ROW; i++)
  {
    compact_arr[i] = new int[size2];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] != 0)
      {
        compact_arr[0][k] = i;
        compact_arr[1][k] = j;
        compact_arr[2][k] = arr[i][j];
        k++;
      }
    }
  }
  return size2;
}
void SortMatrix(int **arr, int size)
{
  if (size >= 5)
  {
    for (int i = 0; i < size; i++)
    {
      int k = 5;
      int m = 0;
      int l = 0;
      for (int j = 0; j < size/5*2; j++)
      {
        int temp;
        temp = arr[i][m];
        arr[i][m] = arr[i][k - 1 - l];
        arr[i][k - 1 - l] = temp;
        if(j!=0 && (j+1)%2==0 &&k+5<=size)
        {
          m += 4;
          k += 5;
          l = 0;
          continue;
        }
        l++;
        m++;
      }
    }
  }
}