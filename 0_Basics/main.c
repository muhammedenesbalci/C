#include <stdio.h>

void first_program() {
    //Building and Compiling first program
	int myFavNum = 0;
    
    printf("Enter a number:  \n");
    
    scanf("%d", &myFavNum);
    
    printf("your number: %d \n", myFavNum);
    }
    
void complier_errors() {
    //Syntax Error
    printf("Hello, world!")
    
    //Undefined Symbols
    int x = y + 5;
    
    }      
    
void complier_warnings(){
    //Type warning
    int x = 3.14;
    int y;
    printf("%f", y);
    
    //Type warning
    int result = "Hello";
        
    }
    
void runtime_error() {
    
    int a = 0;
    int b = 4;
    int c = b/a;
    }

int main()
{
    first_program();
    complier_errors();
    complier_warnings();
    runtime_error();

	return 0;
}
