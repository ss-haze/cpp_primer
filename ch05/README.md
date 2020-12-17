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
   

(c) int ival;                             //need to declare ival outside of if statement
    if (ival = get_value()) cout << "ival = " << ival << endl;
    if (!ival) cout << "ival = 0\n";

(d) if (ival == 0)              //relational - not assignment - operator required, 
    ival = get_value();
    ```
