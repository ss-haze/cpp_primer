#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Sales_data
{
  friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
  friend istream &read(istream &is, Sales_data &item);
  friend ostream &print(ostream &os, const Sales_data &item);

public:
  Sales_data() = default;
  Sales_data(const string &num) : bookNum(num) {}
  Sales_data(const string &num, unsigned units, double price) : bookNum(num), units_sold(units), revenue(price * units) {}
  Sales_data(istream &is) { read(is, *this); }

  string isbn() const { return bookNum; };
  Sales_data &combine(const Sales_data &rhs);

private:
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
  Sales_data total(cin);
  if (cin)
  {
    Sales_data trans(cin);

    while (cin)
    {
      if (total.isbn() == trans.isbn())
      {
        total.combine(trans);
      }

      else
      {
        print(cout, total) << endl;
        total = trans;
      }
      read(cin, trans);
    }
    print(cout, total) << endl;
  }
  else
  {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }

  return 0;
}