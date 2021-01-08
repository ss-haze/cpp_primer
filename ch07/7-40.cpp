#include <string>
#include <iostream>

class Vehicle
{
public:
  Vehicle(std::string id, std::string model, std::string name, double cost)
      : number_plate(id),
        make(model),
        owner(name),
        price(cost)
  {
  }

  Vehicle(std::istream &is)
  {
    is >> number_plate >> make >> owner >> price;
  }

private:
  std::string number_plate;
  std::string make;
  std::string owner;
  double price;
};