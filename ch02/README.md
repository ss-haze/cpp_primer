## Exercise 2.1
> What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?

An int is guaranteed to have a minimum size of 16 bits (value range is -32767 to 32767).
A short is guaranteed to have a minimum size of 16 bits (value range is -32767 to 32767). 
A long is guaranteed to have a minimum size of 32 bits (value range is -2,147,483,647 to 2,147,483,647).
A long long is guaranteed to have a minimum size of 64 bits (value range is -9.22*10^18 to 9.22*10^18).

A signed type has a bit dedicated to signal whether the number is positive or negative.
An unsigned type uses the dedicated bit to double the largest possible number of its signed type, but cannot represent negative numbers.

A float has a minimum size of 6 significant digits.
A double has a minimum size of 10 significant digits.

## Exercise 2.2
> To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

Interest is usually a floating point of up to 4 significant figures, so use float.
Assuming the principal and payment are below 4bn, use an unsigned long.

## Exercise 2.3
> What output will the following code produce?
```
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;     //32
std::cout << u - u2 << std::endl;     //4294967264
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;     //32
std::cout << i - i2 << std::endl;     //-32
std::cout << i - u << std::endl;      //0
std::cout << u - i << std::endl;      //0
```

## [Exercise 2.4](https://github.com/ss-haze/cpp_primer/blob/main/ch02/2-04.cpp)

## Exercise 2.5
> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:

(a) 'a', L'a', "a", L"a"                //char, wide char, string , wide string 
(b) 10, 10u, 10L, 10uL, 012, 0xC        //int, unsigned int, long, unsigned long int, octal int, hexadecimal int
(c) 3.14, 3.14f, 3.14L                  //double, float, long double
(d) 10, 10u, 10., 10e-2                 //int, usigned int, double, double


## Exercise 2.6
> What, if any, are the differences between the following definitions:

int month = 9, day = 7;     //month is an int of 9, day is an int of 7
int month = 09, day = 07;   //day holds 7, but month cannot hold 9 because it is an octal value.


## Exericse 2.7
>What values do these literals represent? What type does each have?

a) "Who goes with F\145rgus?\012"     //two octal char literals: 'e' and New Line
(b) 3.14e1L                           //long double
(c) 1024f                             //error should be 1024.0f to represent float
(d) 3.14L                             //long double


## Exercise 2.8
> Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.
```c++
#include <iostream>
 
 int main()
 {
   std::cout <<"2" <<"\115\012";
   std::cout <<"2" <<"\t\115\012";
   
   return 0;
 }
 ```
## Exercise 2.9
> Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.

(a) std::cin >> int input_value;
//Error. Cannot declare variable in stream operand. Must declare the variable beforehand.
int input_value;
std::cin>> unput:value;

(b) int i = { 3.14 };
//Error. List initialization does not allow narrrowing. Use normal initialization if narrowing is not a problem
int i=3.14;

(c) double salary = wage = 9999.99;
//Error if wage has not been declared beforehand. Ok otherwise.

(d) int i = 3.14;
//Legal, but i will hold a truncated value of 3.


## Exercise 2.10
> What are the initial values, if any, of each of the following variables?
```c++
std::string global_str;           //empty string
int global_int;                   //0
int main()
{
    int local_int;                //undefined
    std::string local_str;        //empty string
}
```

## Exercise 2.11
> Explain whether each of the following is a declaration or a definition:

```
(a) extern int ix = 1024;     //definition
(b) int iy;                   //definition
(c) extern int iz;            //declaration
```

## Exercise 2.12
> Which, if any, of the following names are invalid?

```
(a) int double = 3.14;        //invalid, can't be int and double
(b) int _;                    //valid
(c) int catch-22;             //invalid, can't use dash
(d) int 1_or_2 = 1;           //invalid. Can't start name with a digit.
(e) double Double = 3.14;     //valid
```

