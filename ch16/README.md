### Exercise 16.1
> Define instantiation
```
Instantiation describes the creation of a function or class by the complier from a template definition.
Instantiation occurs when a template function/class is called.
```

### [Exercise 16.2](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-02.cpp)

### [Exercise 16.3](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-03.cpp)

### [Exercise 16.4](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-04.cpp)

### [Exercise 16.5](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-05.cpp)

### [Exercise 16.6](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-06.cpp)

### [Exercise 16.7](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-07.cpp)

### Exercise 16.8
> In the “Key Concept” box on page 108, we noted that as a matter of habit C++ programmers prefer using != to using <. Explain the rationale for this habit.
```
Containers and iterators are template instantiations. 
All of the library containers have iterators that define the == and != operators. 
Most of those iterators do not have the < operator.
```

### Exercise 16.9
> What is a function template? What is a class template?
```
A function template is a blueprint for generating type-specific versions of that function.

A class template is a blueprint for generating classes. 
Class templates differ from function templates in that the compiler can't deduce the template parameter type(s) for a class template. 
Instead, to use a class template we must supply additional information inside angle brackets following the template’s name.
```
### Exercise 16.10
> What happens when a class template is instantiated? 
```
The compiler uses these template arguments to instantiate a specific class from the template.
```

### Exercise 16.11
> The following definition of List is incorrect. How would you fix it?
```c++
template <typename elemType> class ListItem; 
template <typename elemType> class List 
{ 
  public:     
  List<elemType>();     
  List<elemType>(const List<elemType> &); 
  List<elemType>& operator=(const List<elemType> &);     
  ~List();     
  void insert(ListItem *ptr, elemType value); 
  //error: should be
  // void insert (ListItem<elemType> *ptr, elemType Value);

  private:     
  ListItem *front, *end; 
  // should be:
  // ListItem<elemType> *front, *end;
};
```

### Exercise 16.12
> Write your own version of the Blob and BlobPtr templates. including the various const members that were not shown in the text.
##### [blob.h](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-12-blob.h)

### Exercise 16.13
> See 16.12 

### [Exercise 16.14](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-14.cpp)

### Exercise 16.15
> See 16.14

### [Exercise 16.16](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-16.cpp)

### Exercise 16.17
> What, if any, are the differences between a type parameter that is declared as a typename and one that is declared as a class? When must typename be used?
```
There are no differences between class and typename parameters.
When using the scope operator ::, we must use typename to specify we are accessing type members of a class template.
```

### Exercise 16.18
> Explain each of the following function template declarations and identify whether any are illegal. Correct each error that you find.
```
(a) 
template <typename T, U, typename V> void f1(T, U, V); 
correction:
template <typename T, typename U, typename V> void f1(T, U, V);

(b) 
template <typename T> T f2(int &T); 
correction:
template <typename T> T f2(T&);

(c) 
inline template <typename T> T foo(T, unsigned int*); 
correction:
template <typename T> inline T foo(T, unsigned int*); 

(d) 
template <typename T> f4(T, T); 
correction:
template <typename T> void f4(T, T); 

(e) 
typedef char Ctype;     
template <typename Ctype> Ctype f5(Ctype a);
warning:
return and parameter type are not type char.
```

### [Exercise 16.19](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-19.cpp)

### [Exercise 16.20](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-20.cpp)

### [Exercise 16.21](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-21.cpp)

### [Exercise 16.22](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-22.cpp)

### [Exercise 16.23](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-23.cpp)

### Exercise 16.24
> Add a constructor that takes two iterators to your Blob template.
``` 
see 16-12
```

### Exercise 16.25
> Explain the meaning of these declarations:
```c++
extern template class vector<string>; 
/*
This is an explicit template instantiation declaration. We tell the compiler
that this template has been instantiated in another source file.
The complier will therefore not generate code to instantiate this
template in the current file.
*/

template class vector<Sales_data>;
/* 
This is an explicit template instantiation definition. The compiler will
generate code upon seeing this definition in the current file.
*/
```

