#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;
struct collection
{
  string words;
  int quantity = 1;
};

string deletepunct(string sonet);
string deleteEnters(string sonet);
collection *resize(collection *obj, int k, int l);
void showData(collection *obj, int k, size_t max, string pathout);
void separate(collection *obj, string sonet, int &k);
int comparre(collection *obj, int k, size_t &max);
void sortAlphabet(collection *obj, int k, int m);
void sortPoints(collection *obj, int k);

int main(int argc, char*argv[])
{
  string sonet;
  string output;
  string pathin;
  string pathout;
  collection *words;
  size_t max;
  int k;
  int l;
  int liter;
  max = 0;
  liter = 0;
  words = new collection[255];
  pathin = "input.txt";
  pathout = "output.txt";
  if (argc == 3)
  {
    pathin = argv[1];
    pathout = argv[2];
  }
  ifstream in;
  in.open(pathin);
  if (!in.is_open()) {
    cout << "The file can not be opened!" << endl;
  }
  else {
    getline(in, sonet, '\0');
    in.close();
    cout <<endl<< sonet << endl << endl;
    ofstream out;
    out.open(pathout);
    out <<endl<< sonet << endl << endl;
    out.close();
    separate(words, deleteEnters(deletepunct(sonet)), k);
    l = comparre(words, k, max);
    words = resize(words, k, l);
    sortAlphabet(words, l, liter);
    sortPoints(words, l);
    showData(words, l, max, pathout);
    delete[] words;
  }
  system("pause");
  return 0;
}

string deletepunct(string sonet)
{
  int i;
  for (i = 0; sonet[i] != '\0'; i++)
  {
    if (sonet[i] == '\n')
    {
      continue;
    }

    if (sonet[i] == '\'' && i != 0 && isalpha(sonet[i - 1]) && i + 1 != '\0' && isalpha(sonet[i + 1]))
    {
      continue;
    }
    if (sonet[i] == '-' && i != 0 && isalpha(sonet[i - 1]) && i + 1 != '\0' && isalpha(sonet[i + 1]))
    {
      continue;
    }
    if (ispunct(sonet[i]) || sonet[i] == ' ')
    {
      sonet[i] = '\n';
    }
  }
  if (ispunct(sonet[i - 2]))
  {
    sonet[i - 2] = '\n';
  }
  return sonet;
}
string deleteEnters(string sonet)
{
  for (int i = 0; sonet[i] != '\0'; i++)
  {
    if (i == 0 && sonet[i] == '\n')
    {
      sonet.erase(sonet.begin() + i);
      i--;
      continue;
    }
    if (sonet[i] == '\n'&&i + 1 != '\0'&&sonet[i + 1] == '\n')
    {
      sonet.erase(sonet.begin() + i + 1);
      i--;
    }
  }
  return sonet;
}
void separate(collection *obj, string sonet, int &k)
{
  string word;
  word = "";
  k = 0;
  int ind;
  for (int i = 0; sonet[i] != '\0'; i++)
  {
    word = "";
    ind = 0;
    while (sonet[i] != '\n')
    {
      if (sonet[i] != '\0')
      {
        word += sonet[i];
        ind = 1;
        i++;
      }
    }
    if (ind && word != "")
    {
      obj[k].words = word;
      k++;
    }
  }
}

int comparre(collection *obj, int k, size_t &max)
{
  int l;
  l = k;
  size_t length = 0;
  for (int i = 0; i < k; i++)
  {
    for (int j = i + 1; j < k; j++)
    {
      if (obj[i].words != "" && obj[j].words != "")
      {
        length = obj[i].words.length();
        if (max < length)
        {
          max = length;
        }
        if (obj[i].words.length() == obj[j].words.length())
        {
          length++;
          char *temp1 = new char[length];
          char *temp2 = new char[length];
          for (size_t t = 0; t < length; t++)
          {
            temp1[t] = obj[i].words[t];
            temp2[t] = obj[j].words[t];
          }
          if (_strcmpi(temp1, temp2) == 0)
          {
            obj[i].quantity++;
            obj[j].words = "";
            l--;
          }
          delete[] temp1;
          delete[] temp2;
        }
      }
    }
  }
  return l;
}
collection *resize(collection *obj, int k, int l)
{
  collection *sonett = new collection[l];
  int temp;
  temp = 0;
  for (int i = 0; i < k; i++)
  {
    if (obj[i].words != "")
    {
      sonett[temp] = obj[i];
      temp++;
    }
  }
  delete[] obj;
  return sonett;
}
void sortAlphabet(collection *obj, int k, int m)
{
  collection temp;
  for (int i = 0; i < k - 1; i++)
  {
    for (int j = 0; j < k - i - 1; j++)
    {
      char t1 = obj[j].words[m];
      char t2 = obj[j + 1].words[m];

      if (isupper(t1))
      {
        t1 = tolower(t1);
      }
      else if (isupper(t2))
      {
        t2 = tolower(t2);
      }

      if (t1 > t2)
      {
        temp = obj[j];
        obj[j] = obj[j + 1];
        obj[j + 1] = temp;
      }
    }
  }
}
void sortPoints(collection *obj, int k)
{
  int ind;
  collection temp;
  int m;
  m = 0;
  ind = 0;

  for (int i = 0; i < k - 1; i++)
  {
    for (int j = 0; j < k - i - 1; j++)
    {
      while (tolower(obj[j].words[m]) == tolower(obj[j + 1].words[m]) && j != k - 2)
      {
        ind = 1;
        if (obj[j].quantity < obj[j + 1].quantity)
        {
          temp = obj[j];
          obj[j] = obj[j + 1];
          obj[j + 1] = temp;
        }
        j++;
      }
      if (ind)
      {
        ind = 0;
        j--;
        continue;
      }
    }
  }
}
void showData(collection *obj, int k, size_t max, string pathout)
{
  ofstream out;
  out.open(pathout, ios_base::app);
  for (int i = 0; i < k; i++)
  {
    cout << setw(max) << obj[i].words << " : " << obj[i].quantity << endl;
    out << setw(max) << obj[i].words << " : " << obj[i].quantity << endl;
  }
  out.close();
}