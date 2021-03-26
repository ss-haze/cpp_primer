#include <string>
#include <iostream>

class Vehicle
{
public:
  friend std::ostream &operator<<(std::ostream &, const Vehicle &);
  friend std::istream &operator>>(std::istream &, Vehicle &);
  friend bool operator==(const Vehicle &, const Vehicle &);
  friend bool operator!=(const Vehicle &, const Vehicle &);

  Vehicle() = default;
  ~Vehicle() = default;
  Vehicle(std::string owner, std::string make, std::string number_plate, double price);

private:
  std::string owner_;
  std::string make_;
  std::string number_plate_;
  double price_;
};
std::ostream &operator<<(std::ostream &, const Vehicle &);
std::istream &operator>>(std::istream &, Vehicle &);
bool operator==(const Vehicle &, const Vehicle &);
bool operator!=(const Vehicle &, const Vehicle &);
