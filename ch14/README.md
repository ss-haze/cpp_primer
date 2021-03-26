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
##### [sales_data.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/sales_data.h)
##### [sales_data.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/sales_data.cpp)

### Exercise 14.3
> Both string and vector define an overloaded == that can be used to compare objects of those types. Assuming svec1 and svec2 are vectors that hold strings, identify which version of == is applied in each of the following expressions:
```
(a) "cobble" == "stone" 
//const char[] ==

(b) svec1[0] == svec2[0] 
//string ==

(c) svec1 == svec2
//vector ==

(d) svec1[0] == "stone"
//string ==
```

### Exercise 14.4
> Explain how to decide whether the following should be class members:
```
(a) %
Symmetric operator. non-member

(b) %=
Compound assignment operator. member.

(c) ++
Increment oerator. Object state alteration. member.

(d) ->
Member access operator. Must be member.

(e) << 
Left-hand operand is not a class member. Non-member.

(f) &&
Symmetric operator. Non-member.

(g) ==
Symmetric operator. Non-member.

(h) ()
call operator. Must be member.
```

### Exercise 14.5
> In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of one of the following classes. Decide what, if any, overloaded operators your class should provide.
##### [14-05.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-05.h)
##### [14-05.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-05.cpp)

### Exercise 14.6
> Define an output operator for your Sales_data class.
```
see 14-2
```

### Exercise 14.7
> Define an output operator for you String class you wrote for the exercises in § 13.5 (p. 531).

### Exercise 14.8
> Define an output operator for the class you chose in exercise 7.40 from § 7.5.1 (p. 291).
```
see 14.5
```

### Exercise 14.9
> Define an input operator for your Sales_data class.
```
see 14.2
```

### Exercise 14.10
> Describe the behavior of the Sales_data input operator if given the following input:
```
(a) 0-201-99999-9 10 24.95
// all good

(b) 10 24.95 0-210-99999-9
// input error. items_sold is unsigned int, so 24.95 will be truncated to 24.
// the 0.95 remainder will initialize the price variable.
// resulting output is 10 24 22.8 0.95
```

### Exercise 14.11
> What, if anything, is wrong with the following Sales_data input operator? What would happen if we gave this operator the data in the previous exercise?
```c++
istream& operator>>(istream& in, Sales_data& s) 
{     
  double price;     
  in >> s.bookNo >> s.units_sold >> price;     s.revenue = s.units_sold * price; 
  return in;
}
//There is no input check. Output is the same as above.
```

### [Exercise 14.12](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-12.cpp)

### [Exercise 14.13](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-13.cpp)

### Exercise 14.14
> Why do you think it is more efficient to define operator+ to call operator+= rather than the other way around?
```
operator+= does not create a variable and then return a copy of this variable, as operator+ does.
Hence it makes sense to avoid this if possible and have operator + call operator +=, rather than the other way round.
```

### Exercise 14.15
> Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define any of the arithmetic operators? If so, implement them. If not, explain why not.
```
The class consists of threes strings and and a double. It does not make sense to add one vehicle to another.
```

### Exercise 14.16
> Define equality and inequality operators for your StrBlob (§ 12.1.1, p. 456), StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p. 526), and String (§ 13.5, p. 531) classes.

##### [StrVec.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/StrVec.h)
##### [StrVec.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/StrVec.cpp)
##### [14-16-StrVec.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-16-StrVec.cpp)

##### [string.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/string.h)
##### [string.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/string.cpp)
##### [14-16-string.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-16-string.cpp)

##### [StrBlob.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/StrBlob.h)
##### [StrBlob.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/StrBlob.cpp)
##### [14-16-StrBlob.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-16-StrBlob.cpp)

### Exercise 14.17
> Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the equality operators? If so, implement them. If not, explain why not.
```
Yes. See ##### [14-05.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-05.cpp)
```

### Exercise 14.18
> Define relational operators for your StrBlob, StrBlobPtr, StrVec, and String classes.

##### [StrVec.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/StrVec.h)
##### [StrVec.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/StrVec.cpp)
##### [14-18-StrVec.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-18-StrVec.cpp)

##### [string.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/string.h)
##### [string.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/string.cpp)
##### [14-18-string.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-18-string.cpp)

##### [StrBlob.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/StrBlob.h)
##### [StrBlob.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/StrBlob.cpp)
##### [14-18-StrBlob.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-18-StrBlob.cpp)

### Exercise 14.19
> Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the relational operators? If so, implement them. If not, explain why not.
```
No. If one vehicle != another vehicle, there is no sensical case whereby one vehicle < the other vehicle.
```

### Exercise 14.20
> Define the addition and compound-assignment operators for your Sales_data class.
##### [sales_data.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/sales_data.h)
##### [sales_data.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/sales_data.cpp)

### Exercise 14.21
> Write the Sales_data operators so that + does the actual addition and += calls +. Discuss the disadvantages of this approach compared to the way these operators were defined in § 14.3 (p. 560) and § 14.4 (p. 564).
##### [14-21-sales_data.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-22-sales_data.h)
##### [14-21-sales_data.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-22-sales_data.cpp)

### Exercise 14.22
> Define a version of the assignment operator that can assign a string representing an ISBN to a Sales_data.
##### [14-22-sales_data.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-22-sales_data.h)
##### [14-22-sales_data.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-22-sales_data.cpp)

### Exercise 14.23
> Define an initializer_list assignment operator for your version of the StrVec class.

