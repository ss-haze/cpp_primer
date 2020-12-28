#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

class Person
{
  friend istream &read(istream &is, Person &item);

public:
  Person() = default;
  Person(const string &n) : name(n) {}
  Person(const string &n, const string &a) : name(n), address(a) {}
  Person(istream &is) { read(is, *this); }

  string getName() const { return name; }
  string getAddress() const { return address; }

private:
  string name;
  string address;
};

ostream &print(ostream &os, Person &item)
{
  return os << item.getName() << " " << item.getAddress();
}

istream &read(istream &is, Person &item)
{
  return is >> item.name >> item.address;
}

int main()
{
  Person p1("Jim");
  Person p2("John", "England");
  Person p3;
  Person p4(std::cin);

  print(std::cout, p1) << std::endl;
  print(std::cout, p2) << std::endl;
  print(std::cout, p3) << std::endl;
  print(std::cout, p4) << std::endl;

  return 0;
}