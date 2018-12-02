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

Tree *Create(Tree **p, int n);
Tree *FindMaxNode(Tree *root);
Tree *FindMinNode(Tree *root);
Tree *swapMaxAndMin(Tree *root);
void Print(Tree *u);

int main()
{
  Tree *root = NULL;
  Tree *Max = NULL;
  Tree *Min = NULL;
  int n;
  cout << "Enter quantity of branches: " << endl;
  cin >> n;
  root = Create(&root, n);
  cout << endl << "Output new tree:" << endl;
  Print(root);
  Max = FindMaxNode(root);
  Min = FindMinNode(root);
  cout << endl << "Max element = " << Max->right->d.a << endl;
  cout << endl << "Min element = " << Min->left->d.a << endl;
  root = swapMaxAndMin(root);
  cout << endl << "Output swapped tree:" << endl;
  Print(root);
  system("pause");
  return 0;
}

Tree *Create(Tree **p, int n)
{
  system("cls");
  Tree *cur;
  int x, nl, nr;
  cur = *p;
  if (n == 0)
  {
    *p = NULL;
  }
  else
  {
    nl = n / 2;
    nr = n - nl - 1;
    cout << "Enter number: " << endl;
    cin >> x;
    cur = new Tree;
    cur->d.a = x;
    Create(&((*cur).left), nl);
    Create(&((*cur).right), nr);
    *p = cur;
  }
  return *p;
}

Tree* FindMinNode(Tree *root)
{
  while (root->left->left)
  {
    root = root->left;
  }
  return root;
}

Tree* FindMaxNode(Tree *root)
{
  while (root->right->right)
  {
    root = root->right;
  }
  return root;
}

Tree *swapMaxAndMin(Tree *root)
{
  Tree *MaxParent = FindMaxNode(root);
  Tree *MinParent = FindMinNode(root);
  Tree *temp;
  temp = MaxParent->right;
  MaxParent->right = MinParent->left;
  MinParent->left = temp;
  return root;
}
void Print(Tree *u)
{
  if (u)
  {
    Print(u->left);
    cout << u->d.a << endl;
    Print(u->right);
  }
}
