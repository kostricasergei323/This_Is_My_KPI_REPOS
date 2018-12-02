#include <iostream>
#include <time.h>
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
Tree *balanced_tree(Tree **root, const int &n);
void output(Tree *root);

int main()
{
  Tree *root = NULL;
  int count;
  cout << "Enter quantity of elements: ";
  cin >> count;
  root=balanced_tree(&root, count);
  output(root);
  system("pause");
  return 0;
}

Tree *balanced_tree(Tree **root, const int &n)
{
  Tree *temp = *root;
  if (n == 0)
  {
    *root = NULL;
  }
  else
  {
    int x;
    int left_n = n / 2;
    int right_n = n - left_n - 1;
    system("cls");
    cout << "Enter element: ";
    cin >> x;
    temp = new Tree;
    (*temp).d.a = x;
    balanced_tree(&((*temp).left), left_n);
    balanced_tree(&((*temp).right), right_n);
    *root = temp;
  }
  return *root;
}
void output(Tree *root)
{
  if (root)
  {
    output(root->left);
    cout << root->d.a << endl;
    output(root->right);
  }
}