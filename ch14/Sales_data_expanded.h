#include <string>
#include <iostream>

class Sales_data
{
  friend Sales_data operator+(const Sales_data &, const Sales_data &);
  friend Sales_data operator-(const Sales_data &, const Sales_data &);
  friend std::istream &operator>>(std::istream &, Sales_data &);
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);

public:
  //constructors
  Sales_data(const std::string &no, unsigned us, double price)
      : bookNo(no), units_sold(us), revenue(price * us) {}
  Sales_data() : Sales_data("", 0, 0) {}
  Sales_data(const std::string &n) : Sales_data(n, 0, 0) {}
  Sales_data(std::istream &is) : Sales_data() { is >> *this; }

  //Class operators
  Sales_data &operator+=(const Sales_data &);
  Sales_data &operator-=(const Sales_data &);

  //Conversion Operators
  explicit operator std::string () {return bookNo;}
  explicit operator double () {return avg_price();}

  //member functions
  std::string isbn() const { return bookNo; }

private:
  double avg_price() const;

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data operator+(const Sales_data &, const Sales_data &);
Sales_data operator-(const Sales_data &, const Sales_data &);
std::istream &operator>>(std::istream &, Sales_data &);
std::ostream &operator<<(std::ostream &, const Sales_data &);
