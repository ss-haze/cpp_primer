#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

struct Person
{
  string getName() const { return name; }
  string getAddress() const { return address; }

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
  Person p1;
  read(std::cin, p1);
  print(std::cout, p1);
  return 0;
}