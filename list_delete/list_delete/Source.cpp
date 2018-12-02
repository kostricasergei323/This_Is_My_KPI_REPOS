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
};

void add(List *head, Data &x);
void listDelete(List **head, Data &x);
void listHeadDelete(List **head);
void listAddToPos(List **head, Data &x, const int pos);
void listDeletePos(List **head, const int pos);
void listDeleteWithPosAndNumbers(List **head, int pos, int quantity, int k);
void output(List *head);
void clear(List **head);

int main()
{
  List *head = NULL;
  char choice;
  Data el;
  int k;
  int ind;
  int pos;
  int quantity;
  ind = 0;
  k = 1;
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
      k++;
    }
    else break;
  } while (true);
  cout << endl << "Output list:" << endl;
  output(head);
  do {
    cout << "You want to create new element with position? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      ind = 1;
      cout << "Enter number to add to list:" << endl;
      while (cin.get() != '\n');
      cin >> el.a;
      do
      {
        cout << "Enter position of number:" << endl;
        cin >> pos;
        if (pos > 0 && pos < k + 1)
        {
          listAddToPos(&head, el, pos-1);
          break;
        }
        else
        {
          cout << "Sorry, but you enter not valid position" << endl;
        }
      } while (true);
    }
    else break;

  } while (true);
  while (cin.get() != '\n');
  if (ind)
  {
    ind = 0;
    cout << endl << "Output list with new elements:" << endl;
    output(head);
  }
  cout << "You want to delete number with value? (y/n): ";
  cin >> choice;
  if (choice == 'y' || choice == 'Y')
  {
    cout << "Enter number to delete from list:" << endl;
    cin >> el.a;
    listDelete(&head, el);
    cout << endl << "Output resulted list:" << endl;
    output(head);
  }

  do
  {
    cout << "Enter position of element to delete it from list:" << endl;
    cin >> pos;
    if (pos > 0 && pos <= k)
    {
      ind = 1;
      listDeletePos(&head, pos-1);
    }
    else  cout << "Sorry, but you enter not valid position" << endl;
  } while (pos <= 0 && pos>k);

  if (ind)
  {
    ind = 0;
    cout << endl << "Output list with deleted element's position:" << endl;
    output(head);
  }
  cout << "You want to delete head? (y/n): ";
  cin >> choice;
  if (choice == 'y' || choice == 'Y')
  {
    listHeadDelete(&head);
    cout << endl << "Output list with deleted head:" << endl;
    output(head);
  }

  do
  {
    cout << "Enter position of start's element and quantity to delete them from list:" << endl;
    cin >> pos >> quantity;
    if (quantity < 0)
    {
      quantity = 0;
    }
    if (pos<=0 && pos>k)
    {
      cout << "Sorry, but you enter not valid data" << endl;
    }
    else listDeleteWithPosAndNumbers(&head, pos-1, quantity, k);
  } while (pos<=0 && pos>k);

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


void listAddToPos(List **head, Data &x, const int pos)
{
  List *p = new List;
  p->d = x;
  if (*head == NULL)
  {
    p->next = NULL;
    *head = p;
    return;
  }
  List *t = *head;
  if (pos == 0)
  {
    p->next = t;
    *head = p;
    return;
  }

  List *current = *head;
  List *temp = current->next;
  int i;
  i = 0;


  while (temp && i < pos - 1)
  {
    current = temp;
    temp = temp->next;
    i++;
  }
  current->next = p;
  p->next = temp;
}

void listHeadDelete(List **head)
{
  if (*head == NULL)
  {
    return;
  }
  List *t = *head;
  *head = t->next;
  delete t;
}


void listDeletePos(List **head, const int pos)
{
  if (*head == NULL)
  {
    return;
  }
  List *current = *head;
  if (pos == 0)
  {
    *head = current->next;
    delete current;
    return;
  }

  List *temp = current->next;
  int i;
  i = 0;
  while (temp)
  {
    if (i == pos - 1)
    {
      current->next = temp->next;
      delete temp;
      return;
    }
    current = temp;
    temp = temp->next;
    i++;
  }
}

void listDeleteWithPosAndNumbers(List **head, int pos, int quantity, int k)
{
  if (*head == NULL)
  {
    return;
  }
  List *current = *head;
  if (pos == 0 && quantity == 0)
  {
    *head = current->next;
    delete current;
    return;
  }
  if (pos == 0 && quantity >= k)
  {
    clear(head);
    return;
  }

  if (quantity > k)
  {
    quantity = k;
  }

  List *temp = current->next;
  int i;
  i = 0;
  while (temp)
  {
    if ((i == pos - 1) && i < quantity+i)
    {
      current->next = temp->next;
      delete temp;
      temp = current;
      pos++;
      quantity--;
    }
    current = temp;
    temp = temp->next;
    i++;
  }
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
  if (head == NULL)
  {
    cout << endl << "List is empty" << endl;
    return;
  }
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