#include <string>
#include <cstring>
#include <memory>
#include <iostream>

int main()
{
  const char c1[] = "Hello";
  const char c2[] = "There";

  char *final_string = new char
      [strlen(c1) + strlen(c2) + 1] ();

  std::cout << strcat (strcat(final_string, c1),  c2) <<std::endl;

  delete[] final_string;

std::string s1 = "Hello", s2 = "There";

std::cout << s1 + s2;
  return 0;
}