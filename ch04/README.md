### Exercise 4.1
> What is the value returned by 5 + 10 * 20/ 2?

5 + 10 * 20/ 2 = 5 + 200/2 = 5 + 100 = 105

### Exercise 4.2
> Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:

(a) * vec.begin()  
The order is member selector -> member function -> dereference
i.e. *( (vec.begin) () )

(b) * vec.begin() + 1   
The order is member selector -> member function -> dereference -> addition
i,e. (* (vec.begin) () ) ) + 1


### Exercise 4.3
> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

I think it is acceptable. One can always explicitly force evaluation order through the use of parentheses.

### Exercise 4.4
> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.

12 / 3 * 4 + 5 * 15 + 24 % 4 / 2

= ((12/3)*4) + (5*15) + (24%(4/2) 

= (4*4) + 75 + (24%2)

= 16 + 75 + 0 

= 91


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
```c++
int x=20;
if (x%2) cout <<"x is odd";
else cout << "x is even";

// or, using bitwise operator:

if (x & 01) cout << "x is odd";
else cout << "x is even";
```

### Exercise 4.7
> What does overflow mean? Show three expressions that will overflow.

Overflow occurs when the result of an expression is stored in a type for which the result is outside the type's range.

e.g.
```c++
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

The logical AND and OR operators use short-ciruiting:

(a) The left hand operand is first evaluated

(b) For AND, the right hand operand is evaluated iff (a) evaluates to true

(c) For OR, the right hand operand is evaluated iff (a) evaluates to false

The equality operator evaluates both the right and left hand operand and then compares them. 
The order of evaluation is compiler determined.


### Exercise 4.9
> Explain the behavior of the condition in the following if:
```c++
const char *cp = "Hello World";
if (cp && *cp)
```
(a) The left hand operand (cp) is first evaluated.

(b) It is not a nullptr, therefore this operand evaluates to true.

(c) The right hand operand (*cp) is then evaluated.

(d) *cp does not equal zero, therefore this operand evaluates to true.

(e) The conditional statment evaluates to true.

### Exercise 4.10
> Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.
```c++
while (cin >> input && input!=42){/*.....*/}
```

### Exercise 4.11
> Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, which is greater than c, which is greater than d.
```c++
 if (a>b && b>c && c>d) {/*......*/}
```

### Exercise 4.12
> Assuming i, j, and k are all ints, explain what i != j < k means.

The right hand operand (j>k) evaluates to a bool, which evaluates to either true of false.

The expression is either i != true, or i != false. Since i is an int, the expression evaluates to either i != 1, or i != 0.

### Exercise 4.13
> What are the values of i and d after each assignment?

int i; double d;

(a) d = i = 3.5;      // d=3.0, i=3

(b) i = d = 3.5;      // d=3.5, i=3

### Exercise 4.14
> Explain what happens in each of the if tests.
```c++
if (42=i)
//error: we cannot assign to an int literal

if (i = 42)
//this always evaluates to true. Better: 
if (i==42)
```












