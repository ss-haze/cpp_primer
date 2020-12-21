#include <iostream>
#include <string>

using std::string;

int main(int argc, char *argv[]) {
    
  for (int i = 0; i < argc; ++i)
    std::cout << i << "\t" << argv[i] << std::endl;

  string s= "hello";
  string *sp = &s;
    std::cout <<*sp<<std::endl;

    const char c[] = "how";
    std::cout <<*c<<std::endl;

   
  return 0;
}