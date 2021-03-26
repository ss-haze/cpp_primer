#include "14-26-StrBlob.h"

//StrBlob operations
bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
  return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
  return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
  return *lhs.data < *rhs.data;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
  return !(rhs < lhs);
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
  return *rhs.data < *lhs.data;
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
  return !(rhs > lhs);
}

std::string &StrBlob::operator[](size_t n)
{
  check(n, "Object is out of range");
  return (*data)[n];
}

const std::string &StrBlob::operator[](size_t n) const
{
  check(n, "Object is out of range");
  return (*data)[n];
}

//StrBlobPtr operations
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return lhs.wptr.lock() == rhs.wptr.lock() &&
         lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return !(rhs < lhs);
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return rhs < lhs;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return !(rhs > lhs);
}

std::string StrBlobPtr::operator[](size_t n)
{
  auto p = check(n, "Index is out of bounds");
  return (*p)[n];
}

const std::string StrBlobPtr::operator[](size_t n) const
{
  auto p = check(n, "Index is out of bounds");
  return (*p)[n];
}

StrBlobPtr &StrBlobPtr::operator++()
{
  check(curr++, "Increment past end of StrBlobPtr");
  return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
  check(--curr, "Increment below start of StrBlobPtr");
  return *this;
}
StrBlobPtr StrBlobPtr::operator++(int)
{
  auto ret = *this;
  ++*this;
  return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
  auto ret = *this;
  --*this;
  return ret;
}

StrBlobPtr StrBlobPtr::operator+(const size_t n)
{
  StrBlobPtr temp = *this;
  temp += n;
  return temp;
}

StrBlobPtr StrBlobPtr::operator-(const size_t n)
{
  StrBlobPtr temp = *this;
  temp -= n;
  return temp;
}

StrBlobPtr &StrBlobPtr::operator+=(const size_t n)
{
  curr += n;
  check(curr, "increment is out of bounds");
  return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(const size_t n)
{
  curr -= n;
  check(curr, "increment is out of bounds");
  return *this;
}

std::string &StrBlobPtr::operator*() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

std::string *StrBlobPtr::operator->() const
{
  return &this->operator*();
}

//ConstStrBlobPtr operations
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
  return lhs.wptr.lock() == rhs.wptr.lock() &&
         lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
  return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
  return !(rhs < lhs);
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
  return rhs < lhs;
}

bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
  return !(rhs > lhs);
}

const std::string ConstStrBlobPtr::operator[](size_t n) const
{
  auto p = check(n, "Index is out of range");
  return (*p)[n];
}

const std::string &ConstStrBlobPtr::operator*() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

const std::string *ConstStrBlobPtr::operator->() const
{
  return &this->operator*();
}

//StrBlob definitions
StrBlob::StrBlob()
    : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const
{
  if (i >= data->size())
    throw std::out_of_range(msg);
}

std::string &StrBlob::front()
{
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string &StrBlob::back()
{
  check(0, "end on empty StrBlob");
  return data->back();
}

const std::string &StrBlob::front() const
{
  check(0, "front on empty StrBlob");
  return data->front();
}

const std::string &StrBlob::back() const
{
  check(0, "end on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back()
{
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

//StrBlobPtr defintions
StrBlobPtr::StrBlobPtr()
    : curr(0)
{
}

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz)
    : wptr(a.data),
      curr(sz)
{
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t size, const std::string &msg) const
{
  auto ret = wptr.lock();
  if (!ret)
    throw std::runtime_error("Unbound StrBlobPtr");
  if (size >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}

std::string &StrBlobPtr::deref() const
{
  auto ret = check(curr, "dereference past end of StrBlobPtr");
  return (*ret)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr StrBlob::begin()
{
  return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
  return StrBlobPtr(*this, data->size());
}

// ConstrStrBlobPtr definitions

ConstStrBlobPtr::ConstStrBlobPtr()
    : curr(0)
{
}

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &a, size_t sz)
    : wptr(a.data),
      curr(sz)
{
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t size, const std::string &msg) const
{
  auto ret = wptr.lock();
  if (!ret)
    throw std::runtime_error("Unbound StrBlobPtr");
  if (size >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}

std::string &ConstStrBlobPtr::deref() const
{
  auto ret = check(curr, "dereference past end of StrBlobPtr");
  return (*ret)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

ConstStrBlobPtr StrBlob::begin() const
{
  return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
  return ConstStrBlobPtr(*this, data->size());
}