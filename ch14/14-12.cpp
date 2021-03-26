#include "14-12.h"

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
  is >> v.owner_ >> v.make_ >> v.number_plate_ >> v.price_;

  if (is)
    return is;
  else
  {
    v = Vehicle();
    return is;
  }
}

int main()
{
  Vehicle v1("O'Brien, Flannery", "Volvo", "HD 4583", 35000);
  Vehicle v2;

  std::cin >> v2;
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;

  return 0;
}