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

### Exercise 6.24
> Explain the behaviour of the folowing function. If there are problems in the code, explain what they are and how you might fix them.
```c++
void print (const int ia[10])
{
  print (size_t i=0; i!=10; ++i)
  cout << ia[i] << endl;
}
```
The function parameter is actually a pointer to the first element in an array of unspecified size. Were the array of size 3, for example, the function body would loop past the ed of the array and output undefined values. Possible solutions are to pass a pointer to the beginning of array of 10 elements, or to pass the size of the array along with the pointer to the first element:
```c++
void print (const int (*ia)[10]){........}
void print (const int *ia[], size_t size){.......}
```

### [Exercise 6.25 + 6.26](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-26.cpp)

### [Exercise 6.27](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-27.cpp)

### Exercise 6.28
> In the second version of error_msg that has an ErrCode parameter, what is the type of elem in the for loop?

elem is a const string &

### Exercise 6.29
> When you use an initialzer_list in a range for would you ever use a reference as the loop control variable? If so, why? If not, why not?

If the list contains a built-in type such as int, there is negligible overhead in copying the list elements, but if the list contains complex user-defined types, then reference use would be more optimal.

### [Exercise 6.30](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-30.cpp)

### Exercise 6.31 
> When is it valid to return a reference? A reference to const?

It is valid to return a reference to a pre-existing non-local object. 

If we do not want the returned object to be an lvalue, we should use const reference as the return type.

### Exercise 6.32
> Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.

```c++
int& get(int* arry, int index)
{
	return arry[index];
}

int main()
{
	int ia[10];
	for (int i = 0; i != 10; i++)
		get(ia, i) = i;
	for (auto i : ia) std::cout << i << " ";
return 0;
}
```

### [Exercise 6.33](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-33.cpp)

### Exercise 6.34 
> what would happen if the stopping condition in factorial were if (val!=0).

a) if val were positive, then when val has the value 1, instead of returning 1, we would reduce the value of val to 0 and call the factorial function again. Assuming we return 1 when val==0, 
we would get the same result, but would have needlessly iterated through the function one extra time.

b) If val were negative, we would be decreasing the value of val indefinitely, causing stack overflow.

### Exercise 6.35
> In the call to fact, why did we pass val-1 rather than val--

Were the call as follows: return factorial(val--)*val

We wish this expression to first evaluate val, then multiply it by factorial(val--),
but the order of evalution of the multiplication operator is not guaranteed, so we might instead be 
decreasing the value of val, sending this reduced value to the factorial function, and then multiplying the result with the reduced value of val.

### Exercise 6.36
> Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.

string (& func()) [10];

### Exercise 6.37
> Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?

	//full
   string (& func(string(& arr_str)[5]))[5]
   
   //using type alias using
   using  arrStrT = string[5]
   arrStrT &func (arrStrT & arr_str)

   //using type alias typedef
   typedef string arrStrT[5]
   arrStrT &func (arrStrT & arr_str)

	//using trailing return
	auto func(arrStrT & arr_Str)->string (&)[5]

	//using decltype
	string arr[5] = {....}
	decltype (arr) &func(arrStrT & arr_Str)

### Exercise 6.38
> Revise the arrPtr function to return a reference to the array.

```c++
a)
decltype(odd) & arrPtr (int i )
		{
			return (i%2) ? odd: even;
		}

b)
		auto arrPtr(int i)->int(&)[5]
		{
			return (i%2) ? odd: even;
		}

c)
		using arr_int_5 = int [5];
		arr_int_5 & arrPtr(int i)

d)
		int (& arrPtr(int i))[5]        int & arrPtr(int i)[10]
		{
			return (i%2) ? odd: even;
		}
```

### Exercise 6.39
> Explain what the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
´´´
(a)
int calc(int, int);
int calc(const int, const int);

latter adds high level const to parameter. Is a redeclaration of earlier function.

(b) 
int get()
double get()

illegal. functions cannot take same parameters and differ only in the return type.

(c)
int *reset(int *)
double *reset(double*)

overload of reset function. second fn takes and returns a different parameter type.
´´´

