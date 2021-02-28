### Exercise 13.1
> What is a copy constructor? When is it used?
```
 A copy constructor is the constructor whose first parameter is a reference of the class type.

 The copy contructor is used:
 a) to initialize a member of class type from another member of class type;
 b) passing an object as an argument to a parameter of non-reference type
 c) returning an object of non-reference type from a function 
 d) Brace initializing elements in an array or members of an aggregate class
 e) Allocation of objects of some class types, and calling container insert or push members.
 ```
 ### Exercise 13.2
 > Explain why the following declaration is illegal:
 ```c++
 Sales_data::Sales_data(Sales_data rhs);
 // step 1: The copy constructor parameter will copy its argument.
 // step 2: This process will use the copy constructor
 // step 3: In order to perform this copy, the copy constructor will be called
// and we are back at step 1.
// We must make the parameter a reference to avoid this loop
```

### Exercise 13.3
> What happens when we copy a StrBlob? What about StrBlobPtrs?
```
When we copy a StrBlob, we copy the shared_ptr, increasing its count by 1. 
Both StrBlobs point to the same vector<string>.

When we copy a StrBlobPtr, we copy the weak_ptr, which does not increase the count.
Both StrBlobPtrs point to the same
```

### Exercise 13.4
> Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:
```c++
Point global; 
Point foo_bar(Point arg) // use 1
{     
  Point local = arg, *heap = new Point(global);  //use 2 and 3   
  *heap = local;     
  Point pa[ 4 ] = { local, *heap };     //use 4 and 5
  return *heap;        //use 6
}
```

### Exercise 13.5
> Given the following sketch of a class, write a copy
constructor that copies all the members. Your constructor should dynamically allocate a new string (§ 12.1.2, p. 458) and copy the object to which ps points, rather than copying ps itself.
```c++
class HasPtr 
{ 
  public:     
  HasPtr(const std::string &s = std::string())
  :         
  ps(new std::string(s)), 
  i(0) 
  {} 

  HasPtr (const HasPtr& rhs)
  :
  ps(new std::string(*rhs.ps)),
  i(rhs.i) 
  {}
  
  private:     
  std::string *ps;     
  int i; 
};
```

### Exercise 13.6
> What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?
```
The copy-assignment operator is the function operator =, whose parameter is of const class type reference 
and returns a pointer to the calling class member

The operator is used to assign one type member to another type member

The synthesised copy-assignment operator assigns each non-static member of the right operand to the corresponding member 
of the left-hand operand using the copy-assignment operator for that member type

It is synthesised when the class does not explicitly provide its own copy-assignment operator
```

### Exercise 13.7
> What happens when we assign one StrBlob to another? What about StrBlobPtrs?
```
If we assign one StrBlob to another, the count of the shared_ptr of the left StrBlob decreases by one, 
and the shared_ptr count of the right StrBlob increases by one.
Both StrBlobs point to the same vector<string>

With StrBlobPtrs, both weak_ptrs will, after the assignment, hold the same address 
i.e. the shared_ptr value of the right hand size operand.
```

### Exercise 13.8
> Write the assignment operator for the HasPtr class from exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your assignment operator should copy the object to which ps points
```c++
class HasPtr 
{ 
  public:     
  HasPtr(const std::string &s = std::string())
  :         
  ps(new std::string(s)), 
  i(0) 
  {} 

  HasPtr (const HasPtr& rhs)
  :
  ps(new std::string(*rhs.ps)),
  i(rhs.i) 
  {}

  HasPtr& operator = (const HasPtr& rhs)
  {
    i=rhs.i;
    if (ps!=rhs.ps)
    {
      delete ps;
      ps = new std::string (*rhs.ps);
    }
    return *this;
  }
  
  private:     
  std::string *ps;     
  int i; 
};
```

