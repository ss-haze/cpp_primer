### Exercise 4.1
> What is the value returned by 5 + 10 * 20/ 2?
```
5 + 10 * 20/ 2 = 5 + 200/2 = 5 + 100 = 105
```

### Exercise 4.2
> Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
```
(a) * vec.begin()
The order is member selector -> member function -> dereference i.e. *( (vec.begin) () )

(b) * vec.begin() + 1
The order is member selector -> member function -> dereference -> addition i,e. (* (vec.begin) () ) ) + 1
```

### Exercise 4.3
> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

I think it is acceptable. One can always explicitly force evaluation order through the use of parentheses.

### Exercise 4.4
> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
```
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2

= ((12/3)4) + (515) + (24%(4/2)

= (4*4) + 75 + (24%2)

= 16 + 75 + 0

= 91
```

### Exercise 4.5
> Determine the result of the following expressions.
```
(a) -30 * 3 + 21 / 5
= (-30*3) + (21/5)
= -90 + 4
= -86

(b) -30 + 3 * 21 / 5
= -30 + ((3*21)/5)
= -30 + (63/5)
= -30 + 12
= -18

(c) 30 / 3 * 21 % 5
= (30/3)*21) % 5
= (10*21) % 5
= 210 % 5
= 0

(d) -30 / 3 * 21 % 4
= ((-30/3) * 21) % 4
= (-10 * 21) % 4
= -210 % 4
= -2
```

### Exercise 4.6
> Write an expression to determine whether an int value is even or odd.
```
int x=20;
if (x%2) cout <<"x is odd";
else cout << "x is even";

// or, using bitwise operator:

if (x & 01) cout << "x is odd";
else cout << "x is even";
```

### Exercise 4.7
What does overflow mean? Show three expressions that will overflow.

Overflow occurs when the result of an expression is stored in a type for which the result is outside the type's range.
```
e.g.

int x;

x= 10 / 0;

unsigned int z;
int a= 5, b=-10;
z = a + b;

short st= 32767;
st += 1;
```

### Exercise 4.8
> Explain when operands are evaluated in the logical AND, logical OR, and equality operators.
```
The logical AND and OR operators use short-circuiting:

(a) The left hand operand is first evaluated

(b) For AND, the right hand operand is evaluated iff (a) evaluates to true

(c) For OR, the right hand operand is evaluated iff (a) evaluates to false

The equality operator evaluates both the right and left hand operand and then compares them. The order of evaluation is compiler determined.
```

### Exercise 4.9
> Explain the behavior of the condition in the following if:
```
const char *cp = "Hello World";
if (cp && *cp)
(a) The left hand operand (cp) is first evaluated.

(b) It is not a nullptr, therefore this operand evaluates to true.

(c) The right hand operand (*cp) is then evaluated.

(d) *cp does not equal zero, therefore this operand evaluates to true.

(e) The conditional statment evaluates to true.
```

### Exercise 4.10
> Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.
```c++
while (cin >> input && input!=42){/*.....*/}
```

### Exercise 4.11
> Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, which is greater than c, which is greater than d.
``` c++
 if (a>b && b>c && c>d) {/*......*/}
 ```

### Exercise 4.12
> Assuming i, j, and k are all ints, explain what i != j < k means.
```
The right hand operand (j>k) evaluates to a bool, which evaluates to either true of false.

The expression is either i != true, or i != false. Since i is an int, the expression evaluates to either i != 1, or i != 0.
```

### Exercise 4.13
> What are the values of i and d after each assignment?
```c++
int i; double d;

(a) d = i = 3.5; // d=3.0, i=3

(b) i = d = 3.5; // d=3.5, i=3
```

### Exercise 4.14
> Explain what happens in each of the if tests.
```c++
if (42=i)
//error: we cannot assign to an int literal

if (i = 42)
//this always evaluates to true, since we testing the assigning of a value to an int. Better: 
if (i==42)
```

