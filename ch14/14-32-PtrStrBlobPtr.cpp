#include "14-32-PtrStrBlobPtr.h"
#include <iostream>

StrBlobPtr &PtrStrBlobPtr::operator*() const
{
  return *p_;
}
StrBlobPtr *PtrStrBlobPtr::operator->() const
{
  return p_;
}

int main()
{
  StrBlob sb{"Hello", "Bye", "Naybe"};

  StrBlobPtr sb_ptr(sb);

  PtrStrBlobPtr ptr_sb_ptr(sb_ptr);

  std::cout << ptr_sb_ptr->operator*() << std::endl;

  std::cout << (*ptr_sb_ptr).operator*();

  return 0;
}