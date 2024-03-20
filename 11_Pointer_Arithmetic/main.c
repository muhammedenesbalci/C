#include <stdio.h>
#include <string.h>

int arraySum1(int array[], const int n) {
    int sum = 0;
    int *ptrElement;
    int *ptrArrayEnd = array + n;
    
    for(ptrElement = array; ptrElement < ptrArrayEnd; ptrElement++) {
        sum+=*ptrElement;
        }
        
    return sum;
    
    }
    
int arraySum2(int *firstElementArray, const int n) {
    int sum = 0;
    int *ptrElement;
    int *ptrArrayEnd = firstElementArray + n;
    
    for(ptrElement = firstElementArray; ptrElement < ptrArrayEnd; ptrElement++) {
        sum+=*ptrElement;
        }
        
    return sum;
    
    }
    
int arraySum3(int *array, const int n) {
    int sum = 0;
    int *ptrArrayEnd = array + n;
    
    for(; array < ptrArrayEnd; array++) {
        sum+=*array;
        }
        
    return sum;
                              
    }
         
void array_string() {
    int i;
    char multiple[] = "astring";
    char *ptr = multiple;
    
    //adresler 1 1 artiyor dikkat ettiysen
    // %s özel bir işaretçi pointer veriyoruz ve /0 a kadar olan kısmı alıyor dikka ettiysen
    for (i = 0; i <=strlen(multiple) + 1; i++) {
        printf("multiple[%d] = %c || *(ptr+%d) = %c || &multiple[%d] = %p || (ptr+%d) = %p || (ptr+%d):%s \n", i, multiple[i], i, *(ptr + i), i, &multiple[i], i, (ptr + i), i, (ptr+i));
        }
    
    printf("len: %ld\n", strlen(multiple));
    
    printf("size of a char: %d bytes\n", (int)sizeof(char));
    printf("size: %ld\n", sizeof(multiple));
}       

void array_long() {
    int i;
    long multiple[] = {15L, 20L, 40L, 50L};
    long *ptr = multiple;
     //adresler 8 artiyor dikkat ettiysen
    for (i = 0; i <4; i++) {
        printf("multiple[%d] = %ld || *(ptr+%d) = %ld || &multiple[%d] = %p || (ptr+%d) = %p\n", i, multiple[i], i, *(ptr + i), i, &multiple[i], i, (ptr + i));
        }
    printf("size of a long: %d bytes\n", (int)sizeof(long));
    printf("size: %ld\n", sizeof(multiple));

}       


int main(){   

    int myArray[5] = {1, 2, 3, 4, 5};
    //fonksiyona aslında sadece ilk elemanın pointerini veriyoruz normal pointer inputu şeklinde de yazabilirdik sum2 fonksiyonu
    
    printf("--------------------------------------------\n");
    printf("myArray sum: %d\n", arraySum1(myArray, 5));

    printf("--------------------------------------------\n");
    printf("myArray sum2: %d\n", arraySum2(myArray, 5));

    printf("--------------------------------------------\n");
    printf("myArray sum3: %d\n", arraySum3(myArray, 5));

    printf("--------------------------------------------\n");    
    array_string();

    printf("--------------------------------------------\n");
    array_long();
	return 0;
}
