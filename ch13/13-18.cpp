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

  return 0;
}