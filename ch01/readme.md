
## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.
* [GCC and file extensions](http://http://labor-liber.org/en/gnu-linux/development/index.php?diapo=extensions)

## Exercise 1.2 
> Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

Changing the return to -1 makes the program return a value of 'False'

## [Exercise 1.3](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-3.cpp)

## [Exercise 1.4](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-4.cpp)

## [Exercise 1.5](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-5.cpp)

## Exercise 1.6
> Explain whether the following program fragment is legal.

The fragment is illegal because the first two semicolons create separate statements. The ensuing statements must have a std::cout as the left-hand operand before the << operator.
The easiest solution is simply to delete the first two semicolons and create one statement.

```c++
std::cout <<"The sum of " << v1 << " and " << v2 <<" is " < v1 + v2 << std::endl;
```

## Exercise 1.7
> Compile a program that has incorrectly nested comments.

```c++
/*
* This is a comment
/* but this line will end the opening comment brace, making the one on the next line redundant */
*/
int main()
{
  return 0;
}
```

## Exercise 1.8
> Indicate which, if any, of the following output statements are legal:

```
std::cout <<"/*;                  //legal
std::cout <<"*/";                 //legal
std::cout << /* "*/" */;          //illegal
std::cout << /* "*/" /* "/*" */;  //legal
```
Once line three is removed, the output will be: /**/ /*.

## [Exercise 1.9](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-09.cpp)

## [Exercise 1.10](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-10.cpp)

## [Exercise 1.11](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-11.cpp)

 ## Exercise 1.12

 > What does the following for loop do? What is the final value of sum?
 ```c++
 int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```
This loops adds the values of -100 to 100 inclusive, which will evaluate to 0.


## [Exercise 1.13](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-13.cpp)

## Exercise 1.14
> Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?

A while loop is best used for an unknown number of iterations, e.g. looping until a certain input value is encountered. A for loop is best used for a finite number of iterations, where the initial value and termination value are given in the loop header.

## Exercise 1.15
> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

```c++
int main()
{
  int x=10, y=5;
  char s= "h";
  std::cout << x;
  std::cout << y    //syntax error missing ;
  std::cout << z;   //declaration error, z not declared
  s=x;              //type error, char taking value of int, producing unexpected output

return 0;
}
```


## [Exercise 1.16](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-16.cpp)

## Exercise 1.17
> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

For x number of different input values, the program will generate x numbers of lines, and each line will return the count of each input value.

## [Exercise 1.18](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-18.cpp)

## [Exercise 1.19](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-11.cpp)

## [Exercise 1.20](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-21.cpp)

## [Exercise 1.21](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-21.cpp)

## [Exercise 1.22](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-22.cpp)

## [Exercise 1.23](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-23.cpp)

## Exercise 1.24
> Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

See [1.23](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-23.cpp)

## [Exercise 1.25](https://github.com/ss-haze/cpp_primer/blob/main/ch01/1-25.cpp)
















