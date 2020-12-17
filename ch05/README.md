### Exercise 5.1
> What is a null statement? When might you use a null statement?

A null statement consists of a single semi-colon. It is used as a placeholder for situations where c++ syntax rules demand an expression.

### Exercise 5.2
> What is a block? When might you use a block?

A block is a sequence of code consisting of any number of statements, which are enclosed in curly braces. We use a block to group satements that perform a specified task.

### [Exercise 5.3](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-03.cpp)

### Exercise 5.4
> Explain each of the following examples, and correct any problems you detect.
```c++
(a) while (string::iterator iter != s.end()) {....}
// Illegal. Cannot declare the iterator within the while condition.
//Better:
string::iterator iter = s.begin();
while (iter != s.end() ) {.......increment iter somewhere....}
if (!status){....}

(b) while (bool status = find(word)) {...}
// Illegal. Cannot declare the bool within the while condition.
//Better:
bool status;
while (status = find(word)) {...some condition modifier here...}
if (!status){....}
```

### [Exercise 5.5](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-05.cpp)

### [Exercise 5.6](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-06.cpp)

### Exercise 5.7
> Correct the errors in each of the following code fragments.
```c++
(a) if (ival1 != ival2) ival1 = ival2      
    else ival = ival = 0;

(b) if (ival < minval)                  
    minval = ival;
    occurs = 1;

(c) if (int ival = get_value())         
    cout << "ival = " << ival << endl;

    if (!ival) cout << "ival = 0\n";

(d) if (ival = 0)
    ival = get_value();
```

```c++
(a) if (ival1 != ival2) ival1 = ival2;    //missing semi-colon after ival2
 else ival = ival = 0;

(b) if (ival < minval) {                 //missing braces around the following statements
       minval = ival;
       occurs = 1;
    }                  
   
(c) int ival;                            //need to declare ival outside of if statement
    if (ival = get_value()) cout << "ival = " << ival << endl;
    if (!ival) cout << "ival = 0\n";

(d) if (ival == 0)                      //relational - not assignment - operator required, 
    ival = get_value();
```

### Exercise 5.8
> What is a "dangling else"? How are else clauses resolved in C++?

This refers to a situation where, when we have nested ifs, we end up with more if branches than else branches. To resolve this possible problem, the compiler pairs an else
with the closest preceding unmatched if.

### [Exercise 5.9](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-09.cpp)

### [Exercise 5.10](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-10.cpp)

### [Exercise 5.11](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-11.cpp)

### [Exercise 5.12](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-12.cpp)

### Exercise 5.13
> Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.
```c++
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;     //missing break statenents
    char ch = next_text();
    switch (ch) 
    {
      case 'a': 
      aCnt++;
      break;

      case 'e': 
      eCnt++;
      break;

      default: 
      iouCnt++;
    }

(b) unsigned index = some_value();
    int ix;                                 //bypassing initialized variable 
    switch (index) 
    {
      case 1:
        ix = get_value();
        ivec[ix] = index;
        break;

      default:
        ix = ivec.size()-1;
        ivec[ix] = index;
    }

(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) 
    {
      case 1, 3, 5, 7, 9:
        oddcnt++;
        break;

      case 2, 4, 6, 8, 0:                   //case label should be 0, not 10
        evencnt++;
        break;
    }

(d) const unsigned ival=512, jval=1024, kval=4096;        //case labels must be const expressions
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) 
    {
      case ival:
        bufsize = ival * sizeof(int);
        break;

      case jval:
        bufsize = jval * sizeof(int);
        break;

      case kval:
        bufsize = kval * sizeof(int);
        break;
    }
```

### [Exercise 5.14](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-14.cpp)

### Exercise 5.15
> Explain each of the following loops. Correct any problems you detect.

```c++
(a) for (int ix=0; ix!=sz; ++ix) {....}
    if (ix!=sz)

//correction: ix cannot be accessed outside of for loop.
int ix;
for (ix=0; ix !=sz; ++ix) {...}
if (ix!=sz)

(b) int ix;
    for (ix!=sz; ++ix) {...}

//correction: null statement needed in for loop
int ix;
    for (; ix!=sz; ++ix) {...}

(c) for (int ix=0; ix!=sz; ++ix, ++sz) {...}

//correction: sz increment leads to an infinite loop
for (int ix=0; ix!=sz; ++ix) {...}
```

### Exercise 5.16 
> The while loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The for loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?

```c++
(a) while rewritten as for
string input;
while (cin >>input) {.....}

for (string input; cin >>input;) {....}

(b) for rewritten as while
for (auto i= v.begin(); i!=v.end(); ++i) {.....}

auto i=v.begin();
while (i!=v.end())  {.....++i}

// I prefer the for loop, since it is terser and more versatile than the while.
```

### [Exercise 5.17](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-17.cpp)

### Exercise 5.18
> Explain each of the following loops. Correct any problems you detect.
```c++
// (a) is missing enclosing braces

do { 
    int v1, v2;
    cout << "Please enter two numbers to sum:" ;
    if (cin >> v1 >> v2)
      cout << "Sum is: " << v1+v2 << endl;
    } while (cin);

// (b) ival should be declared outside of the loop

int ival;
    do {
    } while (ival = get_response()); 

// (c) ival should be initialized outside of the loop

int ival = get_response();
    do 
    {
      ival = get_response();
    } while (ival); 
```

### [Exercise 5.19](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-19.cpp)

### [Exercise 5.20](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-20.cpp)

### [Exercise 5.21](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-21.cpp)

### Exercise 5.22
> The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.
```c++
//for loop
for (int sz=get_size(); sz<=0; sz=get_size());

//while loop
int sz=0;
while ((sz=get_size())<=0);
```

### [Exercise 5.23](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-23.cpp)

### [Exercise 5.24](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-24.cpp)

### [Exercise 5.25](https://github.com/ss-haze/cpp_primer/blob/main/ch05/5-25.cpp)






