#include <stdio.h>


void first_example() {
    int number = 10;
    int *pnumber = NULL;
    
    printf("number's value %d\n", number);
    printf("number's addres %p\n", &number);
    
    printf("pnumber's value %p\n", pnumber);
    printf("pnumber's addres %p\n", &pnumber);
    //printf("pnumber points value %d\n", *pnumber);
    
    printf("------------------------------\n");
	
    pnumber = &number;
    
    printf("pnumber's value %p\n", pnumber);
    printf("pnumber's addres %p\n", &pnumber);
    printf("pnumber points value %d\n", *pnumber);
    
    printf("size of number %ld\n", sizeof(number));
    printf("size of pnumber %ld\n", sizeof(pnumber));

    printf("------------------------------\n");

    int *ppnumber = &pnumber;
    printf("ppnumber's value %p\n", ppnumber);
    printf("ppnumber points value %p\n", *ppnumber);

    printf("size of ppnumber %ld\n", sizeof(ppnumber));
    printf("size of *ppnumber %ld\n", sizeof(*ppnumber));
    
}

void second_example(){
    int num = 150;
    int *pNum = NULL;

    pNum = &num;

    printf("num address is:  %p\n", &num);
    printf("Address of pNum: %p\n", &pNum);
    printf("value of the pNum: %p\n", pNum);
    printf("value of what pNum is pointing to: %d\n", *pNum);
    }


int main() {    
    first_example();

    printf("------------------------------\n");
    
    second_example();
  return 0;
}
