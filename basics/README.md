# The Basics

>C++ is a compiled language.
>For a program to run, its source text has to be processed by a compiler, producing object files, which are combined by a linker yielding an executable program.

Especially for C and C++ there exists a so called preprocessor, which replaces strings in a source based on defined macros.

>A C++ program typically consists of many source code files (usually simply called source files).

![Scheme of Compiler Process](images/compiler_process.png)

>An executable program is created for a specific hardware/system combination; it is not portable, say, from a Mac to a Windows PC.
>When we talk about portability of C++ programs, we usually mean portability of source code; that is, the source code can be successfully compiled and run on a variety of systems.

>The ISO C++ standard defines two kinds of entities:
>- *Core Language Features*, such as built-in types and loops
>- *Standard-library Components*, such as containers and I/O operations

>C++ is a statically typed language.
>That is, the type of every entity (e.g., object, value, name, and expression) must be known to the compiler at its point of use.
>The type of an object determines the set of operations applicable to it.