### Exercise 14.24
> Decide whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define those operators.
##### [14-24.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-24.h)
##### [14-24.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-24.cpp)

### Exercise 14.25
>Implement any other assignment operators should define. Explain which types should be used as operands and why.
your class
```
see 14.24
```

### Exercise 14.26
> Define subscript operators for your StrVec, String, StrBlob, and StrBlobPtr classes.
##### [14-26-string.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-string.h)
##### [14-26-string.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-string.cpp)

##### [14-26-StrVec.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrVec.h)
##### [14-26-StrVec.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrVec.cpp)

##### [14-26-StrBlob.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrBlob.h)
##### [14-26-StrBlob.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrBlob.cpp)

### Exercise 14.27
> Add increment and decrement operators to your StrBlobPtr class.
see
##### [14-26-StrBlob.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrBlob.h)
##### [14-26-StrBlob.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrBlob.cpp)

### Exercise 14.28
> Define addition and subtraction for StrBlobPtr so that these operators implement pointer arithmetic.
see
##### [14-26-StrBlob.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrBlob.h)
##### [14-26-StrBlob.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrBlob.cpp)

### Exercise 14.29
> We did not define a const version of the increment and decrement operators. Why not?
```
the operators change the state of the object, so const versions are not possible.
```

### Exercise 14.30
> Add dereference and arrow operators to your StrBlobPtr class and to the ConstStrBlobPtr class that you defined in exercise 12.22 from § 12.1.6 (p. 476). Note that the operators in constStrBlobPtr must return const references because the data member in constStrBlobPtr points to a const vector.
see
##### [14-26-StrBlob.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrBlob.h)
##### [14-26-StrBlob.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-StrBlob.cpp)

### Exercise 14.31
> Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?
```
StrBlobPtr data members can be copied, assigned or destroyed using the synthesized copy-control members.
```

### Exercise 14.32
> Define a class that holds a pointer to a StrBlobPtr. Define the overloaded arrow operator for that class
##### [14-32-PtrStrBlobPtr.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-PtrStrBlobPtr.h)
##### [14-32-PtrStrBlobPtr.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-26-PtrStrBlobPtr.cpp)

### Exercise 14.33
> How many operands may an overloaded function-call operator take?
```
As many as the language allows
```

### [Exercise 14.34](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-34.cpp)

### [Exercise 14.35](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-35.cpp)

### [Exercise 14.36](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-36.cpp)

### [Exercise 14.37](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-37.cpp)

### [Exercise 14.38](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-38.cpp)

### [Exercise 14.39](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-39.cpp)

### [Exercise 14.40](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-40.cpp)

### Exercise 14.41
> Why do you suppose the new standard added lambdas? Explain when you would use a lambda and when you would write a class instead.
```
Lambdas are terser than functors, and are useful if the lambda is only needed once.
```

### Exercise 14.42
> Using library function objects and adaptors, define an expression to
(a) Count the number of values that are greater than 1024 
(b) Find the first string that is not equal to pooh 
(c) Multiply all values by 2
```c++
(a)
auto count = count_if (vec.begin(), vec.end(), bind(greater<int>(),_1, 1024)));
cout <<count;

(b)
auto iter = find_if(vs.begin(), vs.end(), bind(not_equal_to<string>(), _1, "pooh"));
  if (iter != vs.end())
    cout << *iter;

(c)
transform(vi.begin(), vi.end(), vi.begin(), bind(multiplies<int>(), _1, 2));
```

### [Exercise 14.43](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-43.cpp)

### [Exercise 14.44](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-44.cpp)

### Exercise 14.45
> Write conversion operators to convert a Sales_data to string and to double. What values do you think these operators should return?
##### [Sales_data.h](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-45-Sales_data.h)
##### [Sales_data.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-45-Sales_data.cpp)
##### [14-45.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-45.cpp)

### Exercise 14.46
> Explain whether defining these Sales_data conversion operators is a good idea and whether they should be explicit.
```
There is no logical reason for applying these conversions (why should a Sales_data item be a string?). Using explicit will avoid any unwanted conversion results.
```

### Exercise 14.47
> Explain the difference between these two conversion operators:
```c++
struct Integral {     
  operator const int(); 
  //this operator will convert an Integral object to a const int. Opeartor can cnange the object state

  operator int() const; 
  //this operator will convert an Integral object to an int. Operator cannot change the object state
};
```

### Exercise 14.48
> Determine whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) should have a conversion to bool. If so, explain why, and explain whether the operator should be explicit. If not, explain why not.
```
I cannot see a use for a bool conversion for the Vehicle class. 
Perhaps we could extend the class and give it a class member that shows if the car is electric.
This could let us keep track of all non-electric vehicles and ensure they are off the road by a certain date.
```

### [Exercise 14.49](https://github.com/ss-haze/cpp_primer/blob/main/ch14/14-49.cpp)

### Exercise 14.50
> Show the possible class-type conversion sequences for the initializations of ex1 and ex2. Explain whether the initializations are legal or not.
```c++
struct LongDouble {     
  LongDouble(double = 0.0);     
  operator double();     
  operator float(); 
  };

LongDouble ldObj; 
int ex1 = ldObj;     //error both conversion operators are possible
float ex2 = ldObj;   //ok. can use operator float()
```

### Exercise 14.51
>  Show the conversion sequences (if any) needed to call each version of calc and explain why the best viable function is selected.
```c++
void calc(int); 
void calc(LongDouble); 
double dval; 
calc(dval); // which calc?

// will call calc(int) since only an arithmetic conversion is needed.
```

































