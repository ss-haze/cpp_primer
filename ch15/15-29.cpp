#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::shared_ptr;
using std::string;

class Quote
{
public:
  //constructors
  Quote() { cout << "Quote default Constructor invoked\n"; };
  Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { cout << "Quote (const string &book, double sales_price) invoked\n"; }
  virtual ~Quote() { cout << "Quote destructor invoked\n"; }

  //copy control
  Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) { cout << "Quote copy constructor invoked\n"; }
  Quote(Quote &&rhs) : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) { cout << "Quote move constructor invoked\n"; }
  Quote &operator=(const Quote &rhs)
  {
    bookNo = rhs.bookNo;
    price = rhs.price;
    cout << "Quote operator = invoked\n";
    return *this;
  }

  Quote &operator=(Quote &&rhs)
  {
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    cout << "Quote move operator = invoked\n";
    return *this;
  }

  //methods
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
  //constructors
  Disc_quote() { "Disc_quote default constructor invoked\n"; }
  Disc_quote(const std::string &book, double price, size_t qty, double disc)
      : Quote(book, price), quantity(qty), discount(disc) { cout << "Disc_quote(const std::string &book, double price, size_t qty, double disc) constructor invoked\n"; }

  //copy control
  Disc_quote(const Disc_quote &rhs) : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) { cout << "Disc_Quote copy constructor invoked\n"; }

  Disc_quote(Disc_quote &&rhs) : Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount)) { cout << "Disc_Quote move constructor invoked\n"; }

  Disc_quote &operator=(const Disc_quote &rhs)
  {
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    cout << "Disc_quote operator= invoked\n";
    return *this;
  }

  //methods
  virtual double net_price(size_t cnt) const = 0;

protected:
  size_t quantity = 0;
  double discount = 0.0;
};

class BulkQuote : public Disc_quote
{
public:
  //constructors
  BulkQuote() { cout << "BulkQuote default constructor invoked\n"; }
  using Disc_quote::Disc_quote;

  //copy control
  BulkQuote(const BulkQuote &rhs) : Disc_quote(rhs) { cout << "BulkQuote copy constructor invoked\n"; }

  BulkQuote(BulkQuote &&rhs) : Disc_quote(std::move(rhs)) { cout << "BulkQuote move constructor invoked\n"; }

  BulkQuote &operator=(const BulkQuote &rhs)
  {
    Disc_quote::operator=(rhs);
    cout << "BulkQuote operator = invoked\n";
    return *this;
  }

  //methods
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

  std::vector<shared_ptr<Quote>> v;

  v.push_back(std::make_shared<BulkQuote>("test", 10, 10, 0.2));
  v.push_back(std::make_shared<BulkQuote>("test2", 10, 10, 0.4));

  double total_price = 0.0;
  for (const auto &it : v)
    total_price += it->net_price(20);
  cout << "\nTotal net price of vector items: " << total_price << std::endl;

  return 0;
}