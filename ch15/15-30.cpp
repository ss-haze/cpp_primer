#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>

using std::cout;
using std::shared_ptr;
using std::string;

class Quote
{
public:
  //constructors
  Quote(){};
  Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
  virtual ~Quote() {}

  //copy control
  Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) {}
  Quote(Quote &&rhs) : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {}
  Quote &operator=(const Quote &rhs)
  {
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
  }

  Quote &operator=(Quote &&rhs)
  {
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    return *this;
  }

  //methods
  string isbn() const { return bookNo; }
  virtual Quote *clone() const & { return new Quote(*this); }
  virtual Quote *clone() && { return new Quote(std::move(*this)); }
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
  Disc_quote() {}
  Disc_quote(const std::string &book, double price, size_t qty, double disc)
      : Quote(book, price), quantity(qty), discount(disc) {}

  //copy control
  Disc_quote(const Disc_quote &rhs) : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {}

  Disc_quote(Disc_quote &&rhs) : Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount)) {}

  Disc_quote &operator=(const Disc_quote &rhs)
  {
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
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
  BulkQuote() {}
  using Disc_quote::Disc_quote;

  //copy control
  BulkQuote(const BulkQuote &rhs) : Disc_quote(rhs) {}

  BulkQuote(BulkQuote &&rhs) : Disc_quote(std::move(rhs)) {}

  BulkQuote &operator=(const BulkQuote &rhs)
  {
    Disc_quote::operator=(rhs);
    return *this;
  }

  //methods
  BulkQuote *clone() const & override { return new BulkQuote(*this); }
  BulkQuote *clone() && override { return new BulkQuote(std::move(*this)); }
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

double print_total(std::ostream &os, const Quote &item, size_t n)
{
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " Total Sold: " << n << " Total due: " << ret << std::endl;
  return ret;
}

class Basket
{
public:
  void add_item(const Quote &sale)
  {
    cout << "Quote& sale used\n";
    items.insert(shared_ptr<Quote>(sale.clone()));
  }
  void add_item(Quote &&sale)
  {
    cout << "Quote&& sale used\n";
    items.insert(shared_ptr<Quote>(std::move(sale).clone()));
  }

  double total_receipt(std::ostream &os) const
  {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
      sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
  }

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
  {
    return lhs->isbn() < rhs->isbn();
  }

  std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

int main()
{

  Basket bsk;
  Quote q("100", 10);
  bsk.add_item(q);
  bsk.add_item(Quote("123", 45));
  bsk.add_item(BulkQuote("321", 10, 1, 0.1));
  bsk.add_item(BulkQuote("321", 10, 10, 0.1));

  bsk.total_receipt(std::cout);

  return 0;
}