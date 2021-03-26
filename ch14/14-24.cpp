#include "14-24.h"
#include <utility>

Vehicle::Vehicle(std::string owner, std::string make, std::string number_plate, double price)
    : owner_(owner),
      make_(make),
      number_plate_(number_plate),
      price_(price)
{
}

Vehicle::Vehicle(const Vehicle &rhs)
    : owner_(rhs.owner_),
      make_(rhs.make_),
      number_plate_(rhs.number_plate_),
      price_(rhs.price_)
{
  std::cout << "Copy Constructor Invoked\n";
}

Vehicle::Vehicle(Vehicle &&rhs)
    : owner_(rhs.owner_),
      make_(rhs.make_),
      number_plate_(rhs.number_plate_),
      price_(rhs.price_)
{
  rhs = Vehicle();
  std::cout << "Move Constructor Invoked\n";
}

Vehicle &Vehicle::operator=(const Vehicle &rhs)
{
  this->owner_ = rhs.owner_;
  this->make_ = rhs.make_;
  this->number_plate_ = rhs.number_plate_;
  this->price_ = rhs.price_;
  return *this;
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
  Vehicle v2(v1);

  std::cout << v2 << std::endl;

  Vehicle v3(std::move(v2));

  std::cout << v3 << std::endl;

  std::cout << v2 << std::endl;

  return 0;
}