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

### [Exercise 11.3](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-03.cpp)

### [Exercise 11.4](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-04.cpp)

### Exercise 11.5
> Explain the difference between a map and a set. When might you use one or the other?
```
Both are associative containers, but a map has a key and an associated value, whereas a set
has only a key. A set is useful for storing the occurence of an element e.g. names of failed students,
whereas a map will be useful for storing names of students (key) along with their grades (value).
```

### Exercise 11.6
> Explain the difference between a set and a list. When might you use one or the other?
```
A set has unique elements, ordered from lower to higher, and offers logarithmic search/insert/delete
A list can have repeat elements, whose order can be manipulated, and offers constant time insert/delete and linear search
```

### [Exercise 11.7](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-07.cpp)

### [Exercise 11.8](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-08.cpp)

### [Exercise 11.9](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-09.cpp)

### [Exercise 11.10](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-10.cpp)

### Exercise 11.11
> Redefine bookstore without using decltype
```
mulitset<Sales_data, bool (*) (const Sales_data &, const Sales_data &)> bookstore (compareIsbn) ; 
```

### [Exercise 11.12](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-12.cpp)

### [Exercise 11.13](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-13.cpp)

### [Exercise 11.14](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-14.cpp)

### Exercise 11.15
> What are the mapped_type, key_type and value_type of a map from int to vector<int>?
```
mapped_type: vector<int>
key_type: int
value_type: pair<const int, vector<int>>
```

### [Exercise 11.16](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-16.cpp)

### Exercise 11.17
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

### Exercise 11.18
> Write the type of map_it from the loop on page 430 without using auto or decltype.
```
map<string, size_t>::const_iterator
```

### Exercise 11.19
> Define a variable that you initialize by calling begin() on the multiset named bookstore from 11.2.2 (p. 425). 
Write the variable’s type without using auto or decltype.
```c++
multiset<Sales_data, bool (*) (const string&, const string&)>::iterator iter = bookstore.begin() ;
```

### [Exercise 11.20](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-20.cpp)

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

### Exercise 11.22
> Given a map<string, vector<int>>, write the types used as an argument and as the return value for the version of insert that inserts one element
```
arguments: pair<string, vector<int>>
return: pair<map<string,vecor<int>>::iterator, bool>
```

### [Exercise 11.23](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-23.cpp)

### Exercise 11.24
> What does the following program do?
```c++
map<int, int> m;
m[0] = 1;

/* The program creates a map m with an int key and int value.
It then creates an element with key 0 and a value that is default initialized. We then assign 1 to the value.  */
```

### Exercise 11.25
> Contrast the folowing program with the one in the previous exercise
```c++
vector<int> v;
v[0] = 1;
/* v is an an empty vector holding ints.
The second line is an error: it is trying to access member of v at index 0, but v is empty.  */
```

### Exercise 11.26
> What type can be used to suscript a map? What type does the subscript operator return? Give a concrete example - that is, define a map and then write the types that can be used to subscript the map and the type that would be returned from the subscript operator.
```c++
map subscripted with key_type
subscript operator returns a mapped_type

map <string, int> m {"Hello", 5};  

cout <<m ["Hello"]; //subscript type is string, returns int 5
```

### Exercise 11.27
> What kinds of problems would you use count to solve? When might you use find instead?
```
for multiset and multimap, count will give us the number of times a key is present within the container.
For set and map, find will tell us whether the element is present.
```

### Exercise 11.28
> Define and initialize a variable to hold the result of calling find on a map from string to vector of int.
```
map<string, vector<int>> m;
map<string, vector<int>>::const_iterator iter = m.find("item");
```

#### Exercise 11.29
> What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not in the container?
```
They all return a position at which the key can be inserted while maintaining container order.
```

### Exercise 11.30
> Explain the meaning of the operand pos.first->second used in the output expression of the final program in this section.
```
pos refers to a pair
pos.first erfers to the first member of this pair, in this case an interator to the matching element
pos.first->second refers to the value of this element
```

### [Exercise 11.31](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-31.cpp)

### [Exercise 11.32](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-32.cpp)

### [Exercise 11.33](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-33.cpp)

### Exercise 11.34 
> What would happen if we used the subscript operator instead of find in the transform function?
```
If the word was not an element in the map, the subscript operator would create an element in the map and then return its value,
 which in this case would be a value-initialized string i.e. the empty string.
```


### Exercise 11.35
> In buildMap, what effect, if any, would there be from rewriting 
trans_map[key] = value.substr(1); as 
trans_map.insert({key, value.substr(1)})?
```
using the subscript operator overwrites the value each time the key is encountered. 
So value for key is always updated.

using the insert fails creates the pair, but does not change the value of the key the next time it is encountered. 
So value for key is never updated.
```

### Exercise 11.36
> Our program does no checking on the validity of either input file. In particular, it assumes that the rules in the transformation file are all sensible. What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.
```
The line 
if (value.size() > 1)
would prevent the replacement or creation of a key with a value of " ".
```

### Exercise 11.37
> What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?
```
Ordered Associative Container
Standard Traversal encounters elements in sorted order
Order predicate may be specified
Search operations required to have O(log n) runtime
Insert, Remove operations should either be seldom used or have O(log n) runtime

Unordered Associative Container
Standard Traversal encounters elements in unspecified order
Search, Insert, Remove operations should have average-case constant runtime
Popular implementations use hashing
```

### [Exercise 11.38](https://github.com/ss-haze/cpp_primer/blob/main/ch11/11-38.cpp)












