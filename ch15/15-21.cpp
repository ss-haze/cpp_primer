#include <string>
#include <iostream>

using std::ostream;
using std::string;

class Shape
{
public:
  Shape() = default;
  Shape(string &s)
      : name_(s)
  {
  }
  virtual ~Shape() = default;

  virtual int area() const = 0;
  virtual int perimeter() const = 0;

  string get_name() const { return name_; }

private:
  string name_;
};

class Rectangle : public Shape
{
public:
  Rectangle() = default;
  Rectangle(string s, int top, int bottom, int left, int right)
      : Shape(s), top_(top), bottom_(bottom), left_(left), right_(right) {}

  int area() const override { return top_ * left_; }
  int perimeter() const override { return top_ + bottom_ + left_ + right_; }

private:
  int top_;
  int bottom_;
  int left_;
  int right_;
};

class Triangle : public Shape
{
public:
  Triangle() = default;
  Triangle(string s, int base, int opposite, int hypotenuse)
      : Shape(s),
        base_(base),
        opposite_(opposite),
        hypotenuse_(hypotenuse)
  {
  }

  int area() const override { return perimeter() * 0.5; }
  int perimeter() const override { return base_ + opposite_ + hypotenuse_; }

private:
  int base_;
  int opposite_;
  int hypotenuse_;
};

ostream &print_out(ostream &os, Shape &s)
{
  os << "name: " << s.get_name() << std::endl
     << "perimeter length: " << s.perimeter() << std::endl
     << "area: " << s.area();
  return os;
}

int main()
{
  Triangle t1("tri1", 3, 4, 5);
  Rectangle r1("Rect1", 5, 5, 3, 3);

  print_out(std::cout, t1) << std::endl;
  print_out(std::cout, r1) << std::endl;

  return 0;
}