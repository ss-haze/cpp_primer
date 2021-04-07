#include <iostream>
#include <string>
using std::string;

class Quote
{
public:
  Quote() = default;
  Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
  virtual ~Quote() = default;

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
  BulkQuote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {}

  double net_price(size_t cnt) const override
  {
    if (cnt > min_qty)
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }

private:
  size_t min_qty = 0;
  double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " Total Sold: " << n << " Total due: " << ret << std::endl;
  return ret;
}

int main()
{
  Quote a("Quote Book    ", 5.99);
  print_total(std::cout, a, 100);

  BulkQuote b("BulkQuote Book", 5.99, 500, 0.2);
  print_total(std::cout, b, 100);

  return 0;
}