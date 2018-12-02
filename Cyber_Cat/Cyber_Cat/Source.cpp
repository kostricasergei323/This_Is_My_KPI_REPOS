#include <iostream>
#include <windows.h>
using std::cin;
using std::cout;
using std::endl;

struct Metrix
{
  float height;
  float weight;
};
struct Data
{
  char name[30];
  int age;
  Metrix size;
  bool VIC = false;
};

struct List_Stek
{
  Data cat;
  List_Stek *next;
};

void input(List_Stek *element);
void add_S(List_Stek **head);
int count_S(List_Stek *head);
void clear(List_Stek **head);
void add_L(List_Stek **head);
void output(List_Stek *element);
void outputt(List_Stek *head);
void VICat(List_Stek *head, const int pos);
void VIP_processing(List_Stek *head);

int main()
{
  List_Stek *head = NULL;
  char choice;
  do
  {
    cout << "Do you want to create new element of stack? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      add_S(&head);
      cout << "Output stack with new element: " << endl;
      outputt(head);
    }
  } while (choice == 'y' || choice == 'Y');
  cout << endl << "QUANTITY OF STACK'S ELEMENTS = " << count_S(head) << endl;
  clear(&head);

  do
  {
    cout << "Do you want to create new element of list? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      add_L(&head);
      cout << "Output stack with new element: " << endl;
      outputt(head);
    }
  } while (choice == 'y' || choice == 'Y');

  do
  {
    if (head == NULL)
    {
      break;
    }
    cout << "Do you want to assign VICc status for cat, using position? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      int pos;
      do
      {
        cout << "Enter position:" << endl;
        cin >> pos;
        if (pos > 0 && pos <= count_S(head))
        {
          VICat(head, pos - 1);
          cout << endl << "Output processed list:" << endl;
          outputt(head);
          break;
        }
        else cout << endl << "Sorry, but you enter not valid position" << endl;
      } while (true);
    }
  } while (choice == 'y' || choice == 'Y');

  VIP_processing(head);
  clear(&head);
  system("pause");
  return 0;
}

void input(List_Stek *element)
{
  cout << endl << "Enter name of cat: ";
  while (cin.get() != '\n');
  cin.getline(element->cat.name, 30);

  do
  {
    cout << "Enter cat's age: ";
    cin >> element->cat.age;
    if (element->cat.age <= 0 || element->cat.age > 20)
    {
      cout << endl << "Sorry, but you maybe make mistake, try again" << endl;
    }
  } while (element->cat.age <= 0 || element->cat.age > 20);

  cout << endl << "Enter cat's height:" << endl;
  cin >> element->cat.size.height;
  cout << endl << "Enter cat's weight:" << endl;
  cin >> element->cat.size.weight;
  if (element->cat.size.height < 0)
  {
    element->cat.size.height *= -1;
  }
  else if (element->cat.size.weight < 0)
  {
    element->cat.size.weight *= -1;
  }
}
void add_S(List_Stek **head)
{
  if (*head == NULL)
  {
    List_Stek *t = new List_Stek;
    input(t);
    *head = t;
    (*head)->next = NULL;
    return;
  }
  List_Stek *t = new List_Stek;
  input(t);
  t->next = *head;
  *head = t;
}
int count_S(List_Stek *head)
{
  if (head == NULL)
  {
    return 0;
  }
  List_Stek *t = head;
  int i;
  i = 0;
  while (head)
  {
    i++;
    head = head->next;
  }
  return i;
}
void clear(List_Stek **head)
{
  if (*head == NULL)
  {
    return;
  }
  List_Stek *t;
  while (*head)
  {
    t = *head;
    *head = (*head)->next;
    delete t;
  }
}
void add_L(List_Stek **head)
{
  if (*head == NULL)
  {
    List_Stek *t = new List_Stek;
    input(t);
    *head = t;
    (*head)->next = NULL;
    return;
  }
  List_Stek *t = *head;

  while (t->next)
  {
    t = t->next;
  }
  t->next = new List_Stek;
  input(t->next);
  t->next->next = NULL;
}

void outputt(List_Stek *head)
{
  if (head == NULL)
  {
    cout << "List or Stack is empty" << endl;
    return;
  }
  List_Stek *t = head;
  int i = 1;
  while (t)
  {
    cout << "Cat #" << i << " VIP: ";
    t->cat.VIC ? cout << "AVILIABLE" << endl : cout << "NONE" << endl;
    t = t->next;
    i++;
  }
}
void output(List_Stek *element)
{
  if (element == NULL)
  {
    cout << "List or Stack is empty" << endl;
    return;
  }
  cout << "Name: " << element->cat.name << endl;
  cout << "Age: " << element->cat.age << endl;
  cout << "VIC: ";
  element->cat.VIC ? cout << "AVILIABLE" << endl : cout << "NONE" << endl;
  cout << "Metrix:" << endl;
  cout << "1. Height -  " << element->cat.size.height << endl;
  cout << "2. Weight -  " << element->cat.size.weight << endl << endl;
}
void VICat(List_Stek *head, const int pos)
{
  if (head == NULL)
  {
    return;
  }
  List_Stek *t = head;
  int i;
  i = 0;
  while (t->next && i < pos)
  {
    t = t->next;
    i++;
  }
  t->cat.VIC = true;
}
void VIP_processing(List_Stek *head)
{
  if (head == NULL)
  {
    return;
  }
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  List_Stek *t = head;
  while (t)
  {
    if (t->cat.VIC)
    {
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
      output(t);
    }
    t = t->next;
  }
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
  t = head;
  while (t)
  {
    if (t->cat.VIC == false)
    {
      output(t);
    }
    t = t->next;
  }
}
