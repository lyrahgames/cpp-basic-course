# Types and Variables

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

Hence, from an abstract point of view we can think of `number` as a variable of type `int` with the name `number` and a certain value which should be an integral number.

```cpp
    bool is_done; // Boolean, possible values are 'true' or 'false'
    char letter; // every ASCII character
    int number; // integer
    float real; // single-precision floating point number
    double dreal; // double-precision floating point number
```