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
void add(Tree **root, Data &x, int &i);
void output(Tree *root);

int main()
{
  Tree *root = NULL;
  Data x;
  srand(time(NULL));
  for (int i = 0; i < 5; i++)
  {
    x.a = rand() % 10+1;
    add(&root, x, i);
  }
  output(root);
  system("pause");
  return 0;
}

void add(Tree **root, Data &x, int &i)
{
  Tree *p = *root;
  if (p == NULL)
  {
    p = new Tree;
    p->d.a = x.a;
    p->left = NULL;
    p->right = NULL;
    *root = p;
    return;
  }
  while (p)
  {
    if (x.a > p->d.a)
    {
      if (p->right)
      {
        p = p->right;
        continue;
      }
      else
      {
        p->right = new Tree;
        p->right->d.a = x.a;
        p->right->left = NULL;
        p->right->right = NULL;
        return;
      }
    }
    else if (x.a < p->d.a)
    {
      if (p->left)
      {
        p = p->left;
        continue;
      }
      else
      {
        p->left = new Tree;
        p->left->d.a = x.a;
        p->left->left = NULL;
        p->left->right = NULL;
        return;
      }
    }
    else
    {
      i--;
      return;
    }
  }
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