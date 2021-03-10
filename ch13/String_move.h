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
  String(String &&rhs) noexcept;
  String &operator=(const String &rhs);
  String &operator=(String &&rhs) noexcept;
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