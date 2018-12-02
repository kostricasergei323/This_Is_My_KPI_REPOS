#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Info
{
  int index;
};
struct Data
{
  int a;
  Info profile;
};

struct List
{
  Data d;
  List *next;
  List *prev;
};
void el_delete(List **head, List **tail, const int pos);
void el_add(List **head, List **tail);
void el_swap(List **head, List **tail, const int pos);
void changes(List **head, List **tail, bool ch, const int pos);
void loop_list(List *head, List *tail);
void sort_list(List **head, List **tail);
void output_list(List *head, List *tail);
void el_input(List *element);
void find(List *head, List *tail, const Data &x);
void connect_list(List *head1, List **tail1, List **head2, List *tail2);
int el_count(List *head, List *tail);
void el_output(List *head, List *tail);


int main()
{
  List *head = NULL;
  List *tail = NULL;
  char choice;

  do
  {
    cout << "You want to add new element? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      el_add(&head, &tail);
      cout << endl << "Output list with new element:" << endl;
      output_list(head, tail);
    }
  } while (choice == 'y' || choice == 'Y');

  List *t = head;
  for (int i = 0; i < el_count(head, tail); i++)
  {
    el_input(t);
    t = t->next;
  }
  el_output(head, tail);
  do
  {
    if (head == NULL && tail == NULL)
    {
      break;
    }
    cout << "You want to delete element using position? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      do
      {
        int pos;
        cout << endl << "Enter position:" << endl;
        cin >> pos;
        if (pos<1 || pos>el_count(head, tail))
        {
          cout << endl << "Sorry, but you enter not valid position, try again" << endl;
        }
        else
        {
          el_delete(&head, &tail, pos - 1);
          cout << endl << "Output list with deleted element:" << endl;
          el_output(head, tail);
          break;
        }
      } while (true);
    }
  } while (choice == 'y' || choice == 'Y');

  do
  {
    if (head == NULL && tail == NULL)
    {
      break;
    }
    cout << "Do you want to swap element with next, using position? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      do
      {
        int pos;
        cout << endl << "Enter position:" << endl;
        cin >> pos;
        if (pos<1 || pos>el_count(head, tail) - 1)
        {
          cout << endl << "Sorry, but you enter not valid position, try again" << endl;
        }
        else
        {
          el_swap(&head, &tail, pos - 1);
          cout << endl << "Output list with swapped element:" << endl;
          el_output(head, tail);
          break;
        }
      } while (true);
    }
  } while (choice == 'y' || choice == 'Y');

  do
  {
    if (head == NULL && tail == NULL)
    {
      break;
    }
    cout << "Do you want to sort list? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      sort_list(&head, &tail);
      cout << endl << "Output sorted list:" << endl;
      el_output(head, tail);
      break;
    }
  } while (choice == 'y' || choice == 'Y');

  do
  {
    if (head == NULL && tail == NULL)
    {
      break;
    }
    cout << "You want to find element? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      Data element;
      cout << endl << "Enter number to find it in list: " << endl;
      cin >> element.a;
      find(head, tail, element);
    }
  } while (choice == 'y' || choice == 'Y');

  do
  {
    if ((head == NULL && tail == NULL) || el_count(head, tail) == 1)
    {
      break;
    }
    cout << "Do you want to change head or tail? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      bool chng;
      cout << endl << "What exactly you want to change? (h  - 1 /t - 0)" << endl;
      cin >> chng;
      do
      {
        int pos;
        cout << endl << "Enter new position:" << endl;
        cin >> pos;
        if (pos<1 || pos>el_count(head, tail))
        {
          cout << endl << "Sorry, but you enter not valid position, try again" << endl;
        }
        else
        {
          changes(&head, &tail, chng, pos - 1);
          cout << endl << "Output list with changed ";
          chng ? cout << "head" << endl : cout << "tail" << endl;
          el_output(head, tail);
          break;
        }
      } while (true);
    }
  } while (choice == 'y' || choice == 'Y');

  cout << endl << "Output finished list:" << endl;
  el_output(head, tail);
  cout << "END OF PROGRAM" << endl;
  system("pause");
  return 0;
}


