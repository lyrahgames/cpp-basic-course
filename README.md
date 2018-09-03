# Introduction to Programming with C++

As Bjarne Stroustrup, the creator of C++, wrote in the preface to the 4. edition of his book:
>The use of C++ has changed dramatically over the years and so has the language.
>From the point of view of a programmer, most of the changes have been improvements.
>The current ISO standard C++ (..., usually called C++11) is simply a far better tool for writing quality software than were previous versions.
>...
>C++ is a general-purpose programming language emphasizing the design and use of type-rich, lightweight abstractions.
>It is particularly suited for resource-constrained applications, such as those found in software infrastructures.
>C++ rewards the programmer who take the time to master techniques for writing quality code.
>C++ is a language for someone who takes the task of programming seriously.

## Background
### Hardware, Software and Abstraction Mechanisms
### Why C++?
### Why not C++?
### C++ is not C
As Bjarne Stroustrup, the creator of C++, wrote in his book about C compatibility:

>C++ was developed from the C programming language and, with a few exceptions, retains C as a subset.
>The main reasons for relying on C were to build on a proven set of low-level language facilities and to be part of a technical community.
>...
>One hundred percent C/C++ compatibility was never a goal for C++ because that would compromise type safety and the smooth integration of user-defined and built-in types.
>However, the definition of C++ has been repeatedly reviewed to remove gratuitous incompatibilities; C++ is now more compatible with C than it was originally.
>...
>C’s facilities for low-level systems programming tasks are retained and enhanced; for example, see `inline` [...] and `constexpr` [...].
>Conversely, modern C has adopted (with varying degrees of faithfulness and effectiveness) many features from C++ (e.g., `const` , function prototypes, and inlining, [...]).

>The difference between C and C++ is primarily in the degree of emphasis on types and structure.
>C is expressive and permissive.
>Through extensive use of the type system, C++ is even more expressive without loss of performance.
>Knowing C is not a prerequisite for learning C++.
>Programming in C encourages many techniques and tricks that are rendered unnecessary by C++ language features.
>For example, explicit type conversion (casting) is less frequently needed in C++ than it is in C (§1.3.3).
>However, good C programs tend to be C++ programs.
>For example, every program in Kernighan and Ritchie, The
C Programming Language, Second Edition [...], is a C++ program.


## Setting up the Basic Build Environment
### C++ Compiler
### Editor

## Style Guides and Automatic Formatting
- [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)
- [Bjarne Stroustrup: C++ Style and Technique FAQ](http://www.stroustrup.com/bs_faq2.html)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

## References and Literature
### Online References
To remember every C++ command and how to use it should be impossible.
Therefore some references for the C++ language and their respective standard libraries is obligatory.
Especially online references seem to be most efficient, because the complete content can be accessed nearly everywhere at every time.
We recommend the following:
- [cppreference.com](https://en.cppreference.com/w/)
- [cplusplus.com](http://www.cplusplus.com/)

CMake is a powerful tool for generating your build system independent of the underlying computer system.
The official documentation describes every command in detail.
- [CMake Reference Documentation](https://cmake.org/documentation/)
- [Effective Modern CMake](https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1)
- [Awesome CMake](https://github.com/onqtam/awesome-cmake)

### Reference Books
For convenience, one should use some good books or e-books in addition to online sources.
The best books in our opinion are the books by 'Bjarne Stroustrup', the creator of C++.
- Bjarne Stroustrup, *Programming: Principles and Practice Using C++*
- Bjarne Stroustrup, *The C++ Programming Language*
- Herbert Schildt, *C++: The Complete Reference*

### Further Reading
- Stephan Roth, *Clean C++: Sustainable Software Development Patterns and Best Practices with C++17*
- Scott Meyers, *Effective C++: 55 Specific Ways to Improve Your Programs and Designs*
- Scott Meyers, *Effective Modern C++: 42 Specific Ways to Improve Your Use of C++11 and C++14*
- Andrei Alexandrescu, *Modern C++ Design: Generic Programming and Design Patterns Applied*
- Jeff Langr, *Modern C++ Programming with Test-Driven Development: Code Better, Sleep Better*
- Agner Fog, *Optimization Manuals*
- David A. Patterson and John L. Hennessy, *Computer Organization and Design: The Hardware/Software Interface*

## External Libraries
- [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page): C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms
- [Qt](https://www.qt.io/): Library for creating fluid, high-performance and intuitive UIs, applications, and embedded devices – with the same code base for all platforms
- [doctest](https://github.com/onqtam/doctest): C++ testing framework which is by far the fastest both in compile times and runtime compared to other feature-rich alternatives

## What to learn after this course?
- Lecture *Algorithm Engineering*
- git

## Authors
- Markus Pawellek (markuspawellek@gmail.com)
- Clemens Anschütz (clemens.anschuetz@uni-jena.de)