## Exercise 2.13
> What is he value of j in the following program?
```
int i=42;

int main()
{
  int i=100;
  int j=i;
}
// j = 100.
```

## Exercise 2.14
> Is the following program legal? If so, what values are printed?
```
  int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
```
The code is legal. The output is: 100 45

## Exercise 2.15
> Which of the following definitions, if any, are invalid? Why?
```
(a) int ival = 1.01;        //valid. Value is narrowed.
(b) int &rval1 = 1.01;      //invalid. Cannot have non-const reference to literal.
(c) int &rval2 = ival;      //valid
(d) int &rval3;             //invalid. val3 is not initialized.
```

## Exercise 2.16
> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
```
int i = 0, &r1 = i; double d = 0, &r2 = d;

(a) r2 = 3.14159;     //valid, r2 is reference to d, and d now equals 3.14159
(b) r2 = r1;          //valid, r1 is a reference to int, and int value is converted to double.
(c) i = r2;           //valid, r2 is a reference to double, and value will be narrowed to int.
(d) r1 = d;           //valid, d is a double, so value will be narrowed to int.
```

## Exercise 2.17
> What does the following code print?
```
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
code prints 10 10

## Exercise 2.18
> Write code to change the value of a pointer. Write code to change the value to which the pointer points.

```
int x=10, y=20;
int *p=&x;
p=&y;             //change value of p
*p=x;             //change value to which p points
```

## Exercise 2.19
> Explain the key differences between pointers and references.

References are not objects, but aliases of other objects.
A reference cannot be bound to another object.
A reference must be initialized.

Pointers are objects that hold the address of other objects.
Pointers can point to other objects.
A pointer can be declared and a value assigned at a later date.


## Exercise 2.20
> What does the following program do?

```
int i = 42;     
int *p1 = &i; *p1 = *p1 * *p1;

// p1 is pointer to i. The value to which p1 points is now equal to that value squared, i.e i holds the value 1764.
```

## Exercise 2.21
> Explain each of the following definitions. Indicate whether any are illegal and, if so, why.

int i=0;
(a) double *dp = &i; //dp is a pointer to double. i is an int. Illegal.
(b) int *ip = i;     //ip is a pointer to int, but it must be initialized with an int address. Illegal.
(c) int *p = &i;     //p is a pointer to int, and is initialized with the address of int t. Legal.

## Exercise 2.22
> Assuming p is a pointer to int, explain the following code:

if (p) //...      This conditional returns true is p is pointing to an int. Returns false if p is not initialized or is a nullptr.
if (*p) //...     This conditional returns true if *p is value other than 0.

## Exercise 2.23
> Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

No. If the object a pointer points to is destroyed, the user is not alerted, nor does the pointer cease attempting to access that memory location. A smart pointer solves these problems by automatically deleting itself once it no longer points to an object.

## Exercise 2.24
> Why is the initialization of p legal but that of lp illegal?

```c++
int i = 42;
void *p = &i;
long *lp = &i;
```
A pointer to void can point to any type, so the intialization of p is valid.
Pointer lp however must be a pointer to long, and i is an int.

## Exercise 2.25
> Determine the types and values of each of the following variables.

(a) int* ip, i, &r = i;   //ip is pointer to int, i is an int and r is a reference to i.
(b) int i, *ip = 0;       //i is an int and ip is a null pointer.
(c) int* ip, ip2;         //ip is a pointer to int, and ip2 is an int.

## Exercise 2.26
> Which of the following are legal? For those that are illegal, explain why.
```c++
const int buf;      // illegal. buf is a const and must therefore be initialized.
int cnt = 0;        // ok
const int sz = cnt; // ok
++cnt;              // ok
++sz;               // illegal. sz is a const int and cannot therefore change value.
```

## Exericse 2.27
> Which of the following initializations are legal? Explain why.

(a) int i = -1, &r = 0;             //illegal. r cannot be a reference to an int literal
(b) int *const p2 = & i2;           //legal. p2 is a const pointer to an int.
(c) const int i = -1, &r = 0;       //legal. i is const int of value -1, and r is const ref to an int literal
(d) const int *const p3 = &i2;      //legal. p3 is  const pointer to a const int, which holds the address of i2.
(e) const int *p1 = &i2;            //legal. p1 is a pointer to a const int, whic holds the address of i2.
(f) const int &const r2;            //illegal. r2 is a reference, so must be intialized, and there is no top level const for a reference.
(g) const int i2 = i, &r = i;       //legal. i2 is a const int of value i, and r is a const reference to i.

## Exercise 2.28
> Explain the following definitions. Identify any that are illegal.

(a) int i, *const cp;               //illegal. cp is a const pointer to int and must be initialized
(b) int *p1, *const p2;             //illegal. p2 is a const pointer to int and must be initialized
(c) const int ic, &r = ic;          //illegal. ic is a const int and must be initialized
(d) const int *const p3;            //illegal. p3 is a const pointer to a const int and must be initialized
(e) const int *p;                   //legal. p is pointer to a const int, and can be assigned to later.

## Exercise 2.29
 > Using the variables in the previous exercise, which of the following assignments are legal? Explain why.

 (a) i = ic;                        //legal. can assign to an int from a const int.
 (b) p1 = p3;                       //illegal. p1 could be used to modify p3 if possible.
 (c) p1 = &ic;                      //illegal. p1 could be used to modify value of ic if possible.
 (d) p3 = &ic;                      //illegal. cannot assign to a const ptr.
 (e) p2 = p1;                       //illegal. cannot assign to a const ptr.
 (f) ic = *p3;                      //illegal. cannot assign to a const int.

 ## Exercise 2.30
 > For each of the following declarations indicate whether the object being declared has top-level or low-level const.

 ```c++
 const int v2 = 0; int v1 = v2;                       //v2 is top-level const int
