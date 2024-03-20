#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dersi izle heap stack mantığını iyi anlatıyor

void basics() {
    char *str;
    
    str = (char*)malloc(15); //ilk adresi veriyor
    printf("address: %p\n", str);
    printf("address: %p\n", str+1);
    printf("address: %p\n", str+2);
    printf("address: %p\n", str+3);
    printf("address: %p\n", str+4);
    printf("address: %p\n", str+5);

    printf("values: %c\n", *(str+0));
    printf("values: %c\n", *(str+1));
    printf("values: %c\n", *(str+2));
    printf("values: %c\n", *(str+3));
    printf("values: %c\n", *(str+4));
    printf("values: %c\n", *(str+5));

    printf("size of area: %ld\n", sizeof(*str)); //ilk adreste tutulan alanın boyutunu vgeriyor mantıken
    
    free(str);
    }
void basics2() {
    int *myInt;
    
    myInt = (int*)malloc(15);
    printf("address: %p\n", myInt);
    printf("values: %d\n", *(myInt+0));
    printf("values: %d\n", *(myInt+1));
    printf("values: %d\n", *(myInt+2));
    printf("values: %d\n", *(myInt+3));
    printf("values: %d\n", *(myInt+4));
    printf("values: %d\n", *(myInt+5));

    printf("size of area: %ld\n", sizeof(*myInt));
    
    free(myInt);
    }
    
void basics3() {
    int *myInt;
    
    myInt = (int*)calloc(75, sizeof(int));
    printf("address: %p\n", myInt);
    printf("values: %d\n", *(myInt+0));
    printf("values: %d\n", *(myInt+1));
    printf("values: %d\n", *(myInt+2));
    printf("values: %d\n", *(myInt+3));
    printf("values: %d\n", *(myInt+4));
    printf("values: %d\n", *(myInt+5));

    printf("size of area: %ld\n", sizeof(*myInt));
    
    free(myInt);
    myInt = NULL;
    //hepsini 0 a set ediyor
    }
    
void example() {
    char *str;
    
    str = (char*)malloc(10 * sizeof(char)); 
    strcpy(str, "jason");
    printf("str: %s, Address: %p\n", str, str);
    
    str = (char*)realloc(str, 25 * sizeof(char));
    strcat(str, ".");
    printf("str: %s, Address: %p\n", str, str); 
    
    free(str);
    }
    
void example2() {
       int size = 0;
   char *text = NULL;

   printf("Enter limit of the text: \n");
   scanf("%d", &size);

   text = (char *) malloc(size * sizeof(char));

   if (text != NULL)
   {
       printf("Enter some text: \n");
       scanf(" ");
       fgets(text, size, stdin);

       printf("Inputted text is: %s\n", text);
   }

   free(text);
   text = NULL;
    
    }
int main(){
    
    basics();
    //basics2();
    //example();
    //basics3();
	return 0;
}
