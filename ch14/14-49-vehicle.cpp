#include "14-49-vehicle.h"

Vehicle::Vehicle(std::string owner, std::string make, std::string number_plate, double price, bool electric)
    : owner_(owner),
      make_(make),
      number_plate_(number_plate),
      price_(price),
      electric_(electric)
{
}

std::ostream &operator<<(std::ostream &os, const Vehicle &v)
{
  return (os << v.owner_ << " " << v.make_ << " " << v.number_plate_ << " " << v.price_ << " " << v.electric_);
}

std::istream &operator>>(std::istream &is, Vehicle &v)
{
  return (is >> v.owner_ >> v.make_ >> v.number_plate_ >> v.price_ >> v.electric_);
}

bool operator==(const Vehicle &lhs, const Vehicle &rhs)
{
  return lhs.make_ == rhs.make_ &&
         lhs.number_plate_ == rhs.number_plate_ &&
         lhs.owner_ == rhs.owner_ &&
         lhs.price_ == rhs.price_ &&
         lhs.electric_ == rhs.electric_;
}

bool operator!=(const Vehicle &lhs, const Vehicle &rhs)
{
  return !(lhs == rhs);
}

int main()
{
  Vehicle v1("O'Brien, Flannery", "Volvo", "HD 4583", 35000);

  Vehicle v2("Leotard, Francois", "Renault 5", "Fra PM01", 40000, true);

  if (v1)
    std::cout << "The following car is electric: " << v1 << std::endl;
  else
    std::cout << "The following car is not electric: " << v1 << std::endl;

  if (v2)
    std::cout << "The following car is electric: " << v2 << std::endl;
  else
    std::cout << "The following car is not electric: " << v2 << std::endl;
}