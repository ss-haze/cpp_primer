#include "StrBlobPtr.h"
#include "StrBlobUpdated.h"

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
