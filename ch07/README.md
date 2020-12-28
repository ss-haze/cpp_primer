### [Exercise 7.1](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-01.cpp)


### [Exercise 7.2](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-02.cpp)

### [Exercise 7.3](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-03.cpp)

### [Exercise 7.4](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-04.cpp)

### [Exercise 7.5](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-05.cpp)

### [Exercise 7.6](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-06.cpp)

### [Exercise 7.7](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-07.cpp)

### Exercise 7.8
> Why does read define its Sales_data parameter as a plain reference and print define its parameter as a reference to const?
```
Read's parameter is a ref, and this parameter is then modified and returned by the function.

Print takes a const ref Sales_data object, which it prints out and does not change. 
This function can print both normal and const Sales_data objects.
```

### [Exercise 7.9](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-09.cpp)

### Exercise 7.10
> What does the condition in the folloöwing if statement do?

The statement reads input into data1 and then data2, and evaluates to true if both inputs are successful.

### [Exercise 7.11](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-11.cpp)

### [Exercise 7.12](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-12.cpp)

### [Exercise 7.13](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-13.cpp)

### [Exercise 7.14](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-14.cpp)

### [Exercise 7.15](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-15.cpp)

### Exercise 7.16
> What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?
```
An access specifier may appear as often as is wished.
A public specifier should be used for interface members.
A private specifier should be used for implementation members.
```

### Exercise 7.17
> What, if any, are the differences between using a class or struct?
```
Members defined or declared before the first access specifier in a class are private and in a struct are public.
```

### Exercise 7.18
> What is encapsulation? Why is it useful?
```
Encapsulation is the separation of the implementation and interface of a class.
An encapsulated class hides the implementation from the user, who does not need to know the workings of the class. The user can simply use the class interface to use the class. 
Encapsulation also prevents user code corrupting the implementation. 
A class implementation can change over time and changes need to be made only in the implementation - user code can be left as is.
```

### Exercise 7.19
> Indicate which members of your Person class you would declare as public and which you would declare as private. Explain your choice.
```c++
class Person
{
  public: //public constructors are part of the interface
  Person() = default;

  Person(const string &n) : name(n) {}

  Person(const string &n, const string &a) : name(n), address(a) {}

  Person(istream &is) { read(is, *this); }

  public: //public methods are part of the interface
  string getName() const { return name; }
  string getAddress() const { return address; }

  private: // private data members are part of the implementation
  string name;
  string address;
};
```

### Exercise 7.20
> When are friends useful? Discuss the pros and cons of using friends.
```
Declaring a function as a friend allows that function to access the non-public members of a class.
Pros:
Allows access to private members.

Cons:
Strict encapsulation is broken
Friend functions must be declared as friends inside the class and redeclared outside the class.
```

### [Exercise 7.21](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-21.cpp)

### [Exercise 7.22](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-22.cpp)
