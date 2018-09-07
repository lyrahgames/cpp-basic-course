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

## Naming

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

Let `X` be an arbitrary type and `a` be a variable of type `X`.
Then an initializer determines the initial value `v` of `a`.
This can be written in four different styles.

### Brace-enclosed Initializer
The brace-enclosed initializer can be used in every context.
The second case is a little bit more verbose and comes from the old C days.
Hence, it is recommended to use the first initializer.
```cpp
    X a{v};
```
The brace-enclosed initializer should not allow narrowing.
At least the compiler will throw a warning message about narrowing.
```cpp
    float x;    // declare float variable with no initializer
    int a{x};   // error or warning: possible truncation
```

### Copy Initializer
The copy initializers should only be used if there is a strong reason not to use the brace-enclosed initializer.
Such reasons will be explained in the next section.
```cpp
    X a = v;    // use this only for simple variables with simple values
    X a = {v};  //
    X a(v);     // we will use this one for constructors of some classes
```
For built-in types the copy initializer performs a so-called implicit conversion.
A variable of type `float` will automatically truncated if it is assigned to a variable of type `int`.
```cpp
    float x{1.5};   // initialize x with value 1.5
    int a = x;      // initialize a with 1
```
The compiler will not warn about such implicit conversions.
Hence, these initializers are prone to errors when used without caution.

### Literals
To initialize a variable to a given constant value one can use so-called *literals*.
Literals are a special case of constant values and can described directly through the source code.
A variable of type `bool` for example can be set to two different values.
These values can be expressed with the literals `true` and `false` (in this case they are even keywords).
```cpp
    bool x = true;
    bool y = false;
```
#### Character Literals
For other types the literals are changing.
```cpp
    char a = 'a';
    char b = '\n';
    char c = '\"';
```
#### Integer Literals
```cpp
    int n = 1234;
```
#### Floating-point Literals
```cpp
    float f = 1.1f;
    float x = 1e5f;
    double d = 1.2;
```

### Using `auto`
C++ is a strongly-typed language.
This means that every variable has a unique and concrete type.
Until now one had to explicitly state the type of a variable when declaring it.
Sometimes this seems to be a little cumbersome.
In C++ we can use the keyword `auto` to implicitly deduce the type of the variable from its initial value.
```cpp
    auto b = true;
    auto c = 'x';
    auto i = 123;
    auto d = 1.2;
    auto f = 1.1f;
    auto s = sqrt(f);
```
In the case of the built-in types there is no big advantage using the keyword `auto`.
But if the type of expressions becomes more and more complicated, `auto` becomes more useful.
Assume for example measuring the time needed to run sum function `f` without the using `auto` and the system clock.
```cpp
    
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    f();
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    float duration = std::chrono::duration<float>(end - start).count();
```

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