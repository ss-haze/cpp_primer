#include "String_move.h"

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