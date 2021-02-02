#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <array>
#include <initializer_list>
using std::array;
using std::cout;
using std::vector;

int main(int argc, char **argv)
{

  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

std::initializer_list<int> il {1,2,3};


  vector<int> v1 = {il};
 

for (const auto i:v1)cout <<i<< " ";
      return 0;
}