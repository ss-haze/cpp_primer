#include "14-26-string.h"

void String::reallocate()
{
  auto newCapacity = size() ? 2 * size() : 1;
  auto newData = alloc.allocate(newCapacity);
  auto elem = elements;
  auto dest = newData;

  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  first_free = dest;
  elements = newData;
  cap = elements + newCapacity;
}

void String::check_n_alloc()
{
  if (size() == capacity())
    reallocate();
}

String::String(const char *c)
    : elements(nullptr),
      first_free(nullptr),
      cap(nullptr)
{
  auto iter = c;
  while (*iter != '\0')
    push_back(*iter++);
}

void String::push_back(const char &c)
{
  check_n_alloc();
  alloc.construct(first_free++, c);
}

String::~String()
{
  free();
}

void String::free()
{
  if (elements)
  {
    std::for_each(elements, first_free, [this](const char &c) { alloc.destroy(&c); });
    alloc.deallocate(elements, cap - elements);
  }
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
  auto newdata = alloc.allocate(e - b);
  return {newdata, std::uninitialized_copy(b, e, newdata)};
}

String::String(const String &rhs)
{
  auto newdata = alloc_n_copy(rhs.elements, rhs.cap);
  elements = newdata.first;
  cap = newdata.second;
  first_free = elements + (rhs.size());
  std::cout << "copy constructor used\n";
}

String::String(String &&rhs) noexcept
    : elements(rhs.elements),
      first_free(rhs.first_free),
      cap(rhs.cap)
{
  rhs.elements = rhs.cap = rhs.first_free = nullptr;
  std::cout << "Move constructor invoked\n";
}

String &String::operator=(String &&rhs) noexcept
{
  if (this != &rhs)
  {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = rhs.cap = rhs.first_free = nullptr;
  }
  std::cout << "Move assignment operator invoked\n";
  return *this;
}

String &String::operator=(const String &rhs)
{
  auto newdata = alloc_n_copy(rhs.elements, rhs.first_free);
  free();
  elements = newdata.first;
  cap = newdata.second;
  first_free = elements + (rhs.size());
  std::cout << "copy assignment operator used\n";
  return *this;
}

//output operator
std::ostream &operator<<(std::ostream &os, const String &s)
{
  for (auto iter = s.elements; iter != s.first_free; ++iter)
    os << *iter;
  return os;
}

//equality operators
bool operator==(const String &lhs, const String &rhs)
{
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const String &lhs, const String &rhs)
{
  return !(lhs == rhs);
}

//relational operators
bool operator<(const String &lhs, const String &rhs)
{
  auto iter1 = lhs.begin(), iter2 = rhs.begin();
  for (; iter1 != lhs.end() && iter2 != rhs.end(); ++iter1, ++iter2)
    if (*iter1 > *iter2)
      return false;
  return iter1 == lhs.end() && iter2 != rhs.end();
}

bool operator<=(const String &lhs, const String &rhs)
{
  return !(rhs < lhs);
}

bool operator>(const String &lhs, const String &rhs)
{
  return rhs < lhs;
}

bool operator>=(const String &lhs, const String &rhs)
{
  return !(rhs > lhs);
}

int main()
{
  String s1("hell");
  const String s2("big");

  std::cout << s1[1] << std::endl;
  std::cout << s2[1] << std::endl;

  s1[0] = 'w';
  std::cout << s1 << std::endl;

  // s2[2] = 'n';   cannot write to const
  std::cout << s2;

  return 0;
}