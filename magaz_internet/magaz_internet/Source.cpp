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
  int c;
  int date;
};
struct Shop
{
  Order *orders;
};
void SetItems(Item *items);
Order *NewOrder(Order *order, Item *items, int &n);
int ProfitPerOrder(const Order &order, const int &c);
int ForOneItem(const Item &items);
int ToPay(const Order *order, const int &n);
int ProfitPerDay(const Order *order, const int &n, const int &date);
Item *NewItem(Item *items, int &c);
void ShowItem(Item *items, const int &c);
void ShowOrders(Order *order, const int &n);
Order *DeleteOrder(Order *order, int &n);
int main()
{
  int n;
  Shop *shop = new Shop;
  shop->orders = new Order;
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
  system("cls");
  cout << "Do you want to check price per date? (y/n)" << endl;
  cin >> choice;
  if (choice == 'Y' || choice == 'y')
  {
    int date;
    do
    {
      system("cls");
      cout << "Enter date: " << endl;
      cin >> date;
      if (date > 0 && date < 32)
      {
        cout << "Total price: " << ProfitPerDay(shop->orders, n, date) << '$' << endl;
      }
      else
      {
        cout << "You enter incorrect date, try again" << endl;
      }
    } while (date < 1 || date > 31);
  }

  cout << "Do you want to check price for all orders? (y/n)" << endl;
  cin >> choice;
  if (choice == 'Y' || choice == 'y')
  {
    cout << "Total price: " << ToPay(shop->orders, n) << '$' << endl;
  }
  ShowOrders(shop->orders, n);
  DeleteOrder(shop->orders, n=0);
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
    items[i].av_quantity = rand() % 100 + 1;
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
  order_1[n].items = new Item;
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
      cout << j + 1 << ". " << left << setw(13) << items[j].name;
      cout << " Quantity = " << items[j].av_quantity;
      cout << " Price = " << items[j].price << '$' << endl;
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
    case 1: order_1[n].items[c - 1] = items[0]; k = 0; break;
    case 2: order_1[n].items[c - 1] = items[1]; k = 1; break;
    case 3: order_1[n].items[c - 1] = items[2]; k = 2; break;
    case 4: order_1[n].items[c - 1] = items[3]; k = 3; break;
    case 5: order_1[n].items[c - 1] = items[4]; k = 4; break;
    }
    do
    {
      cout << endl << "Enter quantity of product: ";
      while (cin.get() != '\n');
      cin >> order_1[n].items[c - 1].av_quantity;
      if (order_1[n].items[c - 1].av_quantity < 1)
      {
        cout << "Incorrect quanitity, try again" << endl;
        continue;
      }
      if (order_1[n].items[c - 1].av_quantity > items[k].av_quantity)
      {
        cout << "Sorry, but in stock not enough product" << endl;
        cout << "Now in stock this item aviliable in " << items[k].av_quantity << " thing" << endl;
        cout << "Do you want to cancel this order? (y/n)" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
          order_1 = DeleteOrder(order_1, n);
          return order_1;
        }
      }
      else
      {
        items[k].av_quantity -= order_1[n].items[c - 1].av_quantity;
        ind = 0;
      }
    } while (ind);
    cout << "Do you want to add new item to your order? (y/n)" << endl;
    cin >> choice;
  } while (choice == 'Y' || choice == 'y');
  order_1[n].c = c;
  n++;
  return order_1;
}

int ForOneItem(const Item &items)
{
  return items.price * items.av_quantity;
}
int ProfitPerOrder(const Order &order, const int &c)
{
  int sum;
  sum = 0;
  for (int i = 0; i < c; i++)
  {
    sum += ForOneItem(order.items[i]);
  }
  return sum;
}
int ToPay(const Order *order, const int &n)
{
  int sum;
  sum = 0;

  for (int i = 0; i < n; i++)
  {
    sum += ProfitPerOrder(order[i], order[i].c);
  }
  return sum;
}
int ProfitPerDay(const Order *order, const int &n, const int &date)
{
  int sum;
  sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (order[i].date == date)
    {
      sum += ProfitPerOrder(order[i], order[i].c);
    }
  }
  return sum;
}
void ShowItem(Item *items, const int &c)
{
  for (int i = 0; i < c; i++)
  {
    cout << endl << "Item #" << i + 1 << endl;
    cout << "ID: " << items[i].id << endl;
    cout << "Name: " << items[i].name << endl;
    cout << "Quantity: " << items[i].av_quantity << endl;
    cout << "Full Price: " << items[i].price * items[i].av_quantity << '$' << endl;
  }
}
void ShowOrders(Order *order, const int &n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    cout << endl << "Order #" << i + 1 << endl;
    cout << "Number: " << order[i].number << endl;
    cout << "Date: " << order[i].date << endl;
    ShowItem(order[i].items, order[i].c);
    cout << "****************" << endl;
  }
  if (i == 0)
  {
    cout << endl << "NO ORDERS!!!" << endl;
  }
}
Order *DeleteOrder(Order *order, int &n)
{
  if (n == 0)
  {
    delete order;
    return NULL;
  }
  Order *order_1 = new Order[n];
  for (int i = 0; i < n; i++)
  {
    order_1[i] = order[i];
  }
  delete[] order;
  return order_1;
}