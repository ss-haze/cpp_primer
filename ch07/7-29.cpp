#include <string>
#include <iostream>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht* wd, c) {}
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht* wd, ' ') {}

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen& move(pos r, pos c);
    Screen& set(char c);
    Screen& set(pos r, pos col, char c);
    Screen& display(std::ostream& os) { do_display(os); return *this; }
    const Screen& display(std::ostream& os) const { do_display(os); return *this; }

private:
    void do_display(std::ostream& os) const { os << contents; }
    pos height = 0, width = 0, cursor = 0;
    std::string contents;
};

Screen& Screen::set(char c) { contents[cursor] = c; return *this; }

Screen& Screen::set(pos r, pos col, char c) { contents[r * width + col] = c; return *this; }

inline Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos ht, pos wd) const
{
    pos row = ht * width;
    return contents[row + wd];
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout <<"\n";
    myScreen.display(std::cout);
    return 0;
}