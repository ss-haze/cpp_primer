#include "14-21-sales_data.h"

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
  *this = *this + rhs;
  return *this;
}

// If operator+= calls operator+, then both operator functions use a temporary Sales_data object (sum), which is less efficient than our present system of having operator+ call oerator+=

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum.units_sold = lhs.units_sold + rhs.units_sold;
  sum.revenue = lhs.revenue + rhs.revenue;
  return sum;
}

std::istream &operator>>(std::istream &is, Sales_data &item)
{
  double price;
  is >> item.bookNo >> item.units_sold >> price;

  if (is)
    item.revenue = item.units_sold * price;
  else
    item = Sales_data();

  return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item)
{
  os << item.isbn() << " " << item.units_sold << " "
     << item.revenue << " " << item.avg_price();
  return os;
}

inline double Sales_data::avg_price() const
{
  return units_sold ? revenue / units_sold : 0;
}

int main()
{
  Sales_data item1;

  std::cin >> item1;
  std::cout << item1;

  return 0;
}
