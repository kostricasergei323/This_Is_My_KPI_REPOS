#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

using namespace std;

int **input(int *n, int *m);
void fillRand(int **arr, int n, int m);
void output(int **arr, int n, int m);
int **blur(int **arr, int n, int m, unsigned int *start_time);

#define LIM 10

int main()
{
  int **arr;
  int n;
  int m;

  system("chcp 1251");
  system("cls");
  arr = input(&n, &m);
  unsigned int start_time;
  arr = blur(arr, n, m, &start_time);
  unsigned int end_time = clock();
  cout << "Work time:  " << (end_time - start_time) / 1000. << " second\n";
  //	cout << "\nProcessed matrix: \n";
  //	output(arr, n, m);
  system("pause");
  return 0;
}
int **input(int *n, int *m)
{
  do
  {
    cout << "Enter size of matrix: ";
    cin >> *n;
    cin >> *m;
    fflush(stdin);
    if (*n < 1 || *m < 1)
    {
      printf("*** ERROR!***\n\n");
    }
  } while (*n < 1 || *m < 1);
  int **arr = new int*[*n];
  for (int i = 0; i < *m; i++)
  {
    *(arr + i) = new int[*m];
  }
  fillRand(arr, *n, *m);
  //output(arr, *n, *m);
  return arr;
}

void fillRand(int **arr, int n, int m)
{
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      *(*(arr + i) + j) = rand() % LIM;
    }
  }
}

void output(int **arr, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << setw(4) << *(*(arr + i) + j) << " ";
    }
    cout << "\n";
  }
}

int **blur(int **arr, int n, int m, unsigned int *start_time)
{
  int upLim, botLim, leftLim, rightLim;
  int r;
  int j;
  int sum = 0;
  int sumLine;

  cout << "Enter radius: ";
  cin >> r;
  r = abs(r);

  *start_time = clock();
  if (r > 0)
  {
    int **arr2 = new int*[n];
    if (r >= n - 1 && r >= m - 1)
    {
      int temp = 0;
      for (int i = 0; i < n; i++)
      {
        for (j = 0; j < m; j++)
        {
          temp += *(*(arr + i) + j);
        }
      }
      temp /= n * m;

      for (int i = 0; i < n; i++)
      {
        *(arr2 + i) = new int[m];
        for (j = 0; j < m; j++)
        {
          *(*(arr2 + i) + j) = temp;
        }
        delete[]arr[i];
      }
      delete arr;
      return arr2;
    }
    else
    {
      for (int i = 0; i < r && i < n; i++)
      {
        for (j = 0; j <= r && j < m; j++)
        {
          sum += *(*(arr + i) + j);
        }
      }

      leftLim = 0;
      rightLim = (r >= m ? m - 1 : r);

      for (int i = 0; i < n; i++)
      {
        *(arr2 + i) = new int[m];
        upLim = (i - r < 0 ? 0 : i - r);
        botLim = (i + r >= n ? n - 1 : i + r);
        rightLim = (r >= m ? m - 1 : r);
        if (i - r > 0)
        {
          for (int k = 0; k <= rightLim; k++)
          {
            sum -= *(*(arr + upLim - 1) + k);
          }
          delete[]arr[upLim - 1];
        }
        if (i + r < n)
        {
          for (int k = 0; k <= rightLim; k++)
          {
            sum += *(*(arr + botLim) + k);
          }
        }
        sumLine = sum;
        *(*(arr2 + i)) = sumLine / ((rightLim + 1) * (botLim - upLim + 1));
        for (j = 1; j < m; j++)
        {
          leftLim = j - r < 0 ? 0 : j - r;
          rightLim = j + r >= m ? m - 1 : j + r;
          if (j - r > 0)
          {
            for (int k = upLim; k <= botLim; k++)
            {
              sumLine -= *(*(arr + k) + leftLim - 1);
            }
          }
          if (j + r < n)
          {
            for (int k = upLim; k <= botLim; k++)
            {
              sumLine += *(*(arr + k) + rightLim);
            }
          }
          *(*(arr2 + i) + j) = sumLine / ((rightLim - leftLim + 1) * (botLim - upLim + 1));
        }
      }
    }
    for (int i = upLim; i < n; i++)
    {
      delete[]arr[i];
    }
    delete arr;
    return arr2;
  }
  else
  {
    cout << "\n Process didn't need.\n";
    return arr;
  }
}
