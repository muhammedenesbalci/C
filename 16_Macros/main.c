#include <stdio.h>
 

// Object-Like Macros
#define DATE 31
void object_like_macros() {
    printf("Lockdown will be extended upto %d-MAY-2020\n", DATE);
}

// Chain Macros
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138
void chain_macros() {
    printf("I have %dK followers on Instagram\n", INSTAGRAM);
}
// Multi-Line Macros
#define ELE 1, \
            2, \
            3
void multi_line_macros() {
    int arr[] = { ELE };
 
    // Print elements
    printf("Elements of Array are:");
 
    for (int i = 0; i < 3; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

// Function-Like Macros
#define min(a, b) (((a) < (b)) ? (a) : (b))
void function_like_macros() {
    int a = 18;
    int b = 76;
 
    printf("Minimum value between %d and %d is %d\n", a, b, min(a, b));
}

// Function-Like Macros-2
#define  PI  3.1416
#define  AREA(r)  (PI*(r)*(r))
void function_like_macros_2() {
    float r = 7;    // radius of circle
    
    printf("Area of Circle with radius %.0f: %.3f\n", r, AREA(r));
}

int main()
{
    printf("object_like_macros-----------------------------------\n");
    object_like_macros();

    printf("chain_macros-----------------------------------\n");
    chain_macros();

    printf("multi_line_macros-----------------------------------\n");
    multi_line_macros();

    printf("function_like_macros-----------------------------------\n");
    function_like_macros();

    printf("function_like_macros_2-----------------------------------\n");
    function_like_macros_2();
    return 0;
}