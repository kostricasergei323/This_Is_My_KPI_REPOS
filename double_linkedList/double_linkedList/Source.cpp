#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Data
{
  int a;
};
struct List
{
  Data d;
  List *next;
  List *prev;
};

void add(List *head, List **tail, Data &x);
void output(List *head);
int main()
{
  char choice;
  Data el;
  List *head = NULL;
  List *tail = NULL;
  List *t = new List;
  cout << "Enter number:" << endl;
  cin>>t->d.a;
  t->next = NULL;
  t->prev = NULL;
  head = t;
  tail = t;

  do
  {
    cout << "You want to create new element? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter number:" << endl;
      while (cin.get() != '\n');
      cin >> el.a;
      add(head, &tail, el);
    }
    else break;
  } while (true);
  cout << "Output:" << endl;
  output(head);
  system("pause");
  return 0;
}

void add(List *head, List **tail, Data & x)
{
  List *p = new List;
  List *current = head;
  while (current->next)
  {
    current = current->next;
  }
  current->next = new List;
  p = current;
  current = current->next;
  current->d.a = x.a;
  current->prev = p;
  current->next = NULL;
  *tail = current;
}

void output(List *head)
{
  if (head == NULL)
  {
    cout <<endl<< "List is empty" << endl;
    return;
  }
  List *current = head;
  while(current)
  {
    cout << current->d.a << endl;
    current = current->next;
  }
}