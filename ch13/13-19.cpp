#include <string>
#include <iostream>

class Employee
{
public:
  Employee()
      : identifier(0)
  {
  }

  Employee(const std::string &s)
      : name(s),
        identifier(++serial)
  {
  }

  Employee(const Employee &rhs) = delete;

  Employee &operator=(const Employee &rhs) = delete;

  void print()
  {
    std::cout << name << " " << identifier << std::endl;
  }

private:
  std::string name = "John Doe";
  size_t identifier = 0;
  static size_t serial;
};

size_t Employee::serial = 0;

int main()
{
  Employee a;
  Employee b("Jamal");

  a.print();
  b.print();

  // Employee c = a;  Copy constructor deleted. Command not possible
  // a=b;   Assignment operator deleted. Command not possible

  return 0;
}