### Exercise 6.40
> Which, if either, of the following declarations are errors? Why?
```c++
(a) 
int ff( int a, int b=0, int c=0)  
//ok

(b) char *init (int ht=24, int wd, char bckgrnd) 
//Error.  Must give default values for other two parameters.
```
### Exercise 6.41
> Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer's intent? Why?
```c++
	char *init(int ht, int wd=80, char bckgrnd = ' ');

	(a) init();   
	//illegal. Must pass value for ht

	(b) init(24,10);  
	//legal.  here ht=24, wd=10 and bckgrnd=' '

	(c) init(14, '*'); 
	//legal, but int wd is initialized by '*'. Value was probably intended for bckgrnd.
```

### [Exercise 6.42](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-42.cpp)

### Exercise 6.43
> Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.
```c++
(a) inline bool eq(const BigInt&, const BigInt&){......}

(b) void putValues(int *arr, int size);
```
I would put both in a header file. a) is an inline function, and b) is a function declaration.

### [Exercise 6.44](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-44.cpp)

### Exercise 6.45
> Review the programs you've written for the earlier exercises and decide whether they should be defined as inline. If so, do so. If not, explain why they should not be inline.

Small functions such as make_plural and arrPtr can be inline.

Some of the print functions that used recursion cannot be used inline.

### Exercise 6.46
> Would it be possible to define isShorter as a constexpr? If so, do so. If not, explain why not.

The isShorter function compares the length of two strings. In order to do this, it calls the size() method on both parameters.

The method can only be given a value at run-time, not compile time, therefore the return value of the function cannot be determined at compile time.

### [Exercise 6.47](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-47.cpp)

### Exercise 6.48
> Explain what this loop does and whether it is a good use of assert.

```c++
string s;
	while (cin >> s && s != sought) {}
	assert(cin);

/*
The loop tests for a string input, and will execute as long as that string does not equal sought. 
We will break out of the loop either if cin returns false (string not input, or s==sought).

The assert in the body of the loop tests that the input stream is true (ie not in error or eof). 
If the program terminates, we know it is because cin is in a fail state (ie a string was not input) and not because s==bought.

I don't think this is a good use of assert, because if NDBUG is defined, the program will not terminate if a non-string is input as needed.
Better might be something like putting an if(cin) statement inside a try block and throwing an exception if cin returns false. 
*/
```

### Exercise 6.49
> What is a candidate function? What is a viable function?
```
A candidate function is a function with the same name as the called function and for which a declaration is visible at the point of the call.

A viable function is a candidate function that has the same number of parameters as there are arguments in the call, and the type of each argument must either match or be convertible to the type of its corresponding parameter.
```

### Exericse 6.50
> Given the declarations for f from page 242, list the viable functions, if any, for each of the following calls. Indicate  which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.

```c++
void f();
void f(int);
void f(int, int);
void f(double, double =3.14)


(a) f(2.56, 42)				// illegal. ambigious call between vid f(int, int) and void f(double, double =3.14)
(b) f(42)					// match to void f(int)
(c) f(42,0)					// match to f(int, int)
(d) f(2.56, 3.14)			// match to void f(double, double)
```

### [Exercise 6.51](https://github.com/ss-haze/cpp_primer/blob/main/ch06/6-51.cpp)

### Exercise 6.52
> Given the following declarations:
```c++
void manip (int, int);
double dobj;
```
what is the rank of each conversion in the following calls?

```c++
(a) manip ('a','z')				
//Match through integral promotion (rank 3)

(b) manip (55.4, dobj)			
//Match through arithmetic conversion (rank 4)
```

### Exercise 6.53
> Explain the effects of the second declaration in each of the following sets of declarations.Indicate which, if any, are illegal.

```c++

(a)
	int calc(int &, int&)
	int calc (const int &, const int &)		//this version can be called by two const int arguments

(b)
	int calc(char*, cnar *)
	int calc(const char*, const char *)		//this version can be called by two const char arguments

(c) 
	int calc(char*, char*)
	int calc(char * const, char* const)		//this version has parameters with high level const, which is ignored. Hence a restatement of earlier version.
```























