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







