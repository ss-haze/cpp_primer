#include <iostream>
using std::cout;

template <typename T> void f(T param) {cout << "template <typename T> void f(T param) called\n";}
template <typename T> void f(const T* param) {cout << "template <typename T> void f(const T* param) called\n";}
template <typename T> void g(T param) {cout << "template <typename T> void g(T param) called\n";} 
template <typename T> void g(T* param) {cout << "template <typename T> void g(T* param) called\n";}

int main()
{
  int i = 42, *p = &i; 
  const int ci = 0, *p2 = &ci; 

  g(42);  //template <typename T> void g(T param) called
  g(p);   //template <typename T> void g(T* param) called
  g(ci);  //template <typename T> void g(T param) called
  g(p2);  //template <typename T> void g(T* param) called
  f(42);  //template <typename T> void f(T param) called
  f(p);   //template <typename T> void f(T param) called
  f(ci);  //template <typename T> void f(T param) called
  f(p2);  //template <typename T> void g(T* param) called

  return 0;
}
