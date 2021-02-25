### Exercise 12.1
> How many elements do b1 and b2 have at the end of this code?
```c++
StrBlob b1;
{     
  StrBlob b2 = {"a", "an", "the"};     
  b1 = b2;     
  b2.push_back("about"); 
}
// b1 has 4 elements
// b2 is destroyed
```

### [Exercise 12.2](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-02.cpp)

### Exercise 12.3
> Does this class need const versions of push_back and pop_back? If so, add them. If not, why aren’t they needed?
```
the compiler accepts const versions, since we are not changing the object (which is a pointer)
but the thing pointed to (which is the vector), but this will be confusing and against the spirit of const usage.
```

### Exercise 12.4
> In our check function we didn’t check whether i was greater than zero. Why is it okay to omit that check?
```
i is an unsigned int, so cannot be less than zero
```

### Exercise 12.5
> We did not make the constructor that takes an
initializer_list explicit (§ 7.5.4, p. 296). Discuss the pros and cons of this design choice.
```
Pros:
We can construct temp StrBlob objects from initializer lists, which allows us to initalize and assign to StrBlob objects
using = {...}, and to pass initializer lists as arguments to function parameters of type StrBlob 

Cons:
Implicit conversions can be sometimes difficult to keep track of
```

### [Exercise 12.6](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-06.cpp)

### [Exercise 12.7](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-07.cpp)

### Exercise 12.8
> Explain what if anything is wrong with the following function.
```c++
bool b() {     
  int* p = new int;    
   // ...     
  return p; 
}
// The returned pointer value will be converted to bool, and the dynamically allocated
// memory will not be deleted. Beeter is to have return of int * 
```

### Exercise 12.9
> Explain what happens in the following code:
 ```c++
int *q = new int(42), *r = new int(100); 
r = q;
 auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
// when q is assigned to r, the int of value 100 can no longer be accessed and deleted.
// the problem does not occur when q2 is assigned to r2, because the object that r2
// pointed to is automatically deleted.
```

### Exercise 12.10
> Explain whether the following call to the process function defined on page 464 is correct. If not, how would you correct the call?
```c++
shared_ptr<int> p(new int(42)); 
process(shared_ptr<int>(p));

//call is correct. process parameter is a copy of the shared_ptr temp. In process, ptr counter is 2, and after ptr is destroyed, counter is back at 1, with p being the sole shared_ptr.
```

### Exercise 12.11
> What would happen if we called process as follows?
```c++
process(shared_ptr<int>(p.get()));
// function parameter ptr would be a copy of the temp argument, which is itself a temp shared_ptr that is independent of p.
// Once the call has been made, the temp shared_ptr is destroyed and the pointer count in the function is 1.
// Once function finises, ptr is destroyed, as is the memory it points to.
// If we now try to use p, it is a dangling pointer, and we have undefined behaviour.
```

### Exercise 12.12
> Using the declarations of p and sp explain each of the following calls to process. If the call is legal, explain what it does. If the call is illegal, explain why:
```c++        
auto p = new int(); 
auto sp = make_shared<int>();

(a) process (sp);
// legal. sp points to value-initialized int.

(b) process (new int () );
//illegal. Function parameter is a shared_ptr type

(c) process (p);
//illegal. Function parameter is a shared_ptr type

(d) process (shared_ptr<int> (p));
//legal, but after function returns, p will be a dangling pointer
```

### Exercise 12.13
> What happens if we execute the following code?
```c++
auto sp = make_shared<int>(); 
auto p = sp.get(); 
delete p;
// Error: Once p is deleted, sp becomes a dangling pointer. 
```

### [Exercise 12.14](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-14.cpp)

### [Exercise 12.15](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-15.cpp)

### [Exercise 12.16](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-16.cpp)


### Exercise 12.17
> Which of the following unique_ptr declarations are illegal or likely to result in subsequent program error? Explain what the problem is with each one.
```c++
int ix = 1024, *pi = &ix, *pi2 = new int(2048); 
typedef unique_ptr<int> IntP;

(a) IntP p0(ix); 
// Illegal. ix is not a pointer to dynamic memory

(b) IntP p1(pi); 
// Illegal. pi is a local pointer.

(c) IntP p2(pi2); 
// Legal

(d) IntP p3(&ix);
// Illegal. Memory pointed to by &ix is not dynamic memory

(e) IntP p4(new int(2048));
// Legal

(f) IntP p5(p2.get());
// Legal. But we have a unique ptr and built-in ptr pointing to same memory.
// If either is deleted, other becomes a dangling pointer.
```

#### Exercise 12.18
> Why doesn’t shared_ptr have a release member?
```
There can be numerous shared_ptrs pointing to the same area on the heap. 
Releasing one shared ptr tells us nothing of how many other potential pointers there are.
```

### [Exercise 12.19](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-19.cpp)

### [Exercise 12.20](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-20.cpp)

### Exercise 12.21
> We could have written StrBlobPtr’s deref member as follows. Which version do you think is better and why?
```c++
std::string& deref() const 
{ 
  return (*check(curr, "dereference past end"))[curr]; 
}
// The above version, although terser than the one we have acutally used, is difficult to decipher.
```

### [Exercise 12.21](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-21.cpp)

### [Exercise 12.22](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-22.cpp)

### [Exercise 12.23](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-23.cpp)

### [Exercise 12.24](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-24.cpp)

### Exercise 12.25
> Given the following new expression, how would you delete pa?
```c++
int *pa = new int[10];
// delete [] pa;
```

### [Exercise 12.26](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-26.cpp)

### [Exercise 12.27](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-27.cpp)

### [Exercise 12.28](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-28.cpp)

### Exercise 12.29
> We could have written the loop to manage the interaction with the user as a do while (§ 5.4.4, p. 189) loop. Rewrite the loop to use a do while. Explain which version you prefer and why.
```c++
void runQueries(ifstream &infile) {       
TextQuery tq(infile);    
do 
{         
  cout << "enter word to look for, or q to quit: ";  
  string s;               
  if (!(cin >> s) || s == "q") break;         
  print(cout, tq.query(s)) << endl;     
}  while (true);

// I find the do-while easier to read than the while
```

### Exercise 12.30 
> see 12.27

### Exercsie 12.31
> What difference(s) would it make if we used a vector instead of a set to hold the line numbers? Which approach is better? Why?
```
The vector would not filter out repeat occurences of a word on the same line.
The use of set is better; it gives us a unique result for each word occurence per line.
```

### [Exercise 12.32](https://github.com/ss-haze/cpp_primer/blob/main/ch12/12-32.cpp)






















