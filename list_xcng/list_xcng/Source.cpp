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
};
void del(List **head, int &k, const Data &x);
void swap(List **head, List *current);
void add(List **head, const Data &x);
void swaptr(List **head, int s);
void output(List *head);
void clear(List **head);
int main()
{
  List *head = NULL;
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
      add(&head, x);
      k++;
    }
  } while (choice == 'y' || choice == 'Y');
  cout << endl << "Output processed list:" << endl;
  output(head);

  do
  {
    if (head == NULL)
    {
      break;
    }
    cout << "Do you want to delete elements with key? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter key" << endl;
      cin >> x.a;
      del(&head, k, x);
      cout << endl << "Output processed list:" << endl;
      output(head);
    }
  } while (choice == 'y' || choice == 'Y');

  if (k >= 3)
  {
    swaptr(&head, k);
  }
  cout << endl << "Output finished list:" << endl;
  output(head);
  clear(&head);
  system("pause");
  return 0;
}
void add(List **head, const Data &x)
{
  if (*head == NULL)
  {
    List *k = new List;
    k->d.a = x.a;
    k->next = NULL;
    *head = k;
    return;
  }
  List *t = *head;
  while (t->next)
  {
    t = t->next;
  }
  t->next = new List;
  t = t->next;
  t->d.a = x.a;
  t->next = NULL;
}

void del(List **head, int &k, const Data &x)
{
  if (*head == NULL)
  {
    return;
  }
  List *current = *head;
  while (current->d.a == x.a)
  {
    if (*head == NULL)
    {
      return;
    }
    if ((*head)->next == NULL)
    {
      *head = NULL;
      k--;
      return;
    }
    *head = current->next;
    delete current;
    current = *head;
    k--;
    if (current->next)
    {
      swap(head, current);
    }
  }

  List *temp = current->next;
  while (temp)
  {
    if (temp->d.a == x.a)
    {
      if (temp->next == NULL)
      {
        current->next = NULL;
        delete temp;
        k--;
        return;
      }
      current->next = temp->next;
      delete temp;
      temp = current;
      k--;
      if (temp->next->next)
      {
        swap(head, temp->next);
      }
      else return;
    }
    current = temp;
    temp = temp->next;
  }
}
void swap(List **head, List *current)
{
  if (*head == NULL)
  {
    return;
  }

  if (*head == current)
  {
    List *t = *head;
    List *p = (*head)->next;
    List *k = p;
    *head = p;
    t->next = k->next;
    (*head)->next = t;
    return;
  }
  List *t = *head;
  while (t->next != current)
  {
    t = t->next;
  }
  t->next = current->next;
  current->next = t->next->next;
  t->next->next = current;
}
void swaptr(List **head, int s)
{
  if (*head == NULL)
  {
    return;
  }
  List *t = *head;
  List *p = t->next->next;
  List *k = p->next;
  int i;
  t->next->next = *head;
  *head = p;
  (*head)->next = t->next;
  t->next->next->next = k;
  List *t1;
  for (t = *head, i = 0; i < 2 && t->next; i++, t = t->next);
  for (t1 = *head, i = 0; i < 3 && t1->next; i++, t1 = t1->next);
  i++;
  while (i < s - 1)
  {
    if ((i + 2) % 3 == 0)
    {
      List *p = t1->next;
      List *k = p->next;
      List *m = k->next;
      t->next = k;
      k->next = p;
      p->next = t1;
      t1->next = m;
      i += 2;
    }
    t = t1;
    t1 = t1->next;
    i++;
  }
}
void output(List *head)
{
  if (head == NULL)
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