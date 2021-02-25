#include "StrBlobUpdated.h"
#include "StrBlobPtr.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
  std::ifstream ifs("string_data.txt");
  if (!ifs)
    std::cerr << "Could not open file";
  StrBlob s;
  std::string input;
  std::istringstream iss;
  while (std::getline(ifs, input))
  {
    iss.str(input);
    std::string word;
    while (iss >> word)
      s.push_back(word);
    iss.clear();
  }

  auto iter = s.begin();

  for (decltype(s.size()) b = 0; b != s.size(); ++b)
  {
    std::cout << iter.deref() << " ";
    iter.incr();
  }

  return 0;
}
