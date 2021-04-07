### Exercise 15.1
> What is a virtual member?
A virtual member is a class function that a derived class can override. When  we call a virtual function through a pointer or a reference, the call will be dynamically bound. Depending on the type of the object to which the object or reference is bound,the function in the base class or one of its derived classes will be called.

### Exercise 15.2
> How does the protected access specifier differ from private?
```
A protected member can be accessed by one of its derived classes, whereas a private member cannot be.
```

### [Exercise 15.3](https://github.com/ss-haze/cpp_primer/blob/main/ch15/15-03.cpp)

### Exercise 15.4
> Which of the following declarations, if any, are incorrect? Explain why.
```c++
class Base { ... };

(a) class Derived : public Derived { ... }; 
//illegal. Class cannot be its own direct base class.

(b) class Derived : private Base { ... };
//legal. Both declaration and defintion.

 (c) class Derived : public Base;
//Illegal; do not need specifier on class declaration.
```

### [Exercise 15.5](https://github.com/ss-haze/cpp_primer/blob/main/ch15/15-05.cpp)


### Exercise 15.6
> Test your print_total function from the exercises in § 15.2.1 (p. 595) by passing both Quote and Bulk_quote objects to that function.
```
see 15.5
```

### [Exercise 15.7](https://github.com/ss-haze/cpp_primer/blob/main/ch15/15-07.cpp)

### Exercise 15.8
> Define static type and dynamic type. 
```
A static type is the type with which a variable is declared or that an expression yields.
A static type is known at compile time.

A dynamic type is the type of the object in memory that a variable or expression represents.
A dynamic type is not known until run-time.
```

### Exercise 15.9
> When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.
```
The dynamic type of a pointer or reference can differ from that pointer's or reference's static type.
```
```c++
class Base {.....};
class Derived : public Base {......};
Derived d;
Base &br = d;
Base *bp = &d;
Derived *dp = &d;
Base *bp2 = dp;
```

### Exercise 15.10
> Recalling the discussion from §8.1 (p. 311), explain how the program on page 317 that passed an ifstream to the Sales_data read function works.
```
ifstream is a derived class, whose base class is istream. The read function has a parameter that is an istream reference. 
If we pass an ifstream argument to the function, the parameter will be dynamically bound to the argument type.
```

### [Exercise 15.11](https://github.com/ss-haze/cpp_primer/blob/main/ch15/15-11.cpp)

### Exercise 15.12
> Is it ever useful to declare a member function as both override and final? Why or why not?
```
Yes. "Override" signals that the method of this derived class is overriding a Base class method. 
And "Final" signals that we do not want any subsequent derived classes to override this class method. 
```
   
#### Exercise 15.13
> Given the following classes, explain each print function. If there is a problem in this code, how would you fix it?
```c++
// The base print function will print the basename.
// The derived print function will call the base print function, and then print the value of i.

class base { 
  public:    
    string name() { return basename; }    
    virtual void print(ostream &os) { os << basename; } 
  private:    
    string basename; 
  };

class derived : public base { 
  public:    
    void print(ostream &os) { print(os); os << " " << i; } //error: infinite loop
    // soln:
    // void print(ostream &os) { base::print(os); os << " " << i; }
  private:    
    int i; 
};
```

### Exercise 15.14
> Given the classes from the previous exercise and the following objects, determine which function is called at run time:
```
base bobj; base *bp1 = &bobj; base &br1 = bobj; 
derived dobj; base *bp2 = &dobj; base &br2 = dobj;

(a) bobj.print(); 
base::print()  compile time

(b) dobj.print(); 
derived::print() compile time

(c) bp1->name(); 
base::name() compile time

(d) bp2->name(); 
base::name() compile time

(e) br1.print(); 
base::print() run time

(f) br2.print();
derived::print() run time
```

### [Exercise 15.15](https://github.com/ss-haze/cpp_primer/blob/main/ch15/15-15.cpp)

### Exercise 15.16
> Rewrite the class representing a limited discount strategy, which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from Disc_quote.
```
see 15-15
```

### Exercise 15.17
> Try to define an object of type Disc_quote and see what errors you get from the compiler.
```
Error message: 
object of abstract class type "Disc_quote" is not allowed: 
-- function "Disc_quote::net_price" is a pure virtual function
```










