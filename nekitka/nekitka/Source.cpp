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
void addElement(List **head, const Data &x);
int func28(List *head);
void output(List *head);
int main()
{
  List *head = NULL;
  Data x;
  char choice;
  do
  {
    system("cls");
    cout << "Do you want to add new element to List? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter number" << endl;
      cin >> x.a;
      addElement(&head, x);
    }
  } while (choice == 'y' || choice == 'Y');

  cout << "New list:" << endl;
  output(head);
  cout << endl << "Quantity of max pair length of elements = " << func28(head) << endl;
  system("pause");
  return 0;
}

void addElement(List **head, const Data &x)
{
  if (*head == NULL)
  {
    (*head) = new List;
    (*head)->d.a = x.a;
    (*head)->next = NULL;
    return;
  }
  List *current = *head;
  while (current->next)
  {
    current = current->next;
  }
  current->next = new List;
  current->next->d.a = x.a;
  current->next->next = NULL;
}
int func28(List *head)
{
  if (head == NULL)
  {
    return 0;
  }
  List *current = head;
  int i;
  int max;
  i = 0;
  max = 0;
  while (current)
  {
    if (current->d.a % 2 == 0)
    {
      i++;
    }
    else i = 0;

    if (max < i)
    {
      max = i;
    }
    current = current->next;
  }
  return max;
}
void output(List *head)
{
  if (head == NULL)
  {
    cout << "List is empty" << endl;
  }
  List *current = head;
  while (current)
  {
    cout << current->d.a << endl;
    current = current->next;
  }
}