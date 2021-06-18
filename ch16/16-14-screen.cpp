#include <string>
#include <iostream>

/* template <unsigned H, unsigned W>
class Screen;

template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &, const Screen<H, W> &);

template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &, Screen<H, W> &); */

template <unsigned H, unsigned W>
class Screen
{
  template <unsigned H_U, unsigned W_U>
  friend std::ostream &operator<<(std::ostream &, const Screen<H_U, W_U> &);

  template <unsigned H_U, unsigned W_U>
  friend std::istream &operator>>(std::istream &, Screen<H_U, W_U> &);

public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(char c) : contents(H * W, c) {}

  char get() const { return contents[cursor]; }
  Screen &move(pos r, pos c);

private:
  pos cursor = 0;
  pos height = H;
  pos width = W;
  std::string contents = std::string(H * W, '*');
};

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c)
{
  pos row = r * width;
  cursor = row + c;
  return *this;
}

template <unsigned H, unsigned W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &s)
{
  os << s.contents;
  return os;
}

template <unsigned H, unsigned W>
std::istream &operator>>(std::istream &is, Screen<H, W> &s)
{
  char c;
  is >> c;
  std::string temp(W * H, c);
  s.contents = temp;
  return is;
}

int main()
{
  Screen<20, 10> s;

  std::cout << s << std::endl;
  std::cin >> s;
  std::cout << s;

  return 0;
}
