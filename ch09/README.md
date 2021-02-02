### Exercise 9-1
> Which is the most appropriate - a vector deque or list - for the following tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.

(a) Read a fixed number of words, inserting them alphabetically as they are entered. We'll see in the 
next chapter that associative containers are better suited to this problem.
- Linked List. Need fast insertion within the container.

(b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
- Deque. Need fast insertion at front and back of container.

(c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.
- Vector. We have lots of small elements, and vector gives us fast random access.

### Exercise 9-2
> Define a list that holds elements that are deques that holds ints.
```c++
std::list <std::deque<int>> lst;
```

### Exercise 9-3
> What are the constraints on the iterators that form iterator ranges?
```
Iterators begin and end must refer to an element, or one past the last element, within the range.
It is possible to reach end by repeatedly incrementing begin i.e. end must not precede begin.
```

### [Exercise 9-4](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-04.cpp)

### [Exercise 9-5](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-05.cpp)

### Exercise 9-6
> What is wrong with the folloöwing program? How might you correct it?
```c++
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) /*....*/

//list iterators do not use the relational operators, so the last line should be:
while (iter1!=iter2) /*....*/
```

### Exercise 9-7
> What type should be used as the index nto a vector of ints?
```c++
std::vector<int>::size_type size;
```

### Exercise 9-8
> What type should be used to read elements in a list of strings? To write them?
```c++
std::list<std::string>::const_iterator to read elements.
std::list<std::string>::iterator to write elements.
```

### Exercise 9-9
> What is the difference between the begin and cbegin functions?
```
begin gives us an iterator type and cbegin gives us a const_iterator type.
```

### Exercise 9-10
> What are the types of the following four objects?
```c++
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 v1.cbegin(), it3 = v2.cbegin();

// it1 is type vector<int>::iterator
// it2 is type vector<int>::const_iterator
// it3 is type vector<int>::const_iterator
// it4 is type vector<int>::const_iterator
```

### Exercise 9-11
> Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.
```c++
//vector of six ints
vector<int> v1 {1,2,3,4,5,6};
vector<int> v1 = {1,2,3,4,5,6};

//vector of 10 ints, each of value 5
vector<int> v2 (10, 5);

//vector of 10 value-initialized ints
vector<int> v3 (10);

// vector copy of v3
vector<int> v4 = v3;
vector<int> v4(v3);

//empty vector
vector<int> v5;

//vector copy using range iterators, containing values 1,2,3, 4,5,6
vector<int> v6 v1(v1.begin(), v1.end());
```

### Exercise 9-12
> Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.
```
A constructor that takes a container requires that both containers have the same container and element type.

A constructor that takes two iterators does not require the container types to be identical.
It requires only that the elements of the copied container can be converted into the elements of the target container.
```

### [Exercise 9-13](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-13.cpp)

### [Exercise 9-14](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-14.cpp)

### [Exercise 9-15](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-15.cpp)

### [Exercise 9-16](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-16.cpp)

### Exercise 9-17
> Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?
```c++
if (c1 < c2)

// c1 and c2 must have the same container and element types
// c1 and c2 cannot be unordered associative containers
// the element must support the < operation
```

### [Exercise 9-18](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-18.cpp)

### [Exercise 9-19](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-19.cpp)

### [Exercise 9-20](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-20.cpp)

### Exercise 9-21
> Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.
```
The loop would still add elements to the front of the vector, but, unlike a list,
all existing elements in the container would have to be shifted down, resulting in a slower operation.
```

### Exercise 9-22
> Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?
```c++
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);

// The while loop does not terminate since iter is not incremented. 
// Solution:

vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid)
{
  if (*iter == some_val)
    iv.insert(iter++, 2 * some_val);
  iter++;
}

// Note: Insert will change the size of the vector, so if we still wish to iterate to the middle of
// the resultant vector, we will need to recalculate mid.
```

### Exercise 9-23
> In the first program in this section on page 346,what would be the values of val,val2, val3 and val4 if c.size() is 1?
```
val, val2, val3 and val4 would all have the same value, which would be c[0].
```

### [Exercise 9-24](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-24.cpp)

### Exercise 9-25
> In the program on page 349 that erased a range of elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?
```
If elem1 = elem2, nothing is erased.
If elem2 = off-the-end iterator, everything from elem1 to the end are erased.
If elem1 and elem2 = off-the-end iterator, nothing is erased.
```

### (Exercise 9-26](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-26.cpp)

### (Exercise 9-27](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-27.cpp)

### (Exercise 9-28](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-28.cpp)

### Exercise 9-29
> Given that vec holds 25 elements, what does vec.resize(100) do? What if we next wrote vec.resize(10)?
```
vec.resize(100) adds 75 value initialized elements to the end of the vector.
vec.resize(10) would then remove the last 90 elements from the vector.
```

### Exercise 9-30
> What, if any, restrictions does using the version of resize that takes a single argument place on the element type?
```
Additional elements must have a default constructor for initialization.
```

### (Exercise 9-31](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-31.cpp)

### Exercise 9-32
> In the program on page 354 would it be legal to write the call to insert as follows? If not, why not?
```c++
iter = vi.insert(iter, *iter++);
// The statement is illegal, since the order of evaluation in insert is undetermined
// The second statement could be evaluated first, for example, and then that location could be used for the insert.
```

### (Exercise 9-33](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-33.cpp)

### (Exercise 9-34](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-34.cpp)

### Exercise 9-35
> Explain the difference between a vector's capacity and its size.
```
A vector's size is determined by the number of elements the vector currently holds.
A vector's capacity is determined by the possible number of elements it can hold before it needs to reallocate memory.
```

### Exercise 9-36
> Can a container have a capacity less than its size?
```
No.
```

### Exercise 9-37
> Why don't list or array have a capacity member?
```
For an array, its size is fixed. There is no need to reallocate or preallocate memory.
For a list, its elements are non-contiguous in memory, therefore it never needs to reallocate or preallocate memory.
```

### (Exercise 9-38](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-38.cpp)


### Exercise 9-39
> Explain what the following program fragment does:
```c++
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size()+svec.size()/2);

/*
We create a vector<string> and reserve memory for 1024 elements
We input x number of strings
If we input more than 1024 elements, the vector will reallocate memory and increase capacity
We then resize the vector to a size of 1.5x, adding size()/2 number of value initialized members
If the resize is greater than the current capacity, the vector will reallocate memory and increase capacity
*/
```

### Exercise 9-40
> If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it readsa 512? 1,000? 1,048?
```
for 256 words, size = 384 and capacity = 1024
for 512 words, size = 768 and capacity = 1024
for 1000 words, size = 1500 and capacity = 2048
for 1048 words, size = 1572 and capacity = 2048
```

### Exercise 9-42
> Given that you want to read a character at a time into a string, and you kow that you need to read at least 100 characters, how might you improve the performance of your program?
```
We can call the reserve member on the string e.g. s.reserve(130);
```

### Exercise 9-48
> Given the definitions of name and numbers on page 365, what does numbers.find(name) return?
``` 
name is not a substring of the string numbers, therefore numbers.find(name) returns string::npos
```

### (Exercise 9-50](https://github.com/ss-haze/cpp_primer/blob/main/ch09/9-50.cpp)




















