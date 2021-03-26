#include "StrBlob.h"

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