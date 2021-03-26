#include "14-26-StrBlob.h"

class PtrStrBlobPtr
{
public:
  PtrStrBlobPtr(StrBlobPtr sbptr)
      : p_(&sbptr)
  {
  }

  StrBlobPtr &operator*() const;
  StrBlobPtr *operator->() const;

private:
  StrBlobPtr *p_ = nullptr;
};