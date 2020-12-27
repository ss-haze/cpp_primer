#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data
{
  string isbn() const
  {
    return bookNum;
  };

  Sales_data &combine(const Sales_data &rhs);

  string bookNum;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

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
      if (total.isbn() == trans.isbn())
      {
        total.combine(trans);
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