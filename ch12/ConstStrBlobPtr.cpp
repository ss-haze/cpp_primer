#include "ConstStrBlobPtr.h"
#include "StrBlob.h"

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
