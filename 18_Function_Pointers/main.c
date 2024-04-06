#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
//###########################################################################################
void fun(int a) 
{ 
    printf("Value of a is %d\n", a); 
} 

void basic_function_pointer() {
    /*
    Why do we need an extra bracket around function pointers like fun_ptr in above example?
    If we remove bracket, then the expression “void (*fun_ptr)(int)” 
    becomes “void *fun_ptr(int)” which is declaration of a function 
    that returns void pointer. 
    */
    void (*fun_ptr)(int);
    fun_ptr = &fun;

    printf("addres of function %p\n",fun_ptr);
    //printf("value of function %d\n", *fun_ptr);

    //üsteki ile aynı şey
    printf("fun %p\n",fun);
    //printf("*fun %d\n", *fun);
    
  
    (*fun_ptr)(10); //(fun_ptr)(10); yapınca da hata vermiyor
    (*fun)(10);
    fun(10);
}
//###########################################################################################
void basic_function_pointer2() {
    void (*fun_ptr)(int);
    fun_ptr = fun;

    printf("addres of function %p\n",fun_ptr);
    //printf("value of function %d\n", *fun_ptr);

    printf("fun %p\n",fun);
    //printf("*fun %d\n", *fun);
    
  
    (fun_ptr)(10); //(*fun_ptr)(10); yapınca da hata vermiyor
}
//###########################################################################################
int add_2(int a, int b) {
    return a + b;
}
void basic_function_pointer3() {
    int (*funcPtr)(int, int);

    // Fonksiyon işaretçisine add fonksiyonunun adresini atama
    funcPtr = &add_2;

    // Fonksiyon işaretçisi aracılığıyla fonksiyonu çağırma
    int result = (*funcPtr)(10, 20);
    printf("Result: %d\n", result);
}
//###########################################################################################
void add(int a, int b) 
{ 
    printf("Addition is %d\n", a+b); 
} 
void subtract(int a, int b) 
{ 
    printf("Subtraction is %d\n", a-b); 
} 
void multiply(int a, int b) 
{ 
    printf("Multiplication is %d\n", a*b); 
} 

void array_function_pointers() {
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply}; 
    unsigned int a = 15, b = 10;

    for (int i=0; i<3; i++) {
        (fun_ptr_arr[i])(a, b);
    } 
}
//###########################################################################################
void fun1() { printf("Fun1\n"); } 
void fun2() { printf("Fun2\n"); } 

void wrapper(void (*fun)()) 
{ 
    fun(); 
}
void function_pointer_as_argument() {
    wrapper(fun1); 
    wrapper(fun2); 
}

//###########################################################################################
//intermediate Example
// açıklaması readme de var
int compare (const void* a, const void* b) { 
    return ( *(int*)a - *(int*)b ); 
} 

void intermediate_example() {
    int arr[] = {10, 5, 15, 12, 90, 80}; 
    int n = sizeof(arr)/sizeof(arr[0]), i; 

    qsort(arr, n, sizeof(int), compare); 

    for (i=0; i<n; i++) 
        printf ("%d ", arr[i]); 
    printf("\n");
}

//###########################################################################################
//intermediate Example-2
bool compare_2 (const void * a, const void * b) { 
  return ( *(int*)a == *(int*)b ); 
} 

int search(void *arr, int arr_size, void *x, 
           bool (*compare) (const void * , const void *)) 
{ 
    int *ptr = (int *)arr; //casting
  
    int i; 
    for (i=0; i<arr_size; i++) 
        if (compare(ptr + i, x)) 
           return i; 
  
    // If element not found 
    return -1; 
} 

int search2(void *arr, int arr_size, void *x, 
           bool (compare) (const void * , const void *)) 
{ 
    int *ptr = (int *)arr; //casting
  
    int i; 
    for (i=0; i<arr_size; i++) 
        if (compare(ptr + i, x)) 
           return i; 
  
    // If element not found 
    return -1; 
} 

void intermediate_example_2() {
    int arr[] = {2, 5, 7, 90, 70}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 90; 
    printf ("Returned index is %d \n", search(arr, n, &x, &compare_2)); 
    x = 2;
    printf ("Returned index is %d \n", search(arr, n, &x, compare_2));
    x = 5;
    printf ("Returned index is %d \n", search2(arr, n, &x, &compare_2));
    x = 70;
    printf ("Returned index is %d \n", search2(arr, n, &x, compare_2));
}

int main() 
{   
    printf("\nBasic funciton pointer ex #####################\n");
    basic_function_pointer();

    printf("\nBasic funciton pointer ex2 #####################\n");
    basic_function_pointer2();

    printf("\nBasic funciton pointer ex3 #####################\n");
    basic_function_pointer3();

    printf("\narray_function_pointers #####################\n");
    array_function_pointers();

    printf("\nfunction_pointer_as_argument #####################\n");
    function_pointer_as_argument();

    printf("\nintermediate_example #####################\n");
    intermediate_example();

    printf("\nintermediate_example-2 #####################\n");
    intermediate_example_2();
    return 0; 
} 