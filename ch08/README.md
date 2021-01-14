### Exercise 8.1
> Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream. (see 8.2)

### [Exercise 8.2](https://github.com/ss-haze/cpp_primer/blob/main/ch08/8-02.cpp)

### Exrcise 8.3
> What causes the following while to terminate?
```c++
while (cin>>i) /*......*/
```
The condition sets the cin goodbit flag if we have successful input into i, and the loop continues.
The cin badbit flag is set to true if we encounter an unrecoverable error.
The cin failbit flag is set to true if we input data that is not of type i.
The cin eofbit and failbit are set to true if we hit the end of the file.

### [Exercise 8.4](https://github.com/ss-haze/cpp_primer/blob/main/ch08/8-04.cpp) 

### [Exercise 8.5](https://github.com/ss-haze/cpp_primer/blob/main/ch08/8-05.cpp)

### [Exercise 8.6 & 8.7](https://github.com/ss-haze/cpp_primer/blob/main/ch08/8-06.cpp) 

### [Exercise 8.8](https://github.com/ss-haze/cpp_primer/blob/main/ch08/8-08.cpp)

### Exercise 8.12
> Why didn't we use in-class initializers in PersonInfo?
```
String and vector have default synthesized constructors,therefore any declared PersonInfo objects will have an empty string for the name member and an empty vector for the vector member. Default values are not needed.
```

### Exercise 8.14
> Why did we declare entry and nums as const auto &?
```
We use a reference in order not to have to copy a potentially large string. We use a const because we are not changing the element.
```
