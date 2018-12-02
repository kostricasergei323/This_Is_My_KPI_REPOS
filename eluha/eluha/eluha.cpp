#include <iostream>
using namespace std;
struct Data
{
  int a;
};

struct Tree
{
  Data d;
  Tree *left;
  Tree *right;
};

void Add(Tree **head, Data &x);
void Print(Tree *u);
Tree* Find(Tree *head, Data &x, Tree **prev);
bool isRoot(Tree *target, Data &x);
bool isOneSon(Tree *target, Data &x);
bool isTwoSons(Tree *target, Data &x);
bool isLeaf(Tree *target, Data &x);
int main()
{
  Tree *root = NULL;
  Data x;
  char choice;
  do
  {
    cout << "Do you want to create new element? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter number: " << endl;
      cin >> x.a;
      Add(&root, x);
    }
    system("cls");
  } while (choice == 'y' || choice == 'Y');
  cout << "Output tree:" << endl;
  Print(root);
  do
  {
    cout << endl << "Do you want to find element? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter key to find:" << endl;
      cin >> x.a;
      if (isRoot(root, x))
      {
        cout << endl << "Element is root" << endl;
      }
      if (isTwoSons(root, x))
      {
        cout << endl << "Element has two sons" << endl;
      }
      else if (isOneSon(root, x))
      {
        cout << endl << "Element has one son" << endl;
      }
      else if (isLeaf(root, x))
      {
        cout << endl << "Element is leaf" << endl;
      }
    }
  } while (choice == 'y' || choice == 'Y');
  system("pause");
  return 0;
}
//���������� ������ ��������:
void Add(Tree **head, Data &x)
{
  Tree *p = *head;
  if (p == NULL)
  { // ������ ����� - ����������� ����� ������� ������ ������ ������
    p = new Tree;
    p->d.a = x.a;
    p->left = NULL;
    p->right = NULL;
    *head = p;
    return;
  }
  Tree *p1 = NULL;
  bool is = false; // ������� ����, ��� ����� ������� ��� �������
  while (p && !is)
  {
    p1 = p;
    if (x.a == p->d.a)
    {
      is = true;
    }
    else {
      if (x.a < p->d.a)
      {
        p = p->left;
      }
      else {
        p = p->right;
      }
    }
  }
  if (is)
  {
    return;
  }

  // �������� ������ ����
  Tree *pnew = new Tree;
  pnew->d.a = x.a;
  pnew->left = NULL;
  pnew->right = NULL;
  if (x.a < p1->d.a) // ������������ � ������ ���������
  {
    p1->left = pnew;
  }
  else {            // ������������ � ������� ���������
    p1->right = pnew;
  }
}


////����� ������ � ����� �������� ����� � ������������� ���� (�� �����������) �� ����� ��������:
void Print(Tree *u)
{
  if (u)
  {
    cout << u->d.a << " ";
    Print(u->left);
    Print(u->right);
  }
}

//����� ���� � ������ �� �����
Tree* Find(Tree *head, Data &x, Tree **prev)
{
  Tree *p = head;
  *prev = NULL;
  // ������ ����� - ������ ������
  if (p == NULL)
    return NULL;

  // ����� �������� ��������
  while (p)
  {
    //cout << "Find : " << p->d.a << endl;
    if (p->d.a == x.a) {
      return p;
    } // ������� �������

    if (p->d.a > x.a) // ������� �� ����� ���������
    {
      *prev = p;
      p = p->left;
    }
    else// ������� �� ������ ���������
    {
      *prev = p;
      p = p->right;
    }
  }

  // ���� �������� ���� - ������ ������� �� ����������
  return NULL;
}


bool isRoot(Tree *target, Data &x)
{
  if (target == NULL) return false;
  Tree *prev = NULL;
  if (Find(target, x, &prev) == target) return true;
  return false;
}

bool isOneSon(Tree *target, Data &x)
{
  if (target == NULL) return false;
  Tree *prev = NULL;
  if ((Find(target, x, &prev)->right) || (Find(target, x, &prev)->left)) return true;
  if ((Find(target, x, &prev)->right) && (Find(target, x, &prev)->left)) return false;
  return false;
}

bool isTwoSons(Tree *target, Data &x)
{
  if (target == NULL) return false;
  Tree *prev = NULL;
  if ((Find(target, x, &prev)->right) && (Find(target, x, &prev)->left)) return true;
  return false;
}

bool isLeaf(Tree *target, Data &x)
{
  if (target == NULL) return false;
  Tree *prev = NULL;
  if (!(Find(target, x, &prev)->right) && !(Find(target, x, &prev)->left)) return true;
  return false;
}