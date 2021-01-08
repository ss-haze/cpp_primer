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
An encapsulated class hides the implementation from the user, who does not need to know the workings of the class. 
The user can simply use the class interface to use the class. 
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

### [Exercise 7.23](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-23.cpp)

### [Exercise 7.24](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-24.cpp)

### Exercise 7.25
> Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?

Yes, because Screen members are all string type.

### [Exercise 7-26](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-26.cpp)

### [Exercise 7.27](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-27.cpp)

### Exercise 7.28
> What would happen in the previous exercise if the return type of move, set and display was Screen rather than Screen&?

Were the return type Screen,the second call to Display would not display the '#' in the output, since the changes have been made to copies of myScreen, not the original myScreen object. 

### [Exercise 7.29](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-29.cpp)

### Exercise 7.30
> It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the this pointer to access members.

Pros:
Easier to read
Cons:
More to read

### [Exercise 7.31](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-31.cpp)

### [Exercise 7.32](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-32.cpp)

### Exercise 7.33
> What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.
```c++
pos Screen::size() const
{
  return height*width;
}

//corrected
Screen::pos Screen::size() const
{
  return height*width;
}

//pos is a Class type of Screen, therefore we must use the scope operator to alter the compiler to the location of its definition.
```

### Exercise 7.34
> What would happen if we put the typedef of pos in the Screen class on page 285 as the last line in the class?
```
all earlier uses of pos would then be undefined.
```

### Exercise 7.35
```c++
typedef std::string Type;
Type initVal();     //string initVal()
class Exercise {
  public:
   typedef double Type;
   Type setVal(Type);  //double setVal(double)
   Type initVal();
  private:
   int val;
   
};
Type Exercise::setVal(Type parm) {    //ERROR: double Exercise::setVal(double parm) 
  val = parm + initVal();
  return val;
}

//solution:

typedef std::string Type;
Type initVal();     //string initVal()
class Exercise {
  public:
   typedef double Type;
   Type setVal(Type);  //double setVal(double)
   Type initVal();
  private:
   int val;  
};

Exercise::Type Exercise::initVal(){double d = 5.0; return d;}
Exercise::Type Exercise::setVal(Type parm) {    
  val = parm + initVal();
  return val;
}
```
### Exercise 7.36 
> The following initializer is in error. Identify and fix the problem.
```c++
struct X {
  X (int i, int j)
  :
  base(i), rem(base % j) {} //error. rem initialized first, but base is undefined.
  int rem, base;  
};

//solution
struct X {
  X (int i, int j)
  :
  base(i), rem(base % j) {}
  int base, rem;
};
```

### Exercise 7.37
> Using the version of Sales_data from this section, determine which constructor is used to initialize each of the following variables adn list the values of the data members in each object.
```c++
Sales_data first_item(cin);
int main() {
  Sales_data next; 
  Sales_data last("9-999-99999-9");
}
// first_item uses Sales_data (std::istream & is)
// next and last use Sales_data (std::string s= "")
// next.bookNo is 0 and last.bookNo is equal to "9-999-99999-9"
```

### Exercise 7.38
> We might want to supply cin as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument.
```c++
Sales_data (std::istream& is = std::cin) {read(is, *this); }
```

### Exercise 7.39
> Would it be legal for both the constructor that takes a string and the one that takes an istream& to have default arguments? If not, why not?
```
It would be illegal, because we would then have two default constructors.
```

### [Exercise 7.40](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-40.cpp)

### [Exercise 7.41](https://github.com/ss-haze/cpp_primer/blob/main/ch07/7-41.cpp)





