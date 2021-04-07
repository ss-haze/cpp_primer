#include <iostream>
#include <string>
using std::string;

class Quote
{
public:
  Quote() = default;
  Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
  virtual ~Quote();

  string isbn() const { return bookNo; }
  virtual double net_price(size_t cnt) const { return cnt * price; }

private:
  string bookNo;

protected:
  double price = 0.0;
};

class BulkQuote : public Quote
{
public:
  BulkQuote() = default;
  BulkQuote(const std::string &, double, std::size_t, double);

  double net_price(size_t cnt) const { if (cnt>min_qty) return cnt * (1 - discount) * price; else return cnt*price;}

private:
  size_t min_qty = 0;
  double discount = 0.0;
};

int main()
{

  return 0;
}