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
//Добавление нового элемента:
void Add(Tree **head, Data &x)
{
  Tree *p = *head;
  if (p == NULL)
  { // Дерево пусто - добавляемый новый элемент станет корнем дерева
    p = new Tree;
    p->d.a = x.a;
    p->left = NULL;
    p->right = NULL;
    *head = p;
    return;
  }
  Tree *p1 = NULL;
  bool is = false; // признак того, что такой элемент уже имеется
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

  // Создание нового узла
  Tree *pnew = new Tree;
  pnew->d.a = x.a;
  pnew->left = NULL;
  pnew->right = NULL;
  if (x.a < p1->d.a) // присоединить к левому поддереву
  {
    p1->left = pnew;
  }
  else {            // присоединить к правому поддереву
    p1->right = pnew;
  }
}


////Обход дерева и вывод значений узлов в упорядоченном виде (по возрастанию) на экран монитора:
void Print(Tree *u)
{
  if (u)
  {
    cout << u->d.a << " ";
    Print(u->left);
    Print(u->right);
  }
}

//Поиск узла в дереве по ключу
Tree* Find(Tree *head, Data &x, Tree **prev)
{
  Tree *p = head;
  *prev = NULL;
  // Дерево пусто - искать нечего
  if (p == NULL)
    return NULL;

  // Поиск искомого элемента
  while (p)
  {
    //cout << "Find : " << p->d.a << endl;
    if (p->d.a == x.a) {
      return p;
    } // Решение найдено

    if (p->d.a > x.a) // Перейти на левое поддерево
    {
      *prev = p;
      p = p->left;
    }
    else// Перейти на правое поддерево
    {
      *prev = p;
      p = p->right;
    }
  }

  // Если попадаем сюда - значит решение не существует
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