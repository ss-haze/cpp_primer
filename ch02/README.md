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





















