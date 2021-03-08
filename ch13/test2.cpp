#include <iostream>
#include <string>
#include <memory>
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

  StrVec(const string &s);
  ~StrVec();
  StrVec &operator=(const StrVec &rhs);

  //methods
  size_t size() const { return cap - elements; }
  size_t capacity() const { return cap - first_free; }
  void push_back(const string &s);
  string* begin() const {return elements;}
  string* end() const {return cap;}

private:
  void chk_n_alloc()
  {
    if (size() == capacity())
      reallocate();
  }
  std::pair<string *, string *> alloc_n_copy(const string *, const string *);
  void free();
  void reallocate();
  std::allocator<string> alloc;
  string *elements;
  string *first_free;
  string *cap;
};

void StrVec::push_back(const string& s)
{
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

std::pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
  auto const data = alloc.allocate(e-b);
  return {data, std::uninitialized_copy(b, e, data)}; 
}

void StrVec::free()
{
 if (elements)
 {
   for (auto p=cap; p!=elements;)
 alloc.destroy(--p);
 alloc.deallocate(elements, cap-elements);
 }
}

StrVec::StrVec( const StrVec& rhs)
{
  auto newdata = alloc_n_copy (rhs.begin(), rhs.end());
  elements=newdata.first;
  first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
  free();
}

StrVec& StrVec::operator = (const StrVec& rhs)
{
auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
free();
elements=newdata.first;
first_free = cap = newdata.second;
return *this;
}

void StrVec::reallocate()
{
  auto newcapacity = size() ? 2*size():1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;

  for (size_t i = 0; i != size(); ++i)
  alloc.construct(dest++, std::move(*elem++));
  elements=newdata;
  first_free=dest;
  cap=elements + newcapacity;

}