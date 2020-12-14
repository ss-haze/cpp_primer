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

## [Exercise 2.4]

## Exercise 2.5
> Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:
```
(a) 'a', L'a', "a", L"a"                //char, wide char, string , wide string 
(b) 10, 10u, 10L, 10uL, 012, 0xC        //int, unsigned int, long, unsigned long int, octal int, hexadecimal int
(c) 3.14, 3.14f, 3.14L                  //double, float, long double
(d) 10, 10u, 10., 10e-2                 //int, usigned int, double, double
```

## Exercise 2.6
> What, if any, are the differences between the following definitions:
```
int month = 9, day = 7;     //month is an int of 9, day is an int of 7
int month = 09, day = 07;   //day holds 7, but month cannot hold 9 because it is an octal value.
```

## Exericse 2.7
>What values do these literals represent? What type does each have?
```
a) "Who goes with F\145rgus?\012"     //two octal char literals: 'e' and New Line
(b) 3.14e1L                           //long double
(c) 1024f                             //error should be 1024.0f to represent float
(d) 3.14L                             //long double
```

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
```
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
```

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





