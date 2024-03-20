# Basics

## Build and run a project
- we can build project at build tab. After building, we can see command for build process at codelite's build terminal. I got screenshot.
- The build process consists of two stages: compile and linker.
- compiler: The compiler takes the preprocessed source code and translates it into assembly code or an intermediate representation. This step produces object files (files with a .o or .obj extension), which contain machine code specific to the target architecture but are not yet executable.
- Linker: If your program consists of multiple source files or uses external libraries, the linker combines the object files into a single executable file. It resolves references between different parts of the program and links in necessary library code.
- After linking a executable file created. In linux that file has an extension .out.
- files created under the Debug folder. You can see it.
- We can see commands in compile_command.json file.
- example command bellow.
    ```
    # Compile source code and generate object file
    gcc -c program.c //this command's output is a object file

    # Link object file(s) and create executable
    gcc -o program program.o //this command generate executable file

    # Run the executable
    ./program

    ```
+ we can clean project pressing clean button. After that terminal shows up command like deleting build files. Clean process deletes build files under debug-build folder. Example command is below.
    ```
    rm -f -r Debug/
    ```
---
## Errors and Warnings
- **Complier Error**
    - **Syntax error** is a type of error that occurs when the structure or syntax of a programming language is violated. It means that the code does not conform to the language's grammar rules, resulting in a failure to compile or interpret the program. Syntax errors are often caused by mistakes in the way code is written, such as missing or misplaced punctuation, incorrect keyword usage, or violating other language-specific rules.
        ```
        printf("Hello, world!")
        ```
    - **Semantic errors** are a type of programming error that occurs when the code is syntactically correct, meaning it follows the grammar and structure of the programming language, but it does not produce the expected or desired behavior. Unlike syntax errors, which prevent the code from compiling, semantic errors result in a program that compiles successfully but does not work as intended.Semantic errors are often related to the logic or meaning of the code rather than its structure. These errors can lead to unexpected results or undesired behavior during the program's execution. Debugging semantic errors can be more challenging than fixing syntax errors because the code is grammatically correct, and the error is related to the intended logic of the program.Adding a string to an integer.



    - **Undefined Symbols** When a variable or function is used but not declared or defined, the compiler will generate an error.
        ```
        int x = y + 5;
        ```
    - **Missing Header Files** If a required header file is not included or if there are errors in the included headers, the compiler may produce errors.
        ```
        #include <stdioo.h>
        ```
    - **Invalid Function Calls** Attempting to call a function with the wrong number or type of arguments can lead to errors.
        ```
        int add(int a, int b) {
        return a + b;
        }

        int main() {
            int sum = add(3, "world");
        }
        ```
- **Complier Warning**

    - **Unused Variables or Functions** The compiler warns when it detects variables or functions that are declared but not used within the code.
    - **Type warnings** occur when there is a mismatch between the expected data type and the actual data type used in the code.
        ```
        int result = "Hello";
        ```
    - **Type Mismatch or Conversion Warnings** Warnings about implicit type conversions or potential loss of data during assignments.
        ```
        int x = 3.14
        ```
    - **Format String Mismatches**
        ```
        int x;
        printf("%f", x);
        ```
    - **Uninitialized Variables** Warnings about using variables that may not have been initialized.

- **Linker Error** 
    - Linker errors occur during the linking phase of the compilation process when the linker is combining multiple object files and libraries to generate the final executable. These errors typically involve unresolved symbols or issues with the linkage of different parts of the program.
    - **Undefined Reference** This error occurs when the linker cannot find the definition for a function or variable that is used in the code.
    - **Multiple Definitions** This error occurs when the same symbol is defined in multiple source files or libraries.
    - **Missing Library** When a function or variable is used from a library, but the library is not properly linked, you'll get an undefined reference error.
    - **Incorrect Function Signature** If the function signature (prototype) in one source file does not match the actual definition in another source file, a linker error will occur.

- **Logic Error** 
    - Logic errors, also known as semantic errors, occur when there is a flaw in the reasoning or logic of a program's code. Unlike syntax errors, which involve incorrect language structure and are usually caught by the compiler, logic errors may not result in immediate error messages or crashes. Instead, they lead to unexpected and incorrect behavior during program execution.
    - Incorrect Conditions: If the conditions in your program's control structures (like if statements or loops) are not correctly formulated, the program may not behave as intended.
    - Incorrect Order of Operations: If the sequence of operations in your code is not logical or does not follow the desired order, it can lead to unexpected results.
    - Variable Misuse: Using variables incorrectly, such as assigning the wrong values or misinterpreting their scope, can introduce logic errors.
    - Algorithmic Errors: Flaws in the underlying algorithm or logic of the program can cause incorrect results.
    - Boundary Cases: Failing to account for boundary conditions or special cases in your code can lead to logic errors.
    - Misinterpretation of Requirements: If there's a misunderstanding of the specifications or requirements, the resulting code may not meet the intended functionality.
- **Runtime Error**
    - Runtime errors, also known as execution-time errors, occur while a program is running. Unlike syntax errors, which are detected by the compiler, runtime errors happen when the program is in the process of execution. These errors can cause the program to terminate abnormally or produce unexpected results. Here are some common types of runtime errors.
    - Divide by Zero: Attempting to divide a number by zero is a common cause of runtime errors. This situation is usually not allowed in programming languages, and attempting such an operation may lead to a runtime error.
    - Null Pointer Dereference: Trying to access or dereference a pointer that has not been assigned a valid memory address (is set to null or points to an undefined location) can result in a runtime error.
    - Array Index Out of Bounds: Accessing an array element with an index that is outside the valid range (e.g., accessing an element at index -1 or beyond the array size) can lead to a runtime error.
    - Type Mismatch: Performing operations on incompatible data types or attempting to assign a value of one type to a variable of another type can result in a runtime error.
    - File Not Found: If a program attempts to open or access a file that doesn't exist, it can lead to a runtime error.
    - Infinite Recursion: Recursive functions that do not have proper termination conditions can lead to a stack overflow, causing a runtime error.
    - Memory Allocation Failures: If a program attempts to allocate memory dynamically using functions like malloc or new and fails to do so, it can result in a runtime error.

        Runtime errors can be more challenging to identify and debug than syntax errors because they occur during program execution. Techniques such as using debugging tools, printing intermediate values, and systematically tracing the program's execution can help locate and resolve runtime errors.

        Runtime errors can be more challenging to identify and debug than syntax errors because they occur during program execution. Techniques such as using debugging tools, printing intermediate values, and systematically tracing the program's execution can help locate and resolve runtime errors.


