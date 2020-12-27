#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data
{
  string bookNum;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main()
{
  Sales_data total;
  double price;
  if (cin >> total.bookNum >> total.units_sold >> price)
  {
    total.revenue = total.units_sold * price;
    Sales_data trans;
    while (cin >> trans.bookNum >> trans.units_sold >> price)
    {
      trans.revenue = trans.units_sold * price;
      if (total.bookNum == trans.bookNum)
      {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      }

      else
      {
        cout << total.bookNum << " " << total.units_sold << " " << total.revenue << endl;
        total = trans;
      }
    }
    cout << total.bookNum << " " << total.units_sold << " " << total.revenue << std::endl;
  }
  else
  {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  return 0;
}