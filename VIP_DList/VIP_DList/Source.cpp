#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct Info
{
  int index;
  bool VipStatus = false;
};
struct Data
{
  char name[30] = "NONE";
  int age = 0;
  Info profile;
};
struct List
{
  Data person;
  List *next;
  List *prev;
};

void add(List **head, List **tail);
void input(List *element);
void VIPka(List *head, List *tail, const int pos);
void clear(List **head, List **tail);
void outputInfo(List *element);
void output(List *head, List *tail);

int main()
{
  List *head = NULL;
  List *tail = NULL;
  int k;
  int ind;
  char choice;
  ind = 1;
  k = 0;
  do
  {
    cout << "Do you want to check new visitor? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      k++;
      add(&head, &tail);
      cout << endl << "Output list with new visitor:" << endl;
      output(head, tail);
    }
  } while (choice == 'y' || choice == 'Y');

  cout << "Output list with visitors:" << endl;
  output(head, tail);


  do
  {
    if (head == NULL || tail == NULL)
    {
      break;
    }
    cout << "Do you want to assign VIP status for visitor, using position? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      int pos;
      do
      {
        cout << "Enter position:" << endl;
        cin >> pos;
        if (pos > 0 && pos <= k)
        {
          VIPka(head, tail, pos - 1);
          cout << endl << "Output processed list:" << endl;
          output(head, tail);
          break;
        }
        else cout << endl << "Sorry, but you enter not valid position" << endl;
      } while (true);
    }
  } while (choice == 'y' || choice == 'Y');

  List *element = head;
  for (int i = 0; i < k && element; i++)
  {
    if (ind)
    {
      for (int j = 0; j < k && element; j++)
      {
        if (element->person.profile.VipStatus)
        {
          input(element);
          cout << endl << "Info about visitor: " << endl;
          outputInfo(element);
        }
        element = element->next;
      }
      ind = 0;
      element = head;
    }

    if (!element->person.profile.VipStatus)
    {
      input(element);
      cout << endl << "Info about visitor: " << endl;
      outputInfo(element);
    }
    element = element->next;
  }
  ind = 1;
  element = head;
  for (int i = 0; i < k && element; i++)
  {
    if (ind)
    {
      cout << endl << "Output info about VIP visitors:" << endl;
      for (int j = 0; j < k && element; j++)
      {
        if (element->person.profile.VipStatus)
        {
          outputInfo(element);
        }
        element = element->next;
      }
      ind = 0;
      element = head;
      cout << endl << "Output info about noVIP visitors:" << endl;
    }

    if (!element->person.profile.VipStatus)
    {
      outputInfo(element);
    }
    element = element->next;
  }

  clear(&head, &tail);
  cout << "END OF PROGRAM" << endl;
  system("pause");
  return 0;
}

void add(List **head, List **tail)
{
  if (*head == NULL || *tail == NULL)
  {
    List *k = new List;
    k->person.profile.index = 1;
    k->next = NULL;
    k->prev = NULL;
    *head = k;
    *tail = k;
    return;
  }

  List *t = *head;
  List *p;
  int i;
  i = 2;
  while (t->next)
  {
    t = t->next;
    i++;
  }
  t->next = new List;
  p = t;
  t = t->next;
  t->person.profile.index = i;
  t->prev = p;
  t->next = NULL;
  *tail = t;
}


void VIPka(List *head, List *tail, const int pos)
{
  if (head == NULL || tail == NULL)
  {
    return;
  }
  List *t = head;
  int i;
  i = 0;
  while (t->next && i < pos)
  {
    t = t->next;
    i++;
  }
  t->person.profile.VipStatus = true;
}

void input(List *element)
{
  cout << endl << "Enter name of visitor: ";
  while (cin.get() != '\n');
  cin.getline(element->person.name, 30);

  do
  {
    cout << "Enter visitor's age: ";
    cin >> element->person.age;
    if (element->person.age <= 0 || element->person.age > 100)
    {
      cout << endl << "Sorry, but you maybe make mistake, try again" << endl;
    }
  } while (element->person.age <= 0 || element->person.age > 100);
}
void outputInfo(List *element)
{
  cout << endl << "Name: " << element->person.name << endl;
  cout << "Age: " << element->person.age << endl;
  cout << "VIP: ";
  element->person.profile.VipStatus ? cout << "AVILIABLE" << endl << endl : cout << "NONE" << endl << endl;
}
void output(List *head, List *tail)
{
  if (head == NULL || tail == NULL)
  {
    cout << "No one visitor ;-(" << endl;
    return;
  }
  List *t = head;
  while (t)
  {
    cout << "Visitor #" << t->person.profile.index;
    cout << " VIP: ";
    t->person.profile.VipStatus ? cout << "AVILIABLE" << endl : cout << "NONE" << endl;
    t = t->next;
  }
}
void clear(List **head, List **tail)
{
  if (*head == NULL || *tail == NULL)
  {
    return;
  }
  List *t;
  while ((*head) != NULL)
  {
    t = *head;
    *head = (*head)->next;
    delete t;
  }
  *tail = NULL;
}
