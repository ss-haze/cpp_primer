### [Exercise 10.11](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-01.cpp)

### [Exercise 10.2](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-02.cpp)

### [Exercise 10.3](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-03.cpp)

### Exercise 10.4
> Assuming v is a vector<double>, what, if anything, is wrong with calling
accumulate (v.cbegin(), v.cend(), 0)?
```
The argument passed is an int, which determines the type of the result. 
We want to pass a value of type double in order to get a result of type double.
```

### Exercise 10.5
> In the call to equal on rosters, what would happen if both rosters held C-style strings, rather than library strings?
```
The result is the same ( not sure why, any insight appreciated). We would be comparing address value, which apparently are the same, so perhaps an initialzed pointer to a C-style string points to a unique memory location.
```

### [Exercise 10.6](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-06.cpp)

### Exercise 10.7
> Determine if there are any errors in the following programs and, if so, correct the error(s).
```c++
(a)
vector<int> vec;
list<int> lst;
int i;
while (cin >> i) lst.push_back(i);
copy (lst.cbegin(), lst.cend(), vec.begin());

//error. vector vec, destination of copy, is empty.
// change last line to:
copy (lst.cbegin(), lst.cend(), back_inserter(v) );

(b) 
vector<int> vec;
vec.reserve(10);
fill_n(vec.begin(), 10, 0);

//error. Reserve creates memory for elements, but the size of the vector is still zero.
//either use resize
vector<int> vec;
vec.resize(10);
fill_n(vec.begin(), 10, 0);

//or back_inserter
vector<int> vec;
fill_n(back_inserter(vec), 10, 0);
```

### Exercise 10.8
>We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?
```
Back_inserter is a an iterator type, not a generic algorithm.
```

### [Exercise 10.9](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-09.cpp)

### Exercise 10.10
> Why do you think the algorithms don’t change the size of containers?
```
By using only iterators, the algorithms become generic, usable over any container type. 
One consequent restriction is that the algorithms do not directly interact with the container, hence do not alter container size.
This restriction results in a conceptual distinction: algorithms affect container content, containers affect container size.
```

### [Exercise 10.11](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-11.cpp)

### [Exercise 10.12](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-12.cpp)

### [Exercise 10.13](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-13.cpp)

### [Exercise 10.14](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-14.cpp)

### [Exercise 10.15](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-15.cpp)

### [Exercise 10.16](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-16.cpp)

### [Exercise 10.17](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-17.cpp)

### [Exercise 10.18](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-18.cpp)

### [Exercise 10.19](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-19.cpp)

### [Exercise 10.20](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-20.cpp)

### [Exercise 10.21](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-21.cpp)

### [Exercise 10.22](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-22.cpp)

### Exercise 10.23
> How many arguments does bind take?
```
bind takes the number of arguments its first argument, the callable it binds to, takes + 1.
```

### [Exercise 10.24](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-24.cpp)

### [Exercise 10.25](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-25.cpp)

### Exercise 10.26
> Explain the difference among the three kinds of insert iterators
```
back_inserter is an iterator adaptor that calls the push_back function of its underlying container
front_inserter is an iterator adaptor that calls the push_front function of its underlying container
inserter is an iterator adaptor that calls the insert function of its underlying container
```

### [Exercise 10.27](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-27.cpp)

### [Exercise 10.28](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-28.cpp)

### [Exercise 10.29](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-29.cpp)

### [Exercise 10.30](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-30.cpp)

### [Exercise 10.31](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-31.cpp)

### [Exercise 10.32](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-32.cpp)

### [Exercise 10.33](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-33.cpp)

### [Exercise 10.34](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-34.cpp)

### [Exercise 10.35](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-35.cpp)

### [Exercise 10.36](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-36.cpp)

### [Exercise 10.37](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-37.cpp)

### Exercise 10.38
> List the five iterator categories and the oerations that each supports.
```
input iterator:          read not write; single pass; increment only
(==. !=, ++, *, ->)

output iterator:         write not read; single pass; increment only
(*, ++)

forward iterator:        read and write; multi-pass; increment only
(==, !=, ++, *, ->)

bi-directional iterator: read and write; multi-pass; increment and decrement
(==, !=, ++, --, *, ->)

random access iterator:  read and write; multi-pass; all iterator arithmetic
(==, !=, ++, --, *, ->, <, >, <=, >=, + n, -n, iter1 - iter 2, +, +=, -=, [] )
```

### Exercise 10.39
> What kind of iterator does a list have? What about a vector?
```
A list has a bi-directional iterator. 
A vector has a random access iterator.
```

### Exercise 10.40
> What kind of iterators do you think copy requires? What about reverse or unique?
```
copy requires an input and an output iterator.
reverse requires a bi-directional iterator.
unique requires a forward iterator.
```

### Exercise 10.41
> Based only on the algorithm and argument names, describe the operations that each of the following library algorithms performs:
```
(a) replace (beg, end, old_var, new_val)
replace every old_var element in the range (beg, end] with new_val

(b) replace_if (beg, end, pred, new_val)
replace all elements in range (beg, end] that satisfy pred with new_val

(c) replace_copy (beg, end, dest, old_val, new_val)
for all occurences of old_val in range (beg, end], insert element new_val into dest

(d) replace_copy_if (beg, end, dest, pred, new_val)
for all occurences of old_val in range (beg, end] that satisfy pred, insert element new_val into dest
```

### [Exercise 10.42](https://github.com/ss-haze/cpp_primer/blob/main/ch10/10-42.cpp)
















