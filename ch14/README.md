### Exercise 14.1
> In what ways does an overloaded operator differ from a built-in operator? In what ways are overloaded operators the same as the built-in operators?
```
Differences:
An overloaded operator can be called as a normal function.
Overloaded operators do not have the same order of evaluation and/or short-circuit evaluation.
An overloaded operator must have one member of class type.

Similarity:
Overloaded operators preserve order of precedence and associativity of built-in operators.
```

### Exercise 14.2
> Write declarations for the overloaded input, output, addition, and compound-assignment operators for Sales_data.
##### [sales_data.h (https://github.com/ss-haze/cpp_primer/blob/main/ch14/sales_data.h)
##### [sales_data.cpp (https://github.com/ss-haze/cpp_primer/blob/main/ch14/sales_data.cpp)

### Exercise 14.3
> Both string and vector define an overloaded == that can be used to compare objects of those types. Assuming svec1 and svec2 are vectors that hold strings, identify which version of == is applied in each of the following expressions:
```
(a) "cobble" == "stone" 
//built-in ==

(b) svec1[0] == svec2[0] 
//string ==

(c) svec1 == svec2
//vector ==

(d) svec1[0] == "stone"
//string ==
