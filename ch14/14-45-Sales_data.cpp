#include "14-45-Sales_data.h"

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}

Sales_data &Sales_data::operator-=(const Sales_data &rhs)
{
  units_sold -= rhs.units_sold;
  revenue -= rhs.revenue;
  return *this;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data sum = lhs;
  sum -= rhs;
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