int *p1 = &v1, &r1 = v1;                              
const int *p2 = &v2, *const p3 = &i, &r2 = v2;        //p2 is low-level const ptr, p3 is a top- and bottom.level const ptr, and r2 is a low-level const reference
```

## Exercise 2.31
> Given the declarations in the previous exercise, determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.

r1 = v2;      //legal. top-level const of v2 ignored when assigning value.
p1 = p2;      //illegal. p2 has low-level const and p1 does not.
p2 = p1;      //legal. we can assign a ptr to int to const int ptr.
p1 = p3;      //illegal. p3 has low-level const and p1 does not.
p2 = p3;      //legal. Both p2 and p3 have low-level const, and the high.level const of p3 is ignored.

## Exercise 2.32
> Is the following code legal or not? If not, how might you make it legal?
```c++
int null = 0, *p = null;
```
This code is not valid. 'null' is probably being mixed up with 'NULL'. We have various options:
```c++
//1
int null = 0, *p = &null;

//2
const int null = 0; int *p=null;

//3
int *p = nullptr;

//4
int *p=NULL;  // I think 3 is regarded as preferable to 4

//5
int *p=0;
```

## Exercise 2.33
> Using the variable definitions from this section, determine what happens in each of these assignments:

see [2.34]

## [Exercise 2.34]

## [Exercise 2.35]

## Exercise 2.36
> Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.

auto ignores top-level const and reference, whereas decltype does not.
```
//same type
int x=5;
auto y = x;           //y is an int
decltype(x) z = y;    //z is an int

//different type
const int a=5, &r = a, m=10;
auto s = r;           //s is an int
decltype(r) b = m;    //b is a const int &
```

## Exercise 2.39
> Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.
```c++
struct Foo { } 
int main()
{
    return 0;
}
```
Error message: expected a ';'

## Exericse 2.40
> Write your own version of the Sales_data class.
```c++
struct Sales_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
```







































