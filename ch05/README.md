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
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) 
    {
      case 'a': 
      aCnt++;

      case 'e': 
      eCnt++;

      default: 
      iouCnt++;
    }

(b) unsigned index = some_value();
    switch (index) 
    {
      case 1:
        int ix = get_value();
        ivec[ ix ] = index;
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

      case 2, 4, 6, 8, 10:
        evencnt++;
        break;
    }

(d) unsigned ival=512, jval=1024, kval=4096;
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

