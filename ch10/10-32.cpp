#include "Sales_item.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>

bool compareIsbn(const Sales_item &item1, const Sales_item &item2)
{
  return item1.isbn() < item2.isbn();
}

int main()
{

  std::vector<Sales_item> v{std::istream_iterator<Sales_item>(std::cin), std::istream_iterator<Sales_item>()};

  std::sort(v.begin(), v.end(), compareIsbn);

  for (auto b = v.begin(), e = b; b != v.end(); b = e)
  {
    e = std::find_if(b, v.end(), [b](const Sales_item &item) { return item.isbn() != b->isbn(); });

    std::cout << std::accumulate(b, e, Sales_item(b->isbn())) << std::endl;
    //Initial value for accumulate cannot be Sales_item(), since this temp has no isbn string,
    //and this temp will be copied and returned by the overloaded + operator for Sales_item
  }

  return 0;
}