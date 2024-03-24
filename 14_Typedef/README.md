# typedef
# Informations
- The typedef is a keyword that is used to provide existing data types with a new name. The C typedef keyword is used to redefine the name of already existing data types.
- When names of datatypes become difficult to use in programs, typedef is used with user-defined datatypes, which behave similarly to defining an alias for commands.

# Use of typedef in C
- The typedef keyword gives a meaningful name to the existing data type which helps other users to understand the program more easily.
- It can be used with structures to increase code readability and we don’t have to type struct repeatedly.
- The typedef keyword can also be used with pointers to declare multiple pointers in a single statement.
- It can be used with arrays to declare any number of variables.

    ```c
    typedef existing_name alias_name;
    typedef long long ll;
    ```
    ```c
    // C program to implement typedef
    #include <stdio.h>
    
    // defining an alias using typedef
    typedef long long ll;
    
    // Driver code
    int main()
    {
        // using typedef name to declare variable
        ll var = 20;
        printf("%ld", var);
    
        return 0;
    }
    ```

- **struct** typedef can also be used with structures in the C programming language. A new data type can be created and used to define the structure variable.

- **Pointers** typedef can also be used with pointers as it gives an alias name to the pointers. Typedef is very efficient while declaring multiple pointers in a single statement because pointers bind to the right on the simple declaration. 
    ```c
    typedef int* Int_ptr;
    Int_ptr var, var1, var2;
    ```
- **Arrays** typedef can also be used with an array to increase their count. 
    ```c
    typedef int arr[20];
    // it's same as Arr[20], two-Arr[20][23];
    arr Arr, two_Arr[23];
    ```