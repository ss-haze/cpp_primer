#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <initializer_list>
#include <string>
#include <memory>
#include <exception>

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob
{
  friend class BlobPtr<T>;
  friend bool operator==<T>(const Blob<T> &, const Blob<T> &);

public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;

  //constructors
  Blob();
  Blob(std::initializer_list<T> il);
  template<typename It> Blob (It b, It e);

  //number of elements in Blob
  size_type size() { return data->size(); }
  bool empty() { return data->empty(); }

  //add and remove elements
  void push_back(const T &t) { data->push_back(t); }
  void push_back(T &&t) { data->push_back(std::move(t)); }
  void pop_back();

  //element access
  T &back();
  T &front();
  const T &front() const;
  const T &back() const;
  T &operator[](size_type i);

private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string &msg) const;
};



//constructors
template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
template <typename It> Blob<T>::Blob (It b, It e) :
data (std::make_shared<std::vector<T>>(b,e)) {}

//check
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
  if (i >= data->size())
    throw std::out_of_range(msg);
}

//member access
template <typename T>
T &Blob<T>::operator[](size_type i)
{
  check(i, "subscript is out of range");
  return (*data)[i];
}

template <typename T>
T &Blob<T>::back()
{
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T>
const T &Blob<T>::back() const
{
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T>
T &Blob<T>::front()
{
  check(0, "front on empty Blob");
  return data->front();
}

template <typename T>
const T &Blob<T>::front() const
{
  check(0, "front on empty Blob");
  return data->front();
}

//add and remove elements
template <typename T>
void Blob<T>::pop_back()
{
  check(0, "pop_back on empty Blob");
  data->pop_back();
}

#endif
