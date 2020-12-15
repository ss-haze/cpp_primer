
### [Exercise 3.1](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-01.cpp)

### [Exercise 3.2](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-02.cpp)

### [Exercise 3.3]
> Explain how whitespace characters are handled in the string input operator and in the getline function.

The string input operator sees whitespace (i.e. spaces, newlines and tabs) as limiter, so strings contain no white space characters.

The getline function regards new lines as a limiter, so the string returned using getline will contain all characters input up to the newline.

### [Exercise 3.4](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-04.cpp)

###  [Exercise 3.5]

###  [Exercise 3.6]

###  [Exercise 3.7]
> What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

If we use char, we are are copying the string's characters, so any operations on those characters will not affect the string.

###  [Exercise 3.8]

###  [Exercise 3.9]
> What does the following program do? Is it valid? If not, why not?
```c++
string s;
cout << s[0] << endl;
```
s is an empty string, so the subscript is accessing undefined memory.

### [Exercise 3.10]

### [Exercise 3.11]
> Is the following range for legal? If so, what is the type of c?
```c++
const string s = "Keep out!";
for (auto &c : s){ /*... */ }
```
Yes the range is legal. c is a const char &. We cannot use any operations on c to change s.






