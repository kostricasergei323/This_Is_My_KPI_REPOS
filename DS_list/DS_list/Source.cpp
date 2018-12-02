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

void add(List **head, List **tail, const Data &x);
void deleteEl(List **head, List **tail, int pos);
void clear(List **head, List **tail);
void output(List *head, List *tail);

int main()
{
  List *head = NULL;
  List *tail = NULL;
  Data x;
  int k;
  int ind;
  int ind1;
  char choice;
  ind = 0;
  ind1 = 0;
  k = 0;
  do
  {
    cout << "Do you want to create new element? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      k++;
      cout << "Enter number:" << endl;
      cin >> x.a;
      add(&head, &tail, x);
      ind = 1;
    }
    else break;
  } while (choice == 'y' || choice == 'Y');

  if (ind)
  {
    cout << "Output processed list:" << endl;
    output(head, tail);
    ind1 = 0;
  }

  do
  {
    if (head == NULL || tail == NULL)
    {
      break;
    }
    cout << "Do you want to delete element with position? (y/n)" << endl;
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
          deleteEl(&head, &tail, pos - 1);
          k--;
          cout << endl << "Output processed list:" << endl;
          output(head, tail);
          ind1 = 1;
          break;
        }
        else cout << endl << "Sorry, but you enter not valid position" << endl;
      } while (true);
    }

  } while (choice == 'y' || choice == 'Y');

  cout << endl << "Output resulted list:" << endl;
  output(head, tail);

  clear(&head, &tail);
  cout << "END OF PROGRAM" << endl;
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
    t = t->next;
  }
  t->next = new List;
  p = t;
  t = t->next;
  t->d.a = x.a;
  t->prev = p;
  t->next = NULL;
  *tail = t;
}


void deleteEl(List **head, List **tail, int pos)
{
  if (*head == NULL)
  {
    cout << "List is empty" << endl;
  }
  if (pos == 0 && (*head)->next)
  {
    List *t = *head;
    delete t;
    *head = (*head)->next;
    return;
  }

  if (pos == 0 && (*head)->next == NULL)
  {
    List *t = *head;
    delete t;
    *head = NULL;
    *tail = NULL;
    return;
  }
  List *t = *head;
  int i;
  i = 0;
  while (t->next && i < pos)
  {
    t = t->next;
    i++;
  }
  if (t->next)
  {
    List *t1 = t->next;
    t1->prev = t->prev;
    t->prev->next = t->next;
    delete t;
  }
  else
  {
    t->prev->next = NULL;
    *tail = t->prev;
    delete t;
  }
}

void output(List *head, List *tail)
{
  if (head == NULL || tail == NULL)
  {
    cout << "List is empty" << endl;
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
  if (*head == NULL || *tail == NULL)
  {
    return;
  }
  List *t;
  while((*head)!=NULL)
  {
    t = *head;
    *head = (*head)->next;
    delete t;
  }
  *tail = NULL;
}
