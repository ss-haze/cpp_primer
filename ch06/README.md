### Exercise 6.1
> What is the difference between a parameter and an argument?

Parameters are local variables declared inside the funcion parameter list. They are initialized by the arguments provided in a funcion call.

Arguments are values supplied in a function call that are used to initialize a function's parameters.

### Exercise 6.2
> Indicate which of the following functions are in eror and why. Suggest how you might correct the problems.
```c++
(a) int f() {
  string s; 
  .....
  return s;       
}
//return type should be string

(b) f2 (int vi, int vi) {......}  
//return type should be void

(c) int calc (int v1, int v1) ........}  
//no opening brace for function body, parameters must have different names

(d) double square(double x) return x*x;
//missing braces for function body
```

### [Exercise 6.3](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-03.cpp)

### [Exercise 6.4](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-04.cpp)

### [Exercise 6.5](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-05.cpp)

### Exercise 6.6
> Explain the differences between a parameter, a local variable, and  a local static variable. Give an example of a function in which each might be useful.
```c++
//A parameter is a local variable that is declared in the function parameter list. 
//It is initialized the first time execution flows through the function and is destroyed once the function block terminates.

//A local variable is a variable which is declared and intialized within a block. 
//The variable is destroyed once the block terminates.

//A local static variable is a variable that is initialized before the function in which it is declared is executed. 
//Local static objects have a lifetime beyond the block in which it is declared. 
//They are destroyed when the program terminates.

#include <iostream>
using std::cout; using std::endl;

size_t count()               //x is a parameter
{
	static size_t cnt = 0;       //cnt is local static variable
	return cnt++;
}

int main()
{
for(auto i=0; i!=10;i++)                  //i is a local variable
cout <<"count stands at :"<< count()<<endl;

return 0;
}
```

### [Exercise 6.7](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-07.cpp)

### [Exercise 6.8](https://github.com/ss-haze/cpp_primer/blob/main/ch06/Chapter6.h)

### Exercise 6.9   [fact.cc](https://github.com/ss-haze/cpp_primer/blob/main/ch06/fact.cc)   [factMain.cc](https://github.com/ss-haze/cpp_primer/blob/main/ch06/factMain.cc)

### [Exercise 6.10](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-10.cpp)

### [Exercise 6.11](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-11.cpp)

### [Exercise 6.12](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-12.cpp)

### Exercise 6.13
> Assuming T is the name of a type, explain the difference between a function declared as void f(T) and void f(T&).

void f(T) passes an argument by value. Argument is unchanged by operations on the parameter within the function.

void f(&T) passes an argument by reference. Parameter is an alias of the argument. 
Operations on the parameter within the function body are also operations on the argument.









