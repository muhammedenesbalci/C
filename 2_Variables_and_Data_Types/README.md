# Variables and Data Types

## Enum
- Enum is a data type used to define a set of named integer constants. It provides a way to create a group of named integer constants, making the code more readable and maintainable. The syntax for declaring an enum is as follows
    ```
    enum enum_name {
    constant1,
    constant2,
    constant3,
    /* ... */
    };

    ```
    ```
    #include <stdio.h>

    enum Weekday {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };

    int main() {
        enum Weekday today = Wednesday;

        printf("Today is day number %d\n", today);

        return 0;
    }

    ```

    In this example, the Weekday enum defines seven constants, each representing a day of the week. By default, they are assigned values starting from 0. In the main function, we declare a variable today of type enum Weekday and assign it the value Wednesday. The program then prints the corresponding numeric value of Wednesday, which is 2.

    Enums provide a way to create symbolic names for integral constants, making the code more self-explanatory and enhancing code readability.

## Arguments
- We can give arguments to our program. Main function takes two argument. 
    ```
    int main(int argc, char *argv[])
    {    
        return 0;
    }
    ```
- The first argument is count of given arguments on cli.
- The second argument is real arguments. the first one is program's name other ones other arguments.
- we can run this program like below.
    ```
    gcc -c main.c
    gcc -o main main.o
    ./main 5(argument one) 6(argument two)
    ```