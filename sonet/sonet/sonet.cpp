#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
using namespace std;

struct word
{
  string words;
  int quantity = 0;
};

string *separate(string sonet, int &k)
{
  string *words;
  string *word;

  k = 0;

  return words;
}
void showData(word *obj, const int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << obj[i].words << ':' << obj[i].quantity << endl;
  }
}

int main(int argc, char* argv[])
{
  string sonet;
  string *words;
  string output;
  int k;
  argc = 3;
  if (argc == 3)
  {
    ifstream in("input.txt");
    ofstream out("output.txt");
    if (!in.is_open()) {
      cout << "The file can not be opened!" << endl;
    }
    else {
      getline(in, sonet, '\0');
      in.close();
      words = separate(sonet, k);
      out << output << endl;
      out.close();
    }
  }
  else {
    cout << "not enough command-line arguments" << endl;
  }
  system("pause");
  return 0;
}

