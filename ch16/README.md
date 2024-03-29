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
Unlike function templates, the compiler can't deduce the template parameter type(s) for a class template. 
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

### Exercise 16.37
> The library max function has two function parameters and returns the larger of its arguments. This function has one template type parameter. Could you call max passing it an int and a double? If so, how? If not, why not?
```c++
int x=5; 
double y=5.5;
cout << max<double>(x, y);
```

### Exercise 16.38
> When we call make_shared, we have to provide an explicit template argument. Explain why that argument is needed and how it is used.
```
The argument specifies the return type from make_shared, allowing the compiler to allocate the relevant memmory.
```

### Exercise 16.39
> Use an explicit template argument to make it sensible to pass two string literals to the original version of compare from § 16.1.1.
```c++
compare<string>("first", "second");
```

### Exercise 16.40
> Is the following function legal? If not, why not? If it is legal, what, if any, are the restrictions on the argument type(s) that can be passed, and what is the return type?
```c++
template <typename It> auto fcn3(It beg, It end) -> decltype(*beg + 0) 
{  // process the range   
return *beg; // return a copy of an element from the range 
}
/*
Legal. But beg must point to an arithmetic type, since we use decltype on (*beg + 0),
and that expresssion will yield a reference to int or to a type to which int can be promoted.
*/
```

### [Exercise 16.41](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-41.cpp)

### Exercise 16.42
> Determine the type of T and of val in each of the following calls:
```c++
template <typename T> void g(T&& val); 
int i = 0; 
const int ci = i;

(a) g(i);
i is an l-value, so T has type &int. 
Val has type && &int, which collapses to &int.

(b) g(ci);
ci is a const l-value, so T has type const & int. 
Val has type && const & int, which collapsees to const & int.

(c) g(i * ci);
i*ci produces an r-value, so T has type int.
Val therefore has type && int.
```

### Exercise 16.43
> Using the function defined in the previous exercise, what would the template parameter of g be if we called g(i = ci)?
```
i is an int, so T has type & int. Val has type && & int, which collapses to &int
```

### Exercise 16.44
> Using the same three calls as in the first exercise, determine the types for T if g’s function parameter is declared as T (not T&&). What if g’s function parameter is const T&?
```
template <typename T> void g(T val); 
int i = 0; 
const int ci = i;
a) g(i)
T has type int. Val has type int.
b) g(ci)
T has type int (top level const ignored). Val has type int.
c) g(i*ci) 
T has type int. Val has type int.

template <typename T> void g(const T& val); 
int i = 0; 
const int ci = i;
a) g(i)
T has type int. Val has type const int &
b) g(ci)
T has type int. Val has type const int &
c) g(i*ci)
T has type int. Val has type const int &
```

### Exercise 16.45
> Given the following template, explain what happens if we call g on a literal value such as 42. What if we call g on a variable of type int?
```c++
template <typename T> 
void g(T&& val) { vector<T> v; }

/*
for g(42) T is of type int, and val has type && && int, which decays to && int.
vector<T > v is therefore deduced as vector<int> v.

for g(i) T is deduced as type int &, and val has type && &int, which decays to & int.
vector<T> v is therefore deduced as vector<int&> v, but we cannot have a vector of references,
so the deduction is illegal.
*/
```

### Exercise 16.46
> Explain this loop from StrVec::reallocate in § 13.5 (p. 530):
```c++
for (size_t i = 0; i != size(); ++i)     
 alloc.construct(dest++, std::move(*elem++));

/*
for each iteration of the for loop:
the construct member of allocator type object alloc takes a string pointer and 
an r-value reference as parameters. std::move)*elem++) converts the l-value object to which
element points into an r-value in order to pass it into the construct method.
*/
```

### [Exercise 16.47](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-47.cpp)

### [Exercise 16.48](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-48.cpp)

### Exercise 16.49
> Explain what happens in each of the following calls:
```
see 16.50
```

### [Exercise 16.50](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-50.cpp)

### Exercise 16.51
> Determine what sizeof...(Args) sizeof...(rest) return for each call to foo in this section.
```
foo(i, s, 42, d);    // sizeof..Args and sizeof...(rest) are 3
foo(s, 42, "hi");    // sizeof..Args and sizeof...(rest) are 2
foo(d, s);           // sizeof..Args and sizeof...(rest) are 1
foo("hi");           // sizeof..Args and sizeof...(rest) are 0
```

### [Exercise 16.52](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-52.cpp)

### [Exercise 16.53](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-53.cpp)

### Exercise 16.54
> What happens if we call print on a type that doesn’t have an << operator?
```
We will get a compilation error
```

### Exercise 16.55
>Explain how the variadic version of print would execute if we declared the nonvariadic version of print after the definition of the variadic version.
```
We get the error: no matching function for call to 'print(std::ostream&)'
```

### Exercise 16.59
> Assuming s is a string, explain svec.emplace_back(s).
```
s is an l-value. Args is &s, and args is && &s, which collapses to &s.
std::forward<Args>(args).. will forward &s to the string constructor to build the element.
```

### Exercise 16.60
> Explain how make_shared (§ 12.1.1, p. 451) works.
```
make_shared is a variadic template function of the shared_ptr class of the form:

template <typename T, typename... Args)
shared_ptr<T> make_shared(Args&&... args);

It takes a function parameter pack of varying types and returns a shared_ptr
pointing to a dynamically allocated object of type T.
Inside its body, make_shared expands the function parameter pack and forwards
them (as arguments) to the 'new' expression to allocate a block of memory of
type T.  The pointer returned from new is passed to shared_ptr constructor that
takes a built-in pointer (T*) and an optional callable object. The newly
constructed shared_ptr is returned by value.
```

### [Exercise 16.61](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-61.cpp)

### [Exercise 16.62](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-62.cpp)

### [Exercise 16.63](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-63.cpp)

### [Exercise 16.64](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-64.cpp)

### [Exercise 16.65](https://github.com/ss-haze/cpp_primer/blob/main/ch16/16-65.cpp)



### Exercise 16.66
> What are the advantages and disadvantages of overloading these debug_rep functions as compared to defining specializations?
```
Specializations do not not participate in function matching, 
therefore a specialization is considered by the compiler only
if the general template function is viable and is the best match, 
i.e., after function matching has occured.

An overloaded function on the other hand is preferred over
other overloads if that function is the best match.
```

### Exercise 16.67
> Would defining these specializations affect function matching
for debug_rep? If so, how? If not, why not?
```
No. A specialization is a template instantiation, not a definition
for a potential overload. Specializations do not affect function matching.
If a general template is viable after function matching, and if a specialization
of that template is available and applicable, it will be chosen.
```

























