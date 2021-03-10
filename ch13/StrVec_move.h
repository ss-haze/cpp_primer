#include <iostream>
#include <string>
#include <memory>
#include <initializer_list>
#include <utility>

using std::string;

class StrVec
{
public:
  //constructors
  StrVec()
      : elements(nullptr),
        first_free(nullptr),
        cap(nullptr) {}

  StrVec(StrVec &&rhs) noexcept;
  StrVec(const StrVec &);
  StrVec(const std::initializer_list<string> &);
  ~StrVec();
  StrVec &operator=(StrVec &&rhs) noexcept;
  StrVec &operator=(const StrVec &rhs);

  //methods
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  void push_back(const string &s);
  string *begin() const { return elements; }
  string *end() const { return cap; }
  const string &get_elem(size_t n) const { return *(elements + n); }

private:
  void chk_n_alloc()
  {
    if (size() == capacity())
      reallocate();
  }

  std::pair<string *, string *> alloc_n_copy(const string *, const string *);
  void initialize(const string *, const string *);
  void free();
  void reallocate();
  void reserve(size_t n);
  void alloc_n_move(size_t);
  void resize(size_t size);
  void resize(size_t size, const string &s);
  std::allocator<string> alloc;
  string *elements;
  string *first_free;
  string *cap;
};