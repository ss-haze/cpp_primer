#include <string>
#include <iostream>

using std::cout;
using std::ostream;
using std::string;

class Date
{
public:
  friend ostream &print(ostream &os, Date &d);

  Date(const string &s);
  Date() = default;

private:
  unsigned day = 0;
  unsigned month = 0;
  unsigned year = 0;
};

Date::Date(const string &s)
{
  string symbols = "0123456789,/ ", separators = "/, ", nums = "0123456789";

  if (s.find_first_not_of(symbols) != string::npos)
  {
    if (s.find("Jan") != string::npos)
      month = 1;
    else if (s.find("Feb") != string::npos)
      month = 2;
    else if (s.find("Mar") != string::npos)
      month = 3;
    else if (s.find("Apr") != string::npos)
      month = 4;
    else if (s.find("May") != string::npos)
      month = 5;
    else if (s.find("Jun") != string::npos)
      month = 6;
    else if (s.find("Jul") != string::npos)
      month = 7;
    else if (s.find("Aug") != string::npos)
      month = 8;
    else if (s.find("Sep") != string::npos)
      month = 9;
    else if (s.find("Oct") != string::npos)
      month = 10;
    else if (s.find("Nov") != string::npos)
      month = 11;
    else if (s.find("Dec") != string::npos)
      month = 12;
  }
  string::size_type pos1 = s.find_first_of(separators), pos2 = s.find_last_of(separators), pos3 = pos2 - pos1;
  string d = s.substr(pos1 + 1, pos3 - 1);
  string y = s.substr(pos2 + 1);
  string m = s.substr(0, pos1);
  cout << " m is :" << m << std::endl;

  if (m.find_first_not_of(nums) == string::npos)
    month = stoi(m);
  day = stoi(d);
  year = stoi(y);
}

ostream &print(ostream &os, Date &d)
{
  os << "Month: " << d.month << "\tDay: " << d.day << "\t\tYear: " << d.year;
  return os;
}

int main()
{

  Date date1("Mar,15,2020"), date2("February 3 1900"), date3("Aug/5/2010"), date4("1/5/1945");
  print(std::cout, date1) << std::endl;
  print(std::cout, date2) << std::endl;
  print(std::cout, date3) << std::endl;
  print(std::cout, date4) << std::endl;

  return 0;
}