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
Class templates differ from function templates in that the compiler cannot deduce the template parameter type(s) for a class template. 
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
template <typename elemType> class ListItem; template <typename elemType> class List 
{ 
  public:     
  List<elemType>();     
  List<elemType>(const List<elemType> &); List<elemType>& operator=(const List<elemType> &);     
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
