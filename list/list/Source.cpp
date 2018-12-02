#include <iostream>
using namespace std;
struct Data
{
  int a;
};
struct List
{
  Data d;
  List *next;
};

void add(List *head, Data &x);
List *sortList(List *head);
void listDelete(List **head, Data &x);
void listAdd(List **head, Data &x);
void output(List *head);
void clear(List **head);

int main()
{
  List *head = NULL;
  char choice;
  Data el;
  head = new List;
  cout << "Enter number:" << endl;
  cin >> head->d.a;
  fflush(stdin);
  head->next = NULL;
  do {
    cout << "You want to create new element? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter number:" << endl;
      while (cin.get() != '\n');
      cin >> el.a;
      add(head, el);
    }
    else break;
  } while (true);

  head = sortList(head);
  cout << "Enter number to add to list:" << endl;
  cin >> el.a;
  listAdd(&head, el);  
  cout << endl << "Output sorted list with new element:" << endl;
  output(head);
  system("pause");
  cout << "Enter number to delete from list:" << endl;
  cin >> el.a;
  listDelete(&head, el);
  cout << endl << "Output resulted list:" << endl;
  output(head);
  clear(&head);
  system("pause");
  return 0;
}

void add(List *head, Data &x)
{
  List *current = head;
  while (current->next)
  {
    current = current->next;
  }
  current->next = new List;
  current->next->d.a = x.a;
  current->next->next = NULL;

}


void listAdd(List **head, Data &x) {
  List *p = new List;
  p->d = x;

  List *current = *head;
  if (current->d.a < x.a)
  {
    p->next = *head;
    *head = p;
    return;
  }
  List *temp = current->next;
  while (temp)
  {
    if (temp->d.a < x.a)
    {
      p->next = temp;
      current->next = p;
      return;
    }
    current = temp;
    temp = temp->next;
  }
  temp->next = p;
}

List *sortList(List *head)
{
  if (!head)
  {
    return NULL;
  }
  List *q, *end = NULL, *p, *pr;
  while (head != NULL)
  {
    q = head;
    head = head->next;
    for (p = end, pr = NULL; p != NULL && q->d.a > p->d.a; pr = p, p = p->next);
    if (pr == NULL)
    {
      q->next = end;
      end = q;
    }
    else
    {
      q->next = p;
      pr->next = q;
    }
  }
  return end;
}

void listDelete(List **head, Data &x) {
  if (*head == NULL)
  {
    return;
  }
  List *current = *head;
  while (current->d.a == x.a)
  {
    *head = current->next;
    delete current;
    current = *head;
  }

  List *temp = current->next;
  while (temp)
  {
    if (temp->d.a == x.a)
    {
      current->next = temp->next;
      delete temp;
      temp = current;
    }
    current = temp;
    temp = temp->next;
  }
}

void output(List *head)
{
  List *current;
  current = head;
  while (current)
  {
    cout << current->d.a << endl;
    current = current->next;
  }
}

void clear(List **head)
{
  if (*head == NULL)
  {
    return;
  }
  List *p = *head;
  List *t;
  while (p)
  {
    t = p;
    p = p->next;
    delete t;
  }
  *head = NULL;
}