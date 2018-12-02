#include <iostream>
using std::cin;
using std::cout;
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
void del(List **head, List **tail, int &k, const Data &x);
void add(List **head, List **tail, const Data &x);
void swaptr(List **head, List **tail, int s);
void output(List *head, List *tail);
void clear(List **head, List **tail);
int main()
{
  List *head = NULL;
  List *tail = NULL;
  Data x;
  int k;
  char choice;
  k = 0;
  do
  {
    system("cls");
    cout << "Do you want to create new list's element? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter number" << endl;
      cin >> x.a;
      add(&head, &tail, x);
      k++;
    }
  } while (choice == 'y' || choice == 'Y');
  cout << endl << "Output processed list:" << endl;
  output(head, tail);

  do
  {
    if (head == NULL && tail == NULL)
    {
      break;
    }
    cout << "Do you want to delete elements with key? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter key" << endl;
      cin >> x.a;
      del(&head, &tail, k, x);
      cout << endl << "Output processed list:" << endl;
      output(head, tail);
    }
  } while (choice == 'y' || choice == 'Y');

  if (k >= 3)
  {
    swaptr(&head, &tail, k);
  }
  cout << endl << "Output finished list:" << endl;
  output(head, tail);
  clear(&head, &tail);
  system("pause");
  return 0;
}
void add(List **head, List **tail, const Data &x)
{
  if (*head == NULL && *tail == NULL)
  {
    List *k = new List;
    k->d.a = x.a;
    k->next = NULL;
    k->prev = NULL;
    *head = k;
    *tail = k;
    return;
  }
  List *t = *head;
  List *p;
  while (t->next)
  {
    p = t;
    t = t->next;
    t->prev = p;
  }
  t->next = new List;
  t->next->prev = t;
  t = t->next;
  t->d.a = x.a;
  *tail = t;
  t->next = NULL;
}

void del(List **head, List **tail, int &k, const Data &x)
{
  if (*head == NULL && *tail == NULL)
  {
    return;
  }
  List *current = *head;
  while (current->d.a == x.a)
  {
    if (*head == *tail)
    {
      *head = NULL;
      *tail = NULL;
      return;
    }
    *head = current->next;
    delete current;
    current = *head;
    k--;
  }

  List *temp = current->next;
  while (temp)
  {
    if (temp->d.a == x.a)
    {
      if (temp == *tail)
      {
        temp->prev->next = NULL;
        *tail = temp->prev;
        delete temp;
        return;
      }
      current->next = temp->next;
      delete temp;
      temp = current;
      k--;
    }
    current = temp;
    temp = temp->next;
  }
}
void swaptr(List **head, List **tail, int s)
{
  if (*head == NULL && *tail == NULL)
  {
    return;
  }
  List *t = *head;
  List *p = t->next->next->next;
  int i;
  *head = t->next->next;
  (*head)->next = t->next;
  (*head)->prev = NULL;
  (*head)->next->next = t;
  (*head)->next->prev = *head;
  t->next = p;
  t->prev = (*head)->next;
  List *t1;
  List *k;
  t1 = t->next;
  i = 4;
  while (i < s - 1)
  {
    if ((i + 2) % 3 == 0)
    {
      k = t1->next->next;
      p = k->next;
      t->next = k;
      t->next->next = t1->next;
      t->next->prev = t;
      t->next->next->next = t1;
      t->next->next->prev = t->next;
      t1->next = p;
      t1->prev = t->next->next;
      i += 2;
    }
    t = t1;
    t1 = t1->next;
    i++;
  }
}
void output(List *head, List *tail)
{
  if (head == NULL && tail == NULL)
  {
    cout << endl << "List is empty" << endl;
    return;
  }
  List *t = head;
  while (t)
  {
    cout << t->d.a << endl;
    t = t->next;
  }
}
void clear(List **head, List **tail)
{
  if (*head == NULL && *tail == NULL)
  {
    return;
  }
  while (*head)
  {
    List *t = *head;
    *head = (*head)->next;
    delete t;
  }
  *head = NULL;
  *tail = NULL;
}