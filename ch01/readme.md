
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




