#include <memory>
#include <iostream>
#include <algorithm>

class String
{
public:
  friend std::ostream &operator<<(std::ostream &, const String &);
  friend bool operator==(const String &, const String &);
  friend bool operator!=(const String &, const String &);
  friend bool operator<(const String &, const String &);
  friend bool operator<=(const String &, const String &);
  friend bool operator>(const String &, const String &);
  friend bool operator>=(const String &, const String &);

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

private:
  void free();
  void check_n_alloc();
  void reallocate();
  std::pair<char *, char *> alloc_n_copy(const char *b, const char *e);
  char *begin() { return elements; }
  char *end() { return first_free; }
  const char *begin() const { return elements; }
  const char *end() const { return first_free; }
  const char *cbegin() const { return elements; }
  const char *cend() const { return first_free; }

  std::allocator<char> alloc;
  char *elements;
  char *first_free;
  char *cap;
};

std::ostream &operator<<(std::ostream &, const String &);
bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator<(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>(const String &, const String &);
bool operator>=(const String &, const String &);