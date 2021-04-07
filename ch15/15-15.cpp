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

class Disc_quote : public Quote
{
public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double price, size_t qty, double disc)
      : Quote(book, price), quantity(qty), discount(disc) {}

  virtual double net_price(size_t cnt) const = 0;

protected:
  size_t quantity = 0;
  double discount = 0.0;
};

class BulkQuote : public Disc_quote
{
public:
  BulkQuote() = default;
  BulkQuote(const std::string &book, double p, size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}

  double net_price(size_t cnt) const override
  {
    if (cnt > quantity)
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }
  std::ostream &debug(std::ostream &os) const override
  {
    Quote::debug(os) << std::endl;
    os << "min_qty: " << quantity << std::endl
       << "discount: " << discount;
    return os;
  }
};

class LimitedQuote : public Disc_quote
{
public:
  LimitedQuote() = default;
  LimitedQuote(const std::string &book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}

  double net_price(size_t cnt) const override
  {
    if (cnt > quantity)
      return quantity * (1 - discount) * price + ((cnt - quantity) * price);
    else
      return cnt * (1 - discount) * price;
  }
  std::ostream &debug(std::ostream &os) const override
  {
    Quote::debug(os) << std::endl;
    os << "max_qty: " << quantity << std::endl
       << "discount: " << discount;
    return os;
  }
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " Total Sold: " << n << " Total due: " << ret << std::endl;
  return ret;
}

int main()
{
  Quote a("Quote Book       ", 5.99);
  BulkQuote b("BulkQuote Book   ", 5.99, 50, 0.2);
  LimitedQuote c("LimitedQuote Book", 5.99, 50, 0.2);

  print_total(std::cout, a, 100);
  print_total(std::cout, b, 100);
  print_total(std::cout, c, 100);
  return 0;
}