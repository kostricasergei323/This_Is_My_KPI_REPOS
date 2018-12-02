#define N 5
#include <iostream>
#include <time.h>
#include <cstring>
#include <iomanip>
using namespace std;
struct Item
{
  int id;
  int av_quantity;
  int price;
  char name[30];
};
struct Order
{
  Item *items;
  int number;
  int quantity;
  int c;
  int date;
};
struct Shop
{
  Order *orders;
};
void SetItems(Item *items);
Order *NewOrder(Order *order, Item *items, int &n);
Item *NewItem(Item *items, int &c);
void ShowItem(Item *items, const int &c);
void ShowOrder(Order *order, const int &n);
Order *DeleteOrder(Order *order, int &n);
int main()
{
  int n;
  int *k = new int[0];
  k[0] = 88;
  cout << k;
  Shop *shop = new Shop;
  shop->orders = new Order[0];
  Item *items = new Item[N];
  char choice;
  n = 0;
  SetItems(items);
  do
  {
    cout << "Do you want to create new order? (y/n)" << endl;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
      shop->orders = NewOrder(shop->orders, items, n);
    }
  } while (choice == 'Y' || choice == 'y');
  ShowOrder(shop->orders, n);
  system("pause");
  return 0;
}
void SetItems(Item *items)
{
  srand(time(NULL));
  strcpy_s(items[0].name, "Keyboard");
  strcpy_s(items[1].name, "Mouse");
  strcpy_s(items[2].name, "Monitor");
  strcpy_s(items[3].name, "Smartphone");
  strcpy_s(items[4].name, "TV");
  for (int i = 0; i < N; i++)
  {
    items[i].id = rand() % 100 + 2018;
    items[i].av_quantity = rand() % 10 + 1;
    items[i].price = rand() % 100 + 1;
  }
}
Item *NewItem(Item *items, int &c)
{
  Item *items_1 = new Item[c + 1];
  for (int i = 0; i < c; i++)
  {
    items_1[i] = items[i];
  }
  c++;
  delete[] items;
  return items_1;
}
Order *NewOrder(Order *order, Item *items, int &n)
{
  int k;
  int c;
  int ind;
  char choice;
  c = 0;
  ind = 1;
  Order *order_1 = new Order[n + 1];
  system("cls");
  for (int i = 0; i < n; i++)
  {
    order_1[i] = order[i];
  }
  delete[] order;
  order_1[n].items = new Item[1];
  cout << "Enter number of order: ";
  cin >> order_1[n].number;
  cout << "Enter day, when are do order: ";
  cin >> order_1[n].date;
  do
  {
    system("cls");
    cout << "Products: " << endl;
    order_1[n].items = NewItem(order_1[n].items, c);
    for (int j = 0; j < N; j++)
    {
      cout << j + 1 << ". " << items[j].name << endl;
    }
    do
    {
      cout << "Enter a number of product: ";
      cin >> k;
      if (k < 1 || k>5)
      {
        cout << "Incorrect, try again" << endl;
      }
    } while (k < 1 || k>5);

    switch (k)
    {
    case 1: order_1[n].items[c - 1] = items[0]; break;
    case 2: order_1[n].items[c - 1] = items[1]; break;
    case 3: order_1[n].items[c - 1] = items[2]; break;
    case 4: order_1[n].items[c - 1] = items[3]; break;
    case 5: order_1[n].items[c - 1] = items[4]; break;
    }
    do
    {
      cout << endl << "Enter quantity of product: ";
      cin >> order_1[n].quantity;
      if (order_1[n].quantity > order_1[n].items[c - 1].av_quantity)
      {
        cout << "Sorry, but in stock not enough product" << endl;
        cout << "Now in stock this item aviliable in " << order_1[n].items[c - 1].av_quantity << " thing" << endl;
        cout << "Do you want to delete this order? (y/n)" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
          order_1 = DeleteOrder(order_1, n);
          ind = 0;
          choice = '\0';
          return order_1;
        }
      }
    } while (order_1[n].quantity > order_1[n].items[c - 1].av_quantity);
    if (ind)
    {
      cout << "Do you want to add new item to your order? (y/n)" << endl;
      cin >> choice;
    }
  } while (choice == 'Y' || choice == 'y');
  order_1[n].c = c;
  n++;
  return order_1;
}

void ShowItem(Item *items, const int &c)
{
  for (int i = 0; i < c; i++)
  {
    cout << endl << "Item #" << i + 1 << endl;
    cout << "ID: " << items[i].id << endl;
    cout << "Name: " << items[i].name << endl;
    cout << "Price: " << items[i].price << '$' << endl;
  }
}
void ShowOrder(Order *order, const int &n)
{
  for (int i = 0; i < n; i++)
  {
    cout << endl << "Order #" << i + 1 << endl;
    cout << "Number: " << order[i].number << endl;
    cout << "Date: " << order[i].date << endl;
    cout << "Quantity: " << order[i].quantity << endl;
    ShowItem(order[i].items, order[i].c);
    cout << "****************" << endl;
  }
}
Order *DeleteOrder(Order *order, int &n)
{
  if (n == 0)
  {
    delete order;
    return NULL;
  }
  n--;
  Order *order_1 = new Order[n];
  for (int i = 0; i <= n; i++)
  {
    order_1[i] = order[i];
  }
  delete[] order;
  return order_1;
}