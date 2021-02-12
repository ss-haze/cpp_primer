### Exercise 11.1
> Describe the differences between a map and a vector
```
Elements in a vector are stored and accessed sequentially by their position in the vector.
The position is an integer value.

Elements in a map are stored and retrieved by a key. The key does not have to be an integer.
```

### Exercise 11.2
> Give an example of when each of list, vector, deque, map and set might be most useful.
```
set: useful for determining whether a value is present.
map: useful for situations that require a data pair, e.g. account number and balance
vector: useful for random-access, last insert/delete use
list: useful for middle insert/delete containers
deque: useful for when we need random-access, first/last insert/delete e.g. modelling a queue
```

### [Exercise 11-3](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-03.cpp)

### [Exercise 11-4](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-04.cpp)

### Exercise 11-5
> Explain the difference between a map and a set. When might you use one or the other?
```
Both are associative containers, but a map has a key and an associated value, whereas a set
has only a key. A set is useful for storing the occurence of an element e.g. names of failed students,
whereas a map will be useful for storing names of students (key) along with their grades (value).
```

### Exercise 11-6
> Explain the difference between a set and a list. When might you use one or the other?
```
A set has unique elements, ordered from lower to higher, and offers logarithmic search/insert/delete
A list can have repeat elements, whose order can be manipulated, and offers constant time insert/delete and linear search
```

### [Exercise 11-8](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-08.cpp)

### [Exercise 11-9](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-09.cpp)

### [Exercise 11-10](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-10.cpp)

### Exercise 11-11
> Redefine bookstore without using decltype
```
mulitset<Sales_data, bool (*) (const Sales_data &, const Sales_data &)> bookstore (compareIsbn) ; 
```

### [Exercise 11-12](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-12.cpp)

### [Exercise 11-13](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-13.cpp)

### [Exercise 11-14](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-14.cpp)

### Exercise 11-15
> What are the mapped_type, key_type and value_type of a map from int to vector<int>?
```
mapped_type: vector<int>
key_type: int
value_type: pair<const int, vector<int>>
```

### [Exercise 11-16](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-16.cpp)

### Exercise 11-17
> Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. Indicate whether each call is legal:
```c++
(a) 
copy(v.begin(), v.end(), inserter(c, c.end())); 
// legal. Inserter calls underlying container's insert member

(b)
copy(v.begin(), v.end(), back_inserter(c)); 
// illegal. Back_inserter calls container's push_back member, which a multiset does not have

(c)
copy(c.begin(), c.end(), inserter(v, v.end())); 
// legal. Vector has an insert member

copy(c.begin(), c.end(), back_inserter(v)); 
// legal. Vector has a push_back member 
```

### Exercise 11-18
> Write the type of map_it from the loop on page 430 without using auto or decltype.
```
map<string, size_t>::const_iterator
```

### Exercise 11-19
> Define a variable that you initialize by calling begin() on the multiset named bookstore from 11.2.2 (p. 425). 
Write the variable’s type without using auto or decltype.
```c++
multiset<Sales_data, bool (*) (const string&, const string&)>::iterator iter = bookstore.begin() ;
```

### [Exercise 11-20](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-20.cpp)


### Exercise 11.21
> Assuming word_count is a map from string to size_t and word is a string, explain the following loop:
```c++
while (cin >> word)
    ++word_count.insert({ word, 0 }).first->second;
```
```
1) This will insert a new key into the map. 
2) If the insertion is succesful, the key will be word and the value will be zero.
3) The insertion will return a pair:
3a) If the insert succeeded, the first member of the returned pair will be an iterator to the newly inserted element.
3b) If the insert failed, the first member of the returned pair will be an iterator to an existant element with key == word.
4) The pair member first, an iterator, is dereferenced, and the size_t value is accessed.
5) This value is incremented. If insertion was successful, this value is now 1. If insertion failed, this value is incremented.
```













