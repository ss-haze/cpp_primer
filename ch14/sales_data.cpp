#include "sales_data.h"

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

std::istream &operator>>(std::istream &is, Sales_data &item)
{
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
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
  Sales_data item1("Macbeth", 10, 12);
  Sales_data item2("Macbeth", 50, 10);
  Sales_data item3("Catch-22");
  Sales_data item4(std::cin);

  std::cout << item1 << std::endl;
  std::cout << item2 << std::endl;
  std::cout << item3 << std::endl;
  std::cout << item4 << std::endl;

  std::cout << item1 + item2;

  return 0;
}
