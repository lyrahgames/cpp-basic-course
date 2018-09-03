# Types and Variables

## Declarations and Other Definitions
In C++ every name or expression has a type.
The type determines every operation that can be performed on the expression or name.
Let us look at an easy example of the already known type `int`.

```cpp
    int number;
```

This code snippet introduces a variable with the name `number` and the type `int`.
This is also called a declaration.
For convenience and clarity we want to use the following definitions and notations by Bjarne Stroustrup.
- A *declaration* is a statement in the program that introduces a name with a certain type to the program.
- An *object* is some memory that holds a value of some type.
- A *value* is a set of bits interpreted according to a type.
- A *variable* is a named object.

## Built-in Types

C++ offers a variety of fundamental types also called built-in types.
Every fundamental type is a keyword of the programming language and can only be used in the context of a type.
A few of these built-in types are given below.

```cpp
    bool is_done;   // Boolean, possible values are 'true' or 'false'
    char letter;    // every ASCII character
    int number;     // integer
    float real;     // single-precision floating point number
    double dreal;   // double-precision floating point number
```

Each built-in type corresponds directly to hardware facilities.
Therefore every built-in type has a fixed size in memory that determines the range of values that can be stored in it.
The size of a fundamental type is implementation-defined and can thus vary on different platforms.
This is especially useful if one wants to write code for an embedded system, like a micro-controller in a lab.
But on most 64-bit computer systems the built-in types have a common size.
The types `char` and `bool` are usually stored with one byte.
The types `int` and `float` are usually stored with four byte.
The type `double` uses even 8 bytes of computer memory.
With the keyword `sizeof` C++ introduces a function to find the actual needed memory of a type in bytes.
The following code demonstrates this.

```cpp
    #include <iostream>

    int main() {
      std::cout << "sizeof(bool) = " << sizeof(bool) << " Byte" << std::endl
                << "sizeof(char) = " << sizeof(char) << " Byte" << std::endl
                << "sizeof(int) = " << sizeof(int) << " Byte" << std::endl
                << "sizeof(float) = " << sizeof(float) << " Byte" << std::endl
                << "sizeof(double) = " << sizeof(double) << " Byte" << std::endl;
    }
```

## Initialization of Variables

Let `X` be an arbitrary type, `a` be a variable of type `X` and `v` be the initial value.
Then an initializer determines the initial value of an object.
This can be written in four different styles.

### Brace-enclosed Initializer
The brace-enclosed initializer can be used in every context and is the most general form of an initializer.
```cpp
    X a {v};    // can be used in every context
```
It does not allow narrowing.
```cpp
    float x;    // declare float variable with no initializer
    int a {x};  // error: possible truncation
```

### Copy Initializer
```cpp
    X a = v;    // use this only for simple variables with simple values
```

### Other Initializers
Other forms are given by
```cpp
    X a = {v};  // 
    X a(v);     //
```

## Initialization, Automatic Type Deduction and Type Casting
### Initialization
### Using `auto`
### Type Casting
Explicit and implicit Type casting:
```cpp
    float x;
    int y = 1;
    x = static_cast<float>(y);  // explicit
    x = y;                      // implicit
```

## Pointers
## Type Qualifiers and Modifiers
### `signed` and `unsigned`
### `const`
### `constexpr` 

## Operations and Operators

At the beginning we said, that every type determines the operations that can be performed on it.
In C++ there also exists built-in operators that can be used.

### Assignment Operator
The most fundamental operator is the assignment operator `=`.
`=` assigns a value to a variable.

```cpp
    x = 1;      // 1 is assigned to x
    x = y;      // y is assigned to x
    x = y = z;  // z is assigned to y and then to x
```

### Arithmetic Operators
Arithmetic operators are mostly used for mathematical calculations.

```cpp
    x + y;  // plus or addition
    +x;     // unary plus
    x - y;  // minus or subtraction
    -x;     // unary minus or negation
    x * y;  // multiply
    x / y;  // division
    x % y;  // remainder/modulo for integers
```

### Comparison Operators
Comparison operators are used to formulate some conditions or propositions.

```cpp
    x == y; // x is equal to y
    x != y; // x is not equal to y
    x < y;  // x is lower than y
    x > y;  // x is bigger than y
    x <= y; // x is lower or equal to y
    x >= y; // x is bigger or equal to y
```

### Logical Operators
Logical operators can be used for joining simple propositions to formulate a more complex condition.

```cpp
    !x;     // logical not: true, if x is false and vice versa
    x && y; // logical and: true, if x is true and y is true
    x || y; // logical or:  true, if x is true or y is true
```

### Bitwise Operators
For integer-like types the logical operators can be applied on a per bit basis.
The resulting operators are called bitwise operators.

```cpp
    x & y;  // bitwise and
    x | y;  // bitwise or
    x ^ y;  // bitwise xor
    ~x;     // bitwise not
    x << y; // shift bits left
    x >> y; // shift bits right
```

To show these bitwise operators in reality try the following example.

```cpp
    int x = 0110b;  // x == 6
    int y = x << 1; // y == 1100b == 12
    int z = x & y;  // z == 0100b == 4
    int a = x | y;  // a == 1110b == 14
    int b = x ^ y;  // b == 1010b == 10  
```

### Compound Assignment Operators
Compound assignment operators.

```cpp
    x += y;     // assign x the value of x+y
    x -= y;     // assign x the value of x-y
    x *= y;     // assign x the value of x*y
    x /= y;     // assign x the value of x/y
    x %= y;     // assign x the value of x%y
    x >>= y;    // assign x the value of x>>y
    x <<= y;    // assign x the value of x<<y
    x &= y;     // assign x the value of x&y
    x ^= y;     // assign x the value of x^y
    x |= y;     // assign x the value of x|y
```

### Increment and Decrement Operators
Increment and decrement operators.

```cpp
    ++x;    // increment x: x=x+1, x+=1
    --x;    // decrement x: x=x-1, x-=1
```

### Conditional Ternary Operator

```cpp
    x = (condition)?(result_true):(result_false);    // assigns x the value of result_true if the condition is true and result_false otherwise
```

### Comma operator

```cpp
    x = (x,y);
```

## Precedence of Operators