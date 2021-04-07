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
  virtual std::ostream &debug(std::ostream &os) const
  {
    os << "bookNo: " << bookNo << std::endl
       << "price: " << price;
    return os;
  }

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
  std::ostream &debug(std::ostream &os) const override
  {
    Quote::debug(os) << std::endl;
    os << "min_qty: " << min_qty << std::endl
       << "discount: " << discount;
    return os;
  }

private:
  size_t min_qty = 0;
  double discount = 0.0;
};

class LimitedQuote : public Quote
{
public:
  LimitedQuote() = default;
  LimitedQuote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), max_qty(qty), discount(disc) {}

  double net_price(size_t cnt) const override
  {
    if (cnt > max_qty)
      return max_qty * (1 - discount) * price + ((cnt - max_qty) * price);
    else
      return cnt * (1 - discount) * price;
  }
  std::ostream &debug(std::ostream &os) const override
  {
    Quote::debug(os) << std::endl;
    os << "max_qty: " << max_qty << std::endl
       << "discount: " << discount;
    return os;
  }

private:
  size_t max_qty = 0;
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
  a.debug(std::cout) << std::endl;

  BulkQuote b("BulkQuote Book", 5.99, 50, 0.2);
  b.debug(std::cout) << std::endl;

  LimitedQuote c("LimitedQuote Book", 5.99, 100, 0.2);
  c.debug(std::cout) << std::endl;

  return 0;
}