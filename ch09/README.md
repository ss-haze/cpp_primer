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
vector<int> v4(v3;

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
// the element must support the < operation
```









