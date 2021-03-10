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

### [Exercise 13.18](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-18.cpp)

### Exercise 13.19
> Does your Employee class need to define its own versions of the copy-control members? If so, why? If not, why not? Implement whatever copy-control members you think Employee needs.
```
It seems counterintuitive to copy employees, since each is assumed to be unique. 
So best would be to disable the copy constructor and the assignment operator.
```
##### [13.19](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-19.cpp)

### Exercise 13.20
> Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes from § 12.3 (p. 484).
```
For TextQuery
a) copy
A TextQuery object has two members: a shared_ptr and a map<string, shared_ptr>
The string copy constructor will be called for the map key.
The copy contructor will memberwise copy the rhs members to the left-hand side.
The shared_ptr counts for the two elements will increase by 1.

b) assignment
The string assignment operator will be called for the map key.
The shared-ptr counts for the LHS operand will decrease by 1 and the counts for the RHS operand shared_ptrs will increment.
If the LHS counts hit 0, they will delete their objects.


c) destruction
The shared_ptr counts for the object will decrease by one.
The string destructor will be called for the map key.

QueryResult objects have two shared_ptrs
The above will happen when we copy, assign, destroy QueryResult objects
```

### Exercise 13.21
> Do you think the TextQuery and QueryResult classes need to define their own versions of the copy-control members? If so, why? If not, why not? Implement whichever copy-control operations you think these classes require.
```
No. The classes use shared_ptrs, and the synthesised copy-control constructors and destructor handle all operations.
```

### [Exercise 13.22](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-22.cpp)


### Exercise 13.23
> Compare the copy-control members that you wrote for the solutions to the previous section’s exercises to the code presented here. Be sure you understand the differences, if any, between your code and ours.
```
see 13.22
```

### Exercise 13.24
> What would happen if the version of HasPtr in this section didn’t define a destructor? What if HasPtr didn’t define the copy constructor?
```
If no defined destructor, the synthesised destructor would not delete the string pointer ps.
If no defined copy constructor, the synthesised constructor would copy the string pointer.
```

### Exercise 13.25
> Assume we want to define a version of StrBlob that acts like a value. Also assume that we want to continue to use a shared_ptr so that our StrBlobPtr class can still use a weak_ptr to the vector. Your revised class will need a copy constructor and copy-assignment operator but will not need a destructor. Explain what the copy constructor and copy assignment operators must do. Explain why the class does not need a destructor.
```
The copy constructor and copy assignment operator must dynamically allocate memory and create a copy of the 
vector<string> container.
A destructor need not be defined, as all dynamic memory is dealt with by the smart pointer.
```

### [Exercise 13.26](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-26.h)

### [Exercise 13.27](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-27.cpp)

### [Exercise 13.28](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-28.cpp)

### Exercise 13.29
> Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop.
```
The calls inside the swap function invoke the stl swap function, not our user-defined HasPtr function.
```

### Exercise 13.32
> Would the pointerlike version of HasPtr benefit from defining a swap function? If so, what is the benefit? If not, why not?
```
No. The stl swap function can handle the swapping of pointers.
```

### Exercise 13.33
> Why is the parameter to the save and remove members of Message a Folder&? Why didn’t we define that parameter as Folder? Or const Folder&?
```
We use a reference because we wish to make changes to the parameter.
```

### [Exercise 13.34](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-34.cpp)

### Exercise 13.35
> What would happen if Message used the synthesized versions of the copy-control members?
```
The synthesised constructor would create or a new message with the same pointers to the same folders, 
but the corresponing folders would not have a pointer to this new message.

The sythesised assignment operator would copy the rhs message string and set into the lhs message, 
but again, the lhs message would not have the required pointers in the required folders.
```

### Exercise 13.36
> Design and implement the corresponding Folder class. That class should hold a set that points to the Messages in that Folder.
``` 
see 13.34
```

### [Exercise 13.37](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-37.cpp)

### Exercise 13.38
> We did not use copy and swap to define the Message assignment operator. Why do you suppose this is so?
```
This would be much more resource intensive than the existing method. We would be:
a) making a copy of the rhs
b) removing both the lhs and rhs from their folders
c) swapping contents
d) reading both lhs and rhs to their folders
This involves one copy, two removes, one swap, and two insertions.
The present method involves one remove, one partial swap and one addition.
```

### Exercise 13.41
> Why did we use postfix increment in the call to construct inside push_back? What would happen if it used the prefix increment?
```
We construct at iterator location first_free, which points to the first element in the array, then increment.
If we incremented then constructed, we would be leaving gaps in the array.
```
### Exercise 13.42
> Test your StrVec class by using it in in takes the place call an to it used the prefix of the vector<string> in your TextQuery and QueryResult classes (§ 12.3, p. 484).
##### [QueryClasses.h](https://github.com/ss-haze/cpp_primer/blob/main/ch13/TextQuery.h)
##### [QueryClasses.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch13/TextQuery.cpp)
##### [StrVec.h](https://github.com/ss-haze/cpp_primer/blob/main/ch13/TextQueryResult.h)
##### [StrVec.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch13/TextQueryResult.cpp)
##### [13-42.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-42.cpp)