### Exercise 13.9
> What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?
```
A destructor is a member function with the name of the class prefixed by a tilde. It has neither a return value nor any parameters.

The synthesised destructor destroys members of class type after the empty destructor body is executed.
Like the copy constructor and copy assignment operator, the sythesised destructor may disallow certain objects 
of class type from being destroyed.

A destructor is synthesised for any class that does not define its own destructor.
```

### Exercise 13.10
> What happens when a StrBlob object is destroyed? What about a StrBlobPtr?
```
When a StrBlob object is destroyed, the shared pointer member is destroyed by calling the share_ptr destructor, which 
decreases the shared pointer count. If the count becomes zero, then the vector pointed by the smart pointer is also destroyed.

When a StrBlobPtr is destroyed, the weak_ptr member is destroyed by calling the weak_ptr destructor. This does not affect the 
count of the underlying shared_ptr, so the vector is unaffected.
```

### Exercise 13.11: 
> Add a destructor to your HasPtr class from the previous exercises.
```c++
class HasPtr 
{ 
  public:     
  HasPtr(const std::string &s = std::string())
  :         
  ps(new std::string(s)), 
  i(0) 
  {} 

  HasPtr (const HasPtr& rhs)
  :
  ps(new std::string(*rhs.ps)),
  i(rhs.i) 
  {}

  ~HasPtr()
  {
    delete ps;
  }

  HasPtr& operator = (const HasPtr& rhs)
  {
    i=rhs.i;
    if (ps!=rhs.ps)
    {
      delete ps;
      ps = new std::string (*rhs.ps);
    }
    return *this;
  }
  
  private:     
  std::string *ps;     
  int i; 
};
```

### Exercise 13.12
> How many destructor calls occur in the following code fragment?
```c++
bool fcn(const Sales_data *trans, Sales_data accum) 
{     
  Sales_data item1(*trans), item2(accum);
  return item1.isbn() != item2.isbn();
}
// Three: accum, item1 and item2 are destroyed at the end of the function
```

### [Exercise 13.13](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-13.cpp)

### Exercise 13.14
> Assume that numbered is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named mysn. Assuming numbered uses the synthesized copycontrol members and given the following function:

void f (numbered s) { cout << s.mysn << endl; }

what output does the following code produce?

numbered a, b = a, c = b; f(a); f(b); f(c);
```
numbered a uses the default constructor, and a.mysn==1.
b=a uses the synthesised copy contructor, so b.mysn ==1.
c=b uses the synthesised copy constructor, so c.mysn ==1
f(a) will initialize s with the synthesised copy constructor, so s.mysn == 1.
f(b) will initialize s with the synthesised copy constructor, so s.mysn == 1.
f(c) will initialize s with the synthesised copy constructor, so s.mysn == 1.
```

### Exercise 13.15
> Assume numbered has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?
```
Yes, output is changed.
numbered a uses the default constructor, and a.mysn==1.
b=a uses the copy contructor, so b.mysn ==2.
c=b uses the copy constructor, so c.mysn ==3
f(a) will initialize s with the copy constructor, so s.mysn == 4.
f(b) will initialize s with the copy constructor, so s.mysn == 5.
f(c) will initialize s with the copy constructor, so s.mysn == 6.
```

### Exercise 13.16
> What if the parameter in f were const numbered&? Does that change the output? If so, why? What output gets generated?
```
Yes, output is changed.
numbered a uses the default constructor, and a.mysn==1.
b=a uses the copy contructor, so b.mysn ==2.
c=b uses the copy constructor, so c.mysn ==3
f(a) will initialize s as a copy of a, so s.mysn == 1.
f(b) will initialize s as a copy of a, so s.mysn == 2.
f(c) will initialize s as a copy of a, so s.mysn == 3.
```

### Exercise 13.17
> Write versions of numbered and f corresponding to the previous three exercises and check whether you correctly predicted the output.
##### [13.14 code](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-14.cpp) 
##### [13.15 code](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-15.cpp) 
##### [13.16 code](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-16.cpp) 


