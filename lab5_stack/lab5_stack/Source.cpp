#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Data
{
  char a;
};

struct Stek
{
  Data d;
  Stek *next;
};

void add(Stek **head, const Data &x);
void processing(Stek *head);
void output(Stek *head);
void clear(Stek **head);
int main()
{
  Stek *head = NULL;
  Data x;
  char choice;
  int k;
  k = 0;
  do
  {
    system("cls");
    cout << "Do you want to create new stack's element? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter symbol" << endl;
      cin >> x.a;
      add(&head, x);
      k++;
    }
  } while (choice == 'y' || choice == 'Y');

  if (head == NULL)
  {
    cout << "Stack is empty" << endl;
  }
  else
  {
    cout << endl << "Output processed stack:" << endl;
    output(head);
    processing(head);
    clear(&head);
  }
  system("pause");
  return 0;
}

void add(Stek **head, const Data &x)
{
  if (*head == NULL)
  {
    Stek *t = new Stek;
    t->d.a = x.a;
    *head = t;
    (*head)->next = NULL;
    return;
  }
  Stek *t = new Stek;
  t->d.a = x.a;
  t->next = *head;
  *head = t;
}

void processing(Stek *head)
{
  if (head == NULL)
  {
    return;
  }
  int alpha;
  int num;
  alpha = 0;
  num = 0;
  Stek *t = head;
  while (t)
  {
    if (isalpha(t->d.a) && isupper(t->d.a))
    {
      alpha++;
    }
    if (isalnum(t->d.a) && !isalpha(t->d.a))
    {
      num++;
    }
    t = t->next;
  }
  if (alpha || num)
  {
    if (alpha == num)
    {
      cout << "The number of uppercase letters is equal to the number of digits" << endl;
      return;
    }
    num < alpha ? cout << endl << "Uppercase letters more than digits" << endl : cout << endl << "Digits more than uppercase letters" << endl;
    return;
  }
  cout << endl << "Program didn't meet any uppercase letter or number" << endl;
}

void output(Stek *head)
{
  Stek *t = head;
 
  if(t)
  {
    output(t->next);
    cout << t->d.a << endl;
  }
}
void clear(Stek **head)
{
  if (*head == NULL)
  {
    return;
  }
  Stek *t;
  while (*head)
  {
    t = *head;
    *head = (*head)->next;
    delete t;
  }
}