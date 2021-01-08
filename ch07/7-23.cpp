#include <string>

class Screen
{
  public:
    typedef std::string::size_type pos;
    Screen()=default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents (ht*wd, c){}

    char get() const { return contents[cursor]; }
    inline char get (pos ht, pos wd) const;
    Screen& move (pos r, pos c);

  private:
    pos height =0, width=0, cursor =0;
    std::string contents;
};

inline Screen& Screen::move (pos r, pos c)
{
  cursor = r * width + c;
  return *this;
}

char Screen::get(pos ht, pos wd) const
{
  return contents[ht*width + wd];
}