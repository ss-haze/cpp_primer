
### [Exercise 3.1](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-01.cpp)

### [Exercise 3.2](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-02.cpp)

### Exercise 3.3
> Explain how whitespace characters are handled in the string input operator and in the getline function.

The string input operator sees whitespace (i.e. spaces, newlines and tabs) as limiter, so strings contain no white space characters.

The getline function regards new lines as a limiter, so the string returned using getline will contain all characters input up to the newline.

### [Exercise 3.4](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-04.cpp)

### [Exercise 3.5](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-05.cpp)

### [Exercise 3.6](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-06.cpp)

### Exercise 3.7
> What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.

If we use char, we are are copying the string's characters, so any operations on those characters will not affect the string.

### [Exercise 3.8](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-08.cpp)

### Exercise 3.9
> What does the following program do? Is it valid? If not, why not?
```c++
string s;
cout << s[0] << endl;
```
s is an empty string, so the subscript is accessing undefined memory.

### [Exercise 3.10](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-10.cpp)

### Exercise 3.11
> Is the following range for legal? If so, what is the type of c?
```c++
const string s = "Keep out!";
for (auto &c : s){ /*... */ }
```
Yes the range is legal. c is a const char &. We cannot use any operations on c to change s.

### Exercise 3.12
> Which of the following vector definitions are in error? For those that are legal, explain what the definitio does. For those that are not legal, explain why they are illegal.
```c++
(a) vector<vector><int>> ivec;          //legal. ivec holds int vectors
(b) vector<string> svec= ivec;          //illegal. Different vector types
(c) vector<string> svec(10, "null");    //legal. svec holds ten "null" strings
```
### Exercise 3.13
> How many elements are there in each of the following vectors? What are the values of the elements?
```
vector<int> v1;                   //v1 is empty
vector<int> v2(10);               //v2 has 10 elements set to 0 
vector<int> v3(10, 42);           //v3 has 10 elements set to 42
vector<int> v4{ 10 };             //v4 has 1 element set to 10     
vector<int> v5{ 10, 42 };         //v5 has 2 elements of value 10 and 42
vector<string> v6{ 10 };          //v6 has 10 empty string elements
vector<string> v7{ 10, "hi" };    //v7 has 10 elements set to "hi"   
```

### [Exercise 3.14](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-14.cpp)

### [Exercise 3.15](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-15.cpp)

### [Exercise 3.16](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-16.cpp)

### [Exercise 3.17](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-17.cpp)

### Exerice 3.18
> Is the following code legal? If not, how might you fix it?
```c++
vector<int> ivec;
ivec[0] = 42;

//fix
vector<int> ivec;
ivec.push_back(42);
//or
vector<int> ivec{42};
```

### Exercise 3.19
> List  List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.
```c++
vector<int> vi (10,42);                               //method 1
vector<int> vi2 {42,42,42,42,42,42,42,42,42,42};      //method 2
vector<int> vi3;
for (size_t i =0; i != 10; ++i) vi3.push_back(42);      //method 3
```
Method 1 is the quickest to code and easiest to read.

### [Exercise 3.20](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-20.cpp)

### [Exercise 3.21](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-21.cpp)

### [Exercise 3.22](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-22.cpp)

### [Exercise 3.23](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-23.cpp)

### [Exercise 3.24](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-24.cpp)

### [Exercise 3.25](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-25.cpp)

### Exercise 3.26
> In the binary search program on page 112, why did we write mid=beg+(end-beg)/2; instead of mid=(beg+end) /2;?

There is no iterator addition operator, so beg+end cannot be evaluated.
The product of beg + end would also be undefined, unlike end - beg, which points to a known memory location.

### Exercise 3.27
> Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.
```c++
unsigned buf_size = 1024;

int ia[buf_size];               //illegal. buf_size is not a const expr
int ia[4 * 7 - 14];             //legal
int ia[txt_size()];             //illegal, return value of txt_size must be known at compile time
char st[11] = "fundamental";    //illegal, no room for terminating '\0' character  
```
### Exercise 3.28
> What are the values in the following arrays?
```c++
string sa[10];      //10 empty string elements
int ia[10];         //10 int elements set to 0

int main() 
{
    string sa2[10]; //10 empty string elements
    int ia2[10];    //10 undefined int elements 
}
```

### Exercise 3.29
> List some of the drawbacks of using an array instead of a vector.
```
An array must have a known size at compile time.
The size of an array cannot change.
Arrays cannot be copied nor passed to a function as an argument.
Character arrays must include a null character terminator.
```
### Exercise 3.30
> Identify the indexing errors in the following code:
```c++
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
      ia[ix] = ix; 
```
ix should start at 0, not 1, and the test condition should be: ix < array_size.

### [Exercise 3.31](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-31.cpp)

### [Exercise 3.32](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-32.cpp)

### Exercise 3.33
> What would happen if we did not initialize the scores array in the program on page 116?

The elements in the array would have undefined values

### Exercise 3.34
> Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or p2 that make this code illegal?
```c++
p1 += p2 - p1;
```
The code above is equivalent to p1 = p1 + p2- p1, i.e. p1 = p2.
If p1 and p2 are valid ptrs, the code will work.

### [Exercise 3.35](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-35.cpp)

### [Exercise 3.36](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-36.cpp)

### Exercise 3.37
> What does the following code do?
```c++
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp)
{
    cout << *cp << endl;
    ++cp;
}
```
The program will print the contents of ca, but will not terminate printing because ca does not contain a null character, resulting in garbage output.

### Exercise 3.38
> In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

A pointer holds the address of an object. If we add two pointers, the result is the sum of both addresses, i.e. an indeterminate location in memory.

### [Exercise 3.39](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-39.cpp)

### [Exercise 3.40](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-40.cpp)

### [Exercise 3.41](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-41.cpp)

### [Exercise 3.42](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-42.cpp)

### [Exercise 3.43](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-43.cpp)

### [Exercise 3.44](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-44.cpp)

### [Exercise 3.45](https://github.com/ss-haze/cpp_primer/blob/main/ch03/3-45.cpp)




















