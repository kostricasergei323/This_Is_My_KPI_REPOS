#include <iostream>
#include "lab03.h"

using namespace std;

int main()
{
  GraphicCard MyVideocard;
  bool control = 0;
  bool ind = 0;
  do {
    system("cls");
    MyVideocard.ShowMainMenu();
    cout << endl << "Open the menu again? (0/1)" << endl;
    
    do {
      cout << "Your choice: ";
      cin >> ind;
      if (MyVideocard.getControl() == 1 && ind == 0)
      {
        MyVideocard.DataOutput();
        control = 0;
      }
      if (cin.fail()) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Invalid format! Try again!" << endl;
      }
      else { control = 1; }
    } while (!control);
  } while (ind);

  system("pause");
  return 0;
}