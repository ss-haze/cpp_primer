#ifndef BLOBPTR_H
#define BLOBPTR_H

#include "16-12-blob.h"

template <typename T>
class BlobPtr;

template <typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr
{
  friend operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);

  friend operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);

public:
  //constructors
  BlobPtr() : curr(0) {}

  BlobPtr(Blob<T> &a, size_t sz = 0)
      : wptr(a.data), curr(sz) {}

  //increment and decrement prefix
  BlobPtr &operator++();
  BlobPtr &operator--();

  //increment and decrement postfix
  BlobPtr operator++(int);
  BlobPtr operator--(int);

  //dereference
  T &operator*() const;

private:
  //check success returns a shared_ptr to vector
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;

  //weak ptr to vector. underlying vector might be destroyed
  std::weak_ptr<std::vector<T>> wptr;

  //current position in array
  std::size_t curr;
};


//prefix
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
  --curr;
  check(curr, "decrement past begin of BlobPtr");
  return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
  check(curr, "decrement past begin of BlobPtr");
  ++curr;
  return *this;
}

//postfix
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
  BlobPtr ret = *this;
  ++*this;
  return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
  BlobPtr ret = *this;
  --*this;
  return ret;
}

//dereference
template <typename T>
T &BlobPtr<T>::operator*() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

//check function
template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
  auto ret = wptr.lock();
  if (!ret)
    throw std::runtime_error("Unbound StrBlobPtr");
  if (i >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}

//friend operators
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
  if (lhs.wptr.lock() != rhs.wptr.lock())
  throw std::runtime_error("ptrs are not equivalent");
  return lhs.curr == rhs.curr;
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
 if (lhs.wptr.lock() != rhs.wptr.lock())
 throw std::runtime_error("ptrs are not equivalent");
  return lhs.curr < rhs.curr;
}

#endif