void el_delete(List **head, List **tail, const int pos)
{
  if (*head == NULL && *tail == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  if (pos == 0 && (*head)->next)
  {
    List *t = *head;
    *head = (*head)->next;
    delete t;
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
void el_add(List **head, List **tail)
{
  if (*head == NULL && *tail == NULL)
  {
    List *k = new List;
    k->d.profile.index = 1;
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
  t->d.profile.index = i;
  t->prev = p;
  t->next = NULL;
  *tail = t;
}
void el_swap(List **head, List **tail, const int pos)
{
  if (*head == NULL && *tail == NULL)
  {
    return;
  }
  if (pos == 0 && (*head)->next)
  {
    List *t = (*head)->next->next;
    List *p = *head;
    *head = (*head)->next;
    (*head)->next = p;
    (*head)->next->next = t;
    return;
  }
  if (pos == el_count(*head, *tail) - 2)
  {
    List *temp = (*tail)->prev->prev->next->next;
    (*tail)->prev->prev->next->next = temp->next;
    temp->next = (*tail)->prev->prev->next;
    (*tail)->prev->prev->next = temp;
    return;
  }

  int i = 1;
  List *t = *head;
  while (t && i < pos)
  {
    t = t->next;
    i++;
  }
  List *temp = t->next->next;
  t->next->next = temp->next;
  temp->next = t->next;
  t->next = temp;
}
void changes(List **head, List **tail, bool ch, const int pos)
{
  if (*head == NULL && *tail == NULL)
  {
    return;
  }

  if (ch)
  {
    List *t = *head;
    int i;
    i = 0;
    while (t&&i < pos)
    {
      t = t->next;
      i++;
    }
    *head = t;
    (*head)->prev = NULL;
  }
  else
  {
    List *t = *head;
    int i;
    i = 0;
    while (t&&i < pos)
    {
      t = t->next;
      i++;
    }
    *tail = t;
    (*tail)->next = NULL;
  }
}
void loop_list(List *head, List *tail);
void sort_list(List **head, List **tail)
{
  if (*head == NULL && *tail == NULL)
  {
    return;
  }
  List *q, *end = NULL, *p, *pr;
  while (*head != NULL)
  {
    q = *head;
    *head = (*head)->next;
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
  *head = end;
}
void output_list(List *head, List *tail)
{
  if (head == NULL && tail == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  List *t = head;
  while (t)
  {
    cout << "Element #" << t->d.profile.index << endl;
    t = t->next;
  }
}

void el_output(List *head, List *tail)
{
  if (head == NULL && tail == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  List *t = head;
  while (t)
  {
    cout << "Element #" << t->d.profile.index << " Number = " << t->d.a << endl;
    t = t->next;
  }
}
void el_input(List *element)
{
  int a;
  cout << endl << "Enter number of element #" << element->d.profile.index << ':' << endl;
  cin >> a;
  element->d.a = a;
}
void find(List *head, List *tail, const Data &x)
{
  List *current = head;
  int pos;
  int ind;
  ind = 0;
  pos = 1;
  while (current)
  {
    if (current->d.a == x.a)
    {
      cout << endl << "Program found this element at pos = " << pos << endl;
      ind = 1;
      break;
    }
    current = current->next;
    pos++;
  }
  if (ind == 0)
  {
    cout << endl << "Sorry, but program not found this element" << endl;
  }
}
void connect_list(List *head1, List **tail1, List **head2, List *tail2);
int el_count(List *head, List *tail)
{
  if (head == NULL && tail == NULL)
  {
    return 0;
  }
  List *t = head->next;
  int i;
  i = 1;
  while (t)
  {
    i++;
    t = t->next;
  }
  return i;
}