#include "16-12-BlobPtr.h"

int main()
{
  std::vector<int> v {01,2,3,4,5,6,7,8,9};
  Blob<int> b2 (v.begin(), v.end());   //for 16-24

  Blob<int> b;

  return 0;
}
