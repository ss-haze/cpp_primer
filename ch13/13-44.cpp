#include <memory>
#include <iostream>
#include <algorithm>

class String
{
public:
  String()
      : elements(nullptr),
        first_free(nullptr),
        cap(nullptr)
  {
  }
  String(const char *c);
  String(const String &rhs);
  String &operator=(const String &rhs);
  ~String();

  //methods
  void push_back(const char &c);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }

  void print()
  {
    for (auto iter = elements; iter != first_free; ++iter)
      std::cout << *iter;
  }

private:
  void free();
  void check_n_alloc();
  void reallocate();
  std::pair<char *, char *> alloc_n_copy(const char *b, const char *e);
  std::allocator<char> alloc;
  char *elements;
  char *first_free;
  char *cap;
};

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
}

String &String::operator=(const String &rhs)
{
  auto newdata = alloc_n_copy(rhs.elements, rhs.first_free);
  elements = newdata.first;
  cap = newdata.second;
  first_free = elements + (rhs.size());
  return *this;
}
int main()
{
  const char *c1 = "Hello!", *c2 = "Goodbye!";

  String s1(c1);
  s1.print();
  std::cout << std::endl;

  String s2(s1);
  s2.print();
  std::cout << std::endl;

  String s3(c2);
  s3.print();
  std::cout << std::endl;

  s3 = s2;
  s3.print();

  return 0;
}