#include "16-03-sales_data.h"
#include <functional>

using std::cout;
using std::endl;
using std::less;
using std::string;

template <typename T>
int compare(const T &v1, const T &v2)
{
  if (less<T>()(v1, v2))
    return -1;
  if (less<T>()(v2, v1))
    return 1;
  return 0;
}

//the following code does not compile, since operator < is not defined for Sales_data objects

int main()
{
  Sales_data item1("Item1", 50, 10.0), item2("Item2", 20, 5.5);

  cout << compare(item1, item2);
  return 0;
}
