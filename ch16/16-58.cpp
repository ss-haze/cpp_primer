#include <iostream>
#include <string>
#include <memory>
#include <utility>

template<typename T>
class Vec
{
public:
  //constructors
  Vec()
      : elements(nullptr),
        first_free(nullptr),
        cap(nullptr) {}

  Vec(const Vec&);
  ~Vec();
  Vec &operator=(const Vec &rhs);

  //methods
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  void push_back(const T& t);
  T* begin() const { return elements; }
  T* end() const { return cap; }
  template <typename... Args> void emplace_back(Args&&... args);    //new emplace method declaration

private:
  void chk_n_alloc()
  {
    if (size() == capacity())
      reallocate();
  }

  std::pair<T*, T*> alloc_n_copy(const T *b,const T * e); 
  void free();
  void reallocate();
  void reserve(size_t n);
  void alloc_n_move(size_t);
  void resize(size_t size);
  void resize(size_t size, const T& t);
  std::allocator<T> alloc;
  T *elements;
  T *first_free;
  T *cap;
};

template<typename T>
void Vec<T>::push_back(const T& t)
{
  chk_n_alloc();
  alloc.construct(first_free++, t);
}

template<typename T>
void Vec<T>::resize(size_t n)
{
  resize(n, T());
}


//new emplace back fn definition
template <typename T> 
template <typename... Args>
inline void Vec<T>::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}


template<typename T>
void Vec<T>::resize(size_t n, const T& t)
{
  if (n > size())
  {
    reserve(n * 2);
    for (size_t i = size(); i != n; ++i)
      alloc.construct(first_free++, t);
  }

  else if (n < size())
  {
    while (first_free != elements + n)
      alloc.destroy(--first_free);
  }
}

template <typename T>
void Vec<T>::reserve(size_t n)
{
  if (n <= capacity())
    return;
  alloc_n_move(n);
}


template <typename T>
void Vec<T>::alloc_n_move(size_t n)
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

template <typename T>
std::pair<T*,  T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
  if (elements)
  {
    for (auto p = cap; p != elements;)
      alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
  }
}

template <typename T>
Vec<T>::Vec(const Vec &rhs)
{
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec()
{
  free();
}

template <typename T>
Vec<T> & Vec<T>::operator=(const Vec &rhs)
{
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}

template <typename T>
void Vec<T>::reallocate()
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

int main()
{
      Vec<std::string> v;
	v.emplace_back("test string");
	v.emplace_back(10, 'c');
	v.emplace_back(std::string("another test string"));
	for (const auto &elem : v)
		std::cout << elem << '\n';

  return 0;
}
