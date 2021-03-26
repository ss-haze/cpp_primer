#include "14-45-Sales_data.h"

int main()
{
  Sales_data book1("The Merchant Of Venice", 100, 5.99), book2;
  std::cout << book1 << std::endl;
  std::cout << "Shakespeare wrote " + static_cast<std::string>(book1) << std::endl;
  std::cout << "The books costs " << static_cast<double>(book1) << std::endl;
  if (book1)
    std::cout << "All done!";
  if (book2)
    std::cout << "This will not be printed";
  else
    std::cout << "This book is empty";

  return 0;
}