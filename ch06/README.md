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

#### Exercise 6.14
> Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

If we wish the function to affect the values of the passed arguments, use reference. If not, don't.

### Exercise 6.15
> Explain the rationale for the type of each of find_char's parameters. In particular,  Why is s a reference to const but 'occurs' is a plain reference?

s is a reference because we do not wish to copy a potentially long string.

s is also const because we do not want to make any changes to s.

occurs is a plain reference because we want to the function to increment the value of 'occur'.

> Why is the char parameter not a reference?

We can pass temporary values of c to function if it is not a reference.

> What would happen if we made s a plain reference?

If s was a plain reference the function could make changes to the value of s.

> What if we made 'occurs' a reference to const?

If 'occurs' were a const reference we could not increment the variable.

### Exercise 6.16
> The following function, althugh legal, is less useful than it might be. Identify and correct the limitation on this function.
```c++
bool is_empty(string& s) { return s.empty(); }
```
The function does not change the passed argument, so the parameter should be const & string. The function cannot currently be passed a const string.

### [Exercise 6.17](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-17.cpp)

### Exercise 6.18
> Write declarations for each of the follwing functions. When you write these declarations, use the name of thefunction to indiacte what the function does.

(a) A function named compare that returns bool, and has two parameters that are references to a class names matrix.
```c++
bool compare(const matrix & p1, const matrix & p2); 
```

(b) A function named change_val that returns a vector<int>iterator and takes two parameters: one is an int and the other is an iterator for a vector<int>
```c++
vector<int>::iterator change_val(int p1, vector<int>::iterator p2);
```

### Exercise 6.19 
> Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.
```c++
double calc(double);
int count(const string &, char)
int sum (vector<int>::iterator, vector<int>::iterator, int);
vecctor<int> vec (10);

(a) calc (23.4, 55.1);
//illegal, function only takes one argument.

(b) count ("abcda", 'a');		
//legal

(c) calc(66);
//legal. 66 implicitly converted to double.

(d) sum(vec.begin(), vec.end(), 3.8)	
//legal, 3.8 implicitly converted from double to int 3
```

### Exercise 6.20
> When should reference parameters be reference to const? What happens if we make a parameter a plain reference when it could be a reference to const? 

Refrence parameters should be references to const when the function makes no changes to the argument.

A plain refrence parameter precludes the use of a literal or a const object as an argument.

### [Exercise 6.21](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-21.cpp)

### [Exercise 6.22](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-22.cpp)

### [Exercise 6.23](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-23.cpp)


















