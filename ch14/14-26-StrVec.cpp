#include "14-26-StrVec.h"

void StrVec::push_back(const string &s)
{
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

void StrVec::resize(size_t n)
{
  resize(n, string());
}

void StrVec::resize(size_t n, const string &s)
{
  if (n > size())
  {
    reserve(n * 2);
    for (size_t i = size(); i != n; ++i)
      alloc.construct(first_free++, s);
  }

  else if (n < size())
  {
    while (first_free != elements + n)
      alloc.destroy(--first_free);
  }
}

void StrVec::reserve(size_t n)
{
  if (n <= capacity())
    return;
  alloc_n_move(n);
}

void StrVec::alloc_n_move(size_t n)
{
  auto newdata = alloc.allocate(n);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + n;
}

std::pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
  if (elements)
  {
    for (auto p = cap; p != elements;)
      alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}

void StrVec::initialize(const string *b, const string *e)
{
  auto newdata = alloc_n_copy(b, e);
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &rhs)
{
  initialize(rhs.begin(), rhs.end());
}

StrVec::StrVec(const std::initializer_list<string> &il)
{
  initialize(il.begin(), il.end());
}

StrVec::StrVec(StrVec &&rhs) noexcept
    : elements(rhs.elements),
      first_free(rhs.first_free),
      cap(rhs.cap)
{
  rhs.first_free = rhs.cap = rhs.elements = nullptr;
}

StrVec::~StrVec()
{
  free();
}

void StrVec::reallocate()
{
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;

  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

//operators
std::ostream &operator<<(std::ostream &os, const StrVec &str)
{
  for (const auto &s : str)
    os << s << std::endl;
  return os;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
  return (lhs.size() == rhs.size() &&
          std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
  return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
  auto iter1 = lhs.begin(), iter2 = rhs.begin();
  for (; iter1 != lhs.end() && iter2 != rhs.end(); ++iter1, ++iter2)
    if (*iter1 > *iter2)
      return false;
  return iter1 == lhs.end() && iter2 != rhs.end();
}

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
  return !(rhs < lhs);
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
  return rhs < lhs;
}

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
  return !(rhs > lhs);
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
  if (this != &rhs)
  {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.first_free = rhs.cap = rhs.elements = nullptr;
  }
  return *this;
}

StrVec &StrVec::operator=(const std::initializer_list<string> &il)
{
  free();
  initialize(il.begin(), il.end());
  return *this;
}

int main()

{
  StrVec v;
  v.push_back("hello");
  v.push_back("bye");
  std::cout << v[0] << " " << v[1];

  return 0;
}