### Exercise 16.26
> Assuming NoDefault is a class that does not have a default constructor, can we explicitly instantiate vector<NoDefault>? If not, why not?
```
No. To instantiate a vector template class, the type used for its parameter must be default constructible.
When a class is explicitly instantiated, all constructors and member functions are also instantiated. 
If a function or constructor has a class parameter that is not default constructible, the compiler will throw an error.
```

### Exercise 16.27
> For each labeled statement explain what, if any, instantiations happen. If a template is instantiated, explain why; if not, why not.
```c++
template <typename T> class Stack { }; 
void f1(Stack<char>);                 // (a) 
class Exercise {     
  Stack<double> &rsd;                 // (b)     
  Stack<int>    si;                   // (c) 
  };
int main() {     
  Stack<char> *sc;                    // (d)     
  f1(*sc);                            // (e)     
  int iObj = sizeof(Stack< string >); // (f) 
  }
/*
a) Forward declaration. No instantiation.
b) No instantiation. Reference not initialized.
c) Stack<int> class instantiated. si is default initialized.
d) No instantiation. sc is a pointer to a Stack<char>
e) No instantiation. Does not compile since sc is uninitialized.
f) A temporary Stack<string> class is instantiated.
*/
```

### Exercise 16.31
> Explain how the compiler might inline the call to the deleter if we used DebugDelete with unique_ptr.
```
The type of the deleter is part of the type of the object and is known at compile time.
Therefore the compiler can inline the call to DebugDelete to avoid calling the function at runtime.
```

### Exercise 16.32
> What happens during template argument deduction?
```
In a function template, the compiler uses arguments in the function call to
determine the template parameter for the function template. 

Automatic conversion occurs only for const conversions and array or 
function to pointer conversions. 

For const conversions: A function parameter that is a reference (or pointer) to
	a const can be passed a reference (or pointer) to a nonconst object.
For array- and function-to-pointer conversions: If the function parameter is not
	a reference type, then the normal pointer conversion will be applied to
	arguments of array or function type. 

Arithmetic, derived-to-base and user-defined conversions, are not performed. 
For known (ordinary) types in a function parameters, normal automatic
conversions take place.
```

### Exercise 16.33
> Name two type conversions allowed on function arguments involved in template argument deduction.
```
Const conversions and array/function-to-pointer conversions.
```

### Exercise 16.34
> Given only the following code, explain whether each of these calls is legal. If so, what is the type of T? If not, why not?
```
template <class T> int compare(const T&, const T&); 
(a) compare("hi", "world"); 
Illegal. 

(b) compare("bye", "dad");
Legal.
```
### Exercise 16.35
> Which, if any, of the following calls are errors? If the call is legal, what is the type of T? If the call is not legal, what is the problem?
```
template <typename T> T calc(T, int); 
template <typename T> T fcn(T, T); 
double d;    float f;    char c;

(a) calc(c, 'c'); 
Legal. T is type char.

(b) calc(d, f); 
Legal. T is type double. float is converted to int.

(c) fcn(c, 'c'); 
Legal. T is type char. 

(d) fcn(d, f);
Illegal. 
```

### Exercise 16.36
> What happens in the following calls:
```
template <typename T> f1(T, T); 
template <typename T1, typename T2) f2(T1, T2);
int i = 0, j = 42, *p1 = &i, *p2 = &j; 
const int *cp1 = &i, *cp2 = &j;

(a) f1(p1, p2); 
f1 instantiated as f1(*int, *int)

(b) f2(p1, p2);
f2 instantiated as f2(*int, *int)

(c) f1(cp1, cp2); 
f1 instantiated as f(const int*, const int*)

(d) f2(cp1, cp2); 
f2 instantiated as f2(const *int, const *int)

(e) f1(p1, cp1); 
types are not the same. No instantiation.

(f) f2(p1, cp1);
f2 instantiated as f2(*int, const *int)
```


