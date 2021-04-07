#include <iostream>
#include <string>

class Base
{
public:
  Base() = default;
  Base(int x_in, int y_in) : x(x_in), y(y_in) {}

  void print()
  {
    std::cout << x << " " << y << " " << z << " "
              << "base print called\n";
  }
  virtual void vprint() { std::cout << "base vprint called\n"; }

  virtual void tprint() { std::cout << "tprint in base called\n"; }

private:
  int x = 50;

protected:
  int y = 50;

public:
  int z = 500;
};

class Derived : public Base
{
public:
  Derived() = default;
  Derived(int d) : dd(d) {}

  void vprint() override
  {
    std::cout << "Derived vprint called\n";
  }

private:
  int dd;
};

void tester(Base *basep)
{
  basep->Base::vprint();
}

main()
{
  Derived d(10);

  tester(&d);
  Base b;
  tester(&b);

  return 0;
}