### Exercise 13.43
> Rewrite the free member to use for_each and a lambda (§ 10.3.2, p. 388) in place of the for loop to destroy the elements. Which implementation do you prefer, and why?
```c++
void StrVec::free()
{
  if (elements)
  {
    for_each (elements, first_free, [this] (const string& s) { alloc.destroy(&s); }
    alloc.deallocate(elements, cap - elements);
  }
}
//This version is terser and clearer
```

### [Exercise 13-44](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-44.cpp)

### Exercise 13.45
> Distinguish between an rvalue reference and an lvalue reference.
```
An lvaue reference refers to an lvalue, which is a persistent value. 
The lvalue reference refers to the object's identity.

An rvalue reference refers to an rvalue, which is destroyed once the expression in which it appears completes. 
The rvalue reference refers to the object's value.
```

### Exercise 13.46
> Which kind of reference can be bound to the following initializers?
```c++
int f();  
 vector<int> vi(100);

 int? r1 = f(); 
 //rvalue

 int? r2 = vi[0]; 
 //lvalue

 int? r3 = r1; 
 //lvalue

 int? r4 = vi[0] * f();
 //rvalue
 ```

 ### [Exercise 13-47](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-47.cpp)

 ### [Exercise 13-48](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-48.cpp)

### Exercise 13-49
> Add a move constructor and move-assignment operator to your StrVec, String, and Message classes.

##### [StrVec_move.h](https://github.com/ss-haze/cpp_primer/blob/main/ch13/StrVec_move.h)    
##### [StrVec_move.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch13/StrVec_move.cpp)
##### [String_move.h](https://github.com/ss-haze/cpp_primer/blob/main/ch13/String_move.h)    
##### [String_move.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch13/String_move.cpp)
##### [Message_move.h](https://github.com/ss-haze/cpp_primer/blob/main/ch13/Message_move.h)    
##### [Message_move.cpp](https://github.com/ss-haze/cpp_primer/blob/main/ch13/Message_move.cpp)

### [Exercise 13-50](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-50.cpp)

### Exercise 13-51
> Although unique_ptrs cannot be copied, in § 12.1.5 (p. 471) we wrote a clone function that returned a unique_ptr by value. Explain why that function is legal and how it works.
```
The returned unique pointer was about to be destroyed, therefore the function returns an rvalue, which is copied.
A copied rvalue will invoke the move copy constructor or the move assignment operator. The resources of the unique_ptr
are not copied but moved to the newly constructed object.
```

### Exercise 13-52
> Explain in detail what happens in the assignments of the HasPtr objects on page 541. In particular, describe step by step what happens to values of hp, hp2, and of the rhs parameter in the HasPtr assignment operator.
```
The HasPtr assignment operator is as follows:
HasPtr& operator=(HasPtr rhs)
The rhs parameter is a copy of the argument, so will invoke either the copy constructor or the move contructor.

hp = hp2; 
hp2 is an lvalue. The rhs parameter in the HasPtr assignment operator will therefore initialize using the copy constructor.
The assignment operator expression will act function like a copy assignment expression.

hp = std::move(hp2);
hp2 is an rlvalue. The rhs parameter in the HasPtr assignment operator will therefore initialize using the move constructor.
The assignment operator expression will function like a move assignment expression.
```

### [Exercise 13-53](https://github.com/ss-haze/cpp_primer/blob/main/ch13/13-53.cpp)

### Exercise 13-54
> What would happen if we defined a HasPtr move-assignment operator but did not change the copy-and-swap operator? Write code to test your answer.
```
We get a function matching error, since the compiler has no way of choosing between the two operators:
More than one operator "=" matches these operands ...
```

### Exercise 13-53
> Add an rvalue reference version of push_back to your StrBlob.
```c++
//lvalue reference
void push_back(const std::string &s) { data->push_back(s); }

//rvalue reference
void push_back (const std::string &&s) {data->push_back(std::move(s)); }
```

### Exercise 13-56
> What would happen if we defined sorted as:
```c++
Foo Foo::sorted() const & 
{     
  Foo ret(*this);     
  return ret.sorted();
}

// ret isn lvalue, so we would be calling the function sorted() again i.e. we would
// have created a continuously recurring loop
```

### Exercise 13-57
> What if we defined sorted as:
```c++
Foo Foo::sorted() const & 
{ 
  return Foo(*this).sorted();
}
// Foo(*this) will create an rvalue, so the rvalue sorted method will be invoked
```



















