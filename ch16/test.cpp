#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <list>
#include <memory>

using namespace::std;

class CustomDeleter
{
  public:
  template <typename T>
  void operator()(T *p) const
  {
    cout << "deleting ptr" << '\n';
    delete p;
  }
};

template<typename T> class Blob
{
  template<typename U> friend void print (const Blob<U>& item);

  public:
    Blob() 
    : data(make_shared<vector<T>>()) {}

    template <typename It> Blob (It b, It e) 
    : 
    //data(make_shared<vector<T>>(b, e)) {} 
    data (new vector<T>(b,e), CustomDeleter()) {}

  private:
    shared_ptr<vector<T>> data;
};

template<typename T>
void print (const Blob<T>& item)
  {
    if ( (*item.data).empty() ) cout <<"The object is empty\n";
    else 
    {
      for (const auto & v : *item.data) cout <<v<<" ";
    }
  }

int main ()
{
  Blob<int> b;
  vector<int> vi {1,2,3,4,5,6,7,8,9,0};
  Blob<int> b2 (vi.begin(), vi.end());
  print(b);
  print (b2);

  return 0;
}
