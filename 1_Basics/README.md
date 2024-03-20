# Basics
## Content
- printf
- scanf
- Header files
- Preprocessor
## Informations
- **Preprocessor** In the C programming language, the preprocessor is a phase of the compilation process that occurs before the actual compilation of the source code. Its primary purpose is to handle directives, which are special commands that begin with a # symbol. The preprocessor performs text manipulation on the source code before it is passed to the compiler. Some common preprocessor directives include.The preprocessor operates on the source code text and generates an intermediate code, which is then passed to the compiler for further processing. The preprocessor's role is crucial for tasks like code modularization, inclusion of header files, and conditional compilation.
    - **#include** This directive is used to include the contents of another file in the source code. It is often used to include header files that declare functions, macros, and other elements.
        ```
        #include <stdio.h>
        ```
    - **#define** This directive is used to create symbolic constants or macros. It allows you to define a name for a constant value or a block of code that can be used throughout the program.
        ```
        #include <stdlib.h> // we need this library
        #define PI 3.14159
        ```
    - **#ifdef, #ifndef, #else, #endif** These directives are used for conditional compilation. They allow you to include or exclude certain portions of code based on whether a particular macro is defined.
        ```
        #ifdef DEBUG
        // Debugging code
        #else
        // Release code
        #endif
        ```
    - **pragma** This directive provides a way to give special instructions to the compiler. The behavior of pragma directives can vary between different compilers.
        ```
        #pragma warning(disable : 4996) // Disable a specific warning
        ```
- **Header file** is a file with extension .h which contains C function declarations and macro definitions to be shared between several source files. There are two types of header files: the files that the programmer writes and the files that comes with your compiler.