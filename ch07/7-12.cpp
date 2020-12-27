#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

struct Sales_data;
istream &read(istream &is, Sales_data &item);

struct Sales_data
{
  Sales_data() = default;

  Sales_data(const string &num)
      : bookNum(num)
  {
  }

  Sales_data(const string &num, unsigned units, double price)
      : bookNum(num),
        units_sold(units),
        revenue(price * units)
  {
  }

  Sales_data(istream &is)
  {
    read(is, *this);
  }

  string isbn() const { return bookNum; }

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

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data result = lhs;
  return result.combine(rhs);
}

istream &read(istream &is, Sales_data &item)
{
  double price;
  is >> item.bookNum >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
  return os << item.bookNum << " " << item.units_sold << " " << item.revenue;
}

int main()
{
  Sales_data item1;
  Sales_data item2("122-5");
  Sales_data item3("122-6", 50, 10);
  Sales_data item4(cin);

  print(cout, item1) << endl;
  print(cout, item2) << endl;
  print(cout, item3) << endl;
  print(cout, item4) << endl;

  return 0;
}