### Exercise 4.15
>The following assignment is illegal. Why? How would you correct it?
```c++
double dval; int ival; int *pi;
dval = ival = pi = 0;

// The assignment operator is right associative. So the first assignment is pi = 0.
// The next assignment is ival = pi, but ival is an int and pi is an int *, so no assignment is possible.

//A possible correction:
double dval; int ival; int *pi;
dval = ival = 0;
pi = 0;
```

### Exercise 4.16
> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
```
(a) if (p = getPtr() != 0)

This first evaluates getPtr() != 0 and then assigns this result to p:
p = (getPtr() != 0)  

whereas we first want to assign getPtr() to p and then test whether p != 0:
(p = getPtr())!=0

so the condition should be rewritten as:
if ((p=getPtr()) != 0)

(b) if (i = 1024)
This always evaluates to true. Better:
if (i==1024)
Exercise 4.17
Explain the difference between prefix and postfix increment.

The prefix operator increments the operand by 1 and returns the operand as an lvalue.

The postfix operator increments the operand by 1 and returns a copy of the operand's orginal value as an rvalue.
```

### Exericse 4.18
> What would happen if the while loop on page 148 that prints the elements from a vector used the prefix increment operator?
```
The loop will not print the first element of the vector. 
It will also attempt to dereference one past the last element of the vector. 
The loop will also continue to dereference memory locations until a negative value is encountered.
```

### Exercise 4.19
> Given that ptr points to an int, that vec is a vector, and that ival is an int, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
```c++
(a) ptr != 0 && *ptr++
//We first check ptr is not nullptr, then increase ptr by one, and then dereference the previous value of ptr. 
//Possible problem: ptr may now point to an undefined memory location.

(b) ival++ && ival
//We first increment the value of ival and then test the unincremented value. 
//If this value is not zero, we then test for the incremented value.

(c) vec[ival++] <= vec [ival]
//The order of evalution is undefined and can produce inconsistent results. 
//Assuming ival is 5, we could be testing either for vec[5] <= vec [6], or for vec[5] <= vec[5]. 
//A possible solution is: 
vec[ival] <= vec [ival + 1]
```

### Exercise 4.20
Assuming that iter is a vector::iterator, indicate which, if any, of the following expressions are legal. Explain the behaviour of the legal expressions and why those that aren’t legal are in error.
```c++
(a) *iter++;  
// Legal. We increment iter, and then dereference the unincremented value of iter.

(b) (*iter)++
// Illegal. We cannot increment a string.

(c) *iter.empty()
// Illegal. We are attempting to call the empty() method on iter, then dereference the result.

(d) iter->empty()
// Legal. We dereference iter, and then call the empty() method on the string.

(e) ++*iter
// Illegal. We are attempting to increment a string.

(f) iter++->empty()
// Legal. We increment iter, then dereference the original iter, then call the empty method on the string
```

### [Exercise 4.21](https://github.com/ss-haze/cpp_primer/blob/main/ch04/4-21.cpp)

### [Exercise 4.22](https://github.com/ss-haze/cpp_primer/blob/main/ch04/4-22.cpp)

## Exercise 4.23
> The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```c++
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
The expression fails because the conditional and relational operators 
have lower precedence than the addition operator.

We are adding string s to its last char, then using the relational operator
to assess whether the resulting string is the same as char 's'. 
This operation fails because the relational operator 
cannot take operands of char and string.

Fix:

string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```

### Exercise 4.24
> Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.
```
Were the operator were left associative

finalgrade = grade > 90 ? "high pass" : grade < 60  ? "fail" : "pass";
would be equivalent to

finalgrade = ( grade > 90 ? "high pass" : grade < 60 ) ? "fail" : "pass";

if grade > 90, we return "high pass", which is not an empty string, 
so the second ternary operator returns "fail".
```

### Exercise 4.25
> What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001? 'q' = 01110001
```
when converted to 32-bit int we get 00000000 00000000 00000000 01110001

~q = 11111111 11111111 11111111 10001110

~q<<6 is therefore 11111111 11111111 11100011 10000000

which is in 2-complement notation. Decimal value is -7296
```

### Exercise 4.26
> In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?
```
The minimum size of an int is 16 bits, and the minimum size of long is 32 bits. 
The teacher has 30 students, and therefore needs 30 bits for all results,
and those compilers that have int set to 16 bits would not be able to
contain all the results.
```

### Exercise 4.27
> What is the result of each of these expressions?
```c++
unsigned long ul1= 3, ul2 = 7;
(a) ul1 & ul2     //3
(b) ul1 | ul2     //7
(c) ul1 && ul2    //true
(d) ul1 || ul2    //true
```

### [Exercise 4.28](https://github.com/ss-haze/cpp_primer/blob/main/ch04/4-28.cpp)

### Exercise 4.29
> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
```
int x[10];   
int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
The first output is 10, the number of elements in the array. The second gives the size of a pointer divided by the size of an int
```

### Exercise 4.30
Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation.
```c++
sizeof x + y      // (sizeof (x)) + y 
sizeof p->mem[i]  // sizeof (p->mem[i])
sizeof a < b      // (sizeof (a)) < b
sizeof f()        // sizeof (f()) i.e. size of return type of function.
```

### [Exercise 4.31](https://github.com/ss-haze/cpp_primer/blob/main/ch04/4-31.cpp)

### Exercise 4.32
> Explain the following loop
```c++
constexpr int size = 5;
int ia[size] = { 1, 2, 3, 4, 5 };
for (int* ptr = ia, ix = 0;
     ix != size && ptr != ia + size;
     ++ix, ++ptr) { /* ... */
}
ix and ia both serve as a test for the termination for the loop.

ix terminates the loop when ix equals the size of the array, 
and the ptr terminates the loop when the pointer points to one past the last value of the array.
```

### Exercise 4.33
> Using Table 4.12 (p. 166), explain what the following expression does:
```
someValue ? ++x, ++y : --x, --y
The comma operator takes precedence over the ternary operator, so the above is equivalent to:

(someValue ? ++x, ++y : --x), --y
which says that:

(a) if someValue is 0, then increment x and y, then decrement y

(b) if someValue is not 0, decrement x, and then decrement y
```

### Exercise 4.34
> Given the variable definitions in this section, explain what conversions take place in the following expressions (remember that you may need to consider the associativity of the operators):
```
 (a) if (fval)              //conversion to bool
 (b) dval = fval + ival;    //conversion to float, and then to double
 (c) dval + ival * cval;    //conversion to int, and then conversion to double
 ```

### Exercise 4.35
> Given the following definitions, identify the implicit type conversions, if any, taking place:
```c++
char cval; 
int ival; 
unsigned int ui; 
float fval; 
double dval;

(a) cval = 'a' + 3; 
// a is promoted to an int
// it is added to 3
// the result is converted to char.

(b) fval = ui - ival * 1.0; 
// ival is converted to double
// it is multiplied by 1.0.
// The result is converted to unsigned int
// and subtracted from ui. 
// This result is converted to float and assigned to fval.

dval = ui * fval; 
// ui is promoted to float
// multiplied by fval
// the result is converted to double and assigned to dcal

cval = ival + fval + dval;  
// ival promoted to float
// added to fval
// that resul is converted to double
// addedto dval
// that result is converted to char and assigned to cval
```

### Exercise 4.36
> Assuming i is an int and d is a double write the expression i *= d so that it does integral, rather than floating-point, multiplication.
```c++
i *= static_cast<int>(d)
```

### Exercise 4.37
> Rewrite each of the following old-style casts to use a named cast:
```c++
int i; 
double d; 
const string *ps; 
char *pc; 
void *pv;

(a) pv=(void*)ps; 
//pv=static_cast<void*>(const_cast<string*>(ps));

(b) i=int(*pc);  
//i=static_cast<int>(*pc);

(c) pv=&d;       
//pv=static_cast<void*>(&d);

(d) pc=(char*)pv;
 //pc=static_cast<char*>(pv);
 ```

### Exercise 4.38
> Explain the following expression:
```c++
double slope = static_cast<double>(j/i);
The result of j/i is cast to double and then assigned to slope.
```