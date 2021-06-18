#include <iostream>
#include <string>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

template <typename T, typename U>

T match(const T &start, const T &end, const U &item)
{
  auto iter = start;
  for (; iter != end; ++iter)
  {
    if (*iter == item)
      break;
  }
  return iter;
}

template <typename T, typename U>
void print_result(const T &iter, const U &container)
{
  if (iter == container.end())
    cout << "The item was not found\n";
  else
    cout << "The item was found\n";
}

int main()
{
  vector<int> vi{1, 2, 3, 4, 5};
  print_result((match(vi.cbegin(), vi.cend(), 3)), vi);
  print_result((match(vi.cbegin(), vi.cend(), 33)), vi);

  list<string> ls{"yes", "no", "up", "down", "hello", "bye"};
  print_result((match(ls.cbegin(), ls.cend(), "hello")), ls);
  print_result((match(ls.cbegin(), ls.cend(), "perhaps")), ls);

  return 0;
}