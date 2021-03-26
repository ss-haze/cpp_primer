#include "14-05.h"

Vehicle::Vehicle(std::string owner, std::string make, std::string number_plate, double price)
    : owner_(owner),
      make_(make),
      number_plate_(number_plate),
      price_(price)
{
}

std::ostream &operator<<(std::ostream &os, const Vehicle &v)
{
  return (os << v.owner_ << " " << v.make_ << " " << v.number_plate_ << " " << v.price_);
}

std::istream &operator>>(std::istream &is, Vehicle &v)
{
  return (is >> v.owner_ >> v.make_ >> v.number_plate_ >> v.price_);
}

bool operator==(const Vehicle &lhs, const Vehicle &rhs)
{
  return lhs.make_ == rhs.make_ &&
         lhs.number_plate_ == rhs.number_plate_ &&
         lhs.owner_ == rhs.owner_ &&
         lhs.price_ == rhs.price_;
}

bool operator!=(const Vehicle &lhs, const Vehicle &rhs)
{
  return !(lhs == rhs);
}

int main()
{
  Vehicle v1("O'Brien, Flannery", "Volvo", "HD 4583", 35000);
  Vehicle v2("O'Brien, Flannery", "Volvo", "HD 4583", 35000);
  Vehicle v3("O'Brien, Flloyd", "Mercedes", "HD 5959", 95000);

  //std::cin >> v2;
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;

  std::cout << (v1 == v2) << std::endl
            << (v2 == v3);

  return 0;
}