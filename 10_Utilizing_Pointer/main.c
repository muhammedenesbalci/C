#include <stdio.h>

void first_example() {
	int num = 10;	
	int *pnum = NULL;

    printf("---------------------------------\n");
	printf("num value: %d\n", num);
	printf("num addres: %p\n", &num);

	printf("pnum value: %p\n", pnum);
	printf("pnum addres %p\n", &pnum);
	//printf("pnum point value %d\n", *pnum);

    printf("---------------------------------\n");
    pnum = &num;
    printf("num value: %d\n", num);
	printf("num addres: %p\n", &num);
    
    printf("pnum value: %p\n", pnum);
	printf("pnum addres %p\n", &pnum);
    printf("pnum point value %d\n", *pnum);
    
    printf("---------------------------------\n");
    num += 20;
    printf("num value: %d\n", num);
	printf("num addres: %p\n", &num);
    
    printf("pnum value: %p\n", pnum);
	printf("pnum addres %p\n", &pnum);
    printf("pnum point value %d\n", *pnum);
    
    printf("---------------------------------\n");
    *pnum += 20;
    printf("num value: %d\n", num);
	printf("num addres: %p\n", &num);
    
    printf("pnum value: %p\n", pnum);
	printf("pnum addres %p\n", &pnum);
    printf("pnum point value %d\n", *pnum);
}

void second_example() {
    int value = 10;
    int *pvalue = &value;
    
    scanf("%d", pvalue); //zaten bir pointer olduğu için &kullanmamıza gerek kalmadı
    }

void const_pointers1() {

	int value = 10;
	const int *pvalue = &value; //değerini pointer kullanarak değiştiremeyiz
    
    //*pvalue = 20; error verir
    value = 20; //bu şekilde değiştirebilirz
    
    int value2 = 40; //adresi de değiştirebilirz
    
    pvalue = &value2;

}
void const_pointers2() {

	int value = 10;
	int *const pvalue = &value; //pointeri değiştiremeyiz
    
    *pvalue = 20; //value yi değişriebilirz
    value = 20; //bu şekilde de değiştirebilirz
    
    int value2 = 40; 
    //pvalue = &value2; adresi değiştiremeyiz
}

void const_pointers3() {

	int value = 10;
	const int *const pvalue = &value; //pointeri değiştiremeyiz // point ettiği şeyi de değiştiremeyiz
    
    //*pvalue = 20; //value yi değiştiremeyiz
    
    int value2 = 40; 
    //pvalue = &value2; //adresi değiştiremeyiz
    value = 30; // bu şekilde değiştirebilirz
}

void void_pointers() {
	int i = 10;
	float f = 2.34;
	char ch = 'c';

	void *voidptr;

	printf("-----------------------------------------\n");
	voidptr = &i;
	printf("addres: %p\n", (int*)voidptr);
	printf("value: %d\n", *(int*)voidptr);

	printf("-----------------------------------------\n");
	voidptr = &f;
	printf("addres: %p\n", (float*)voidptr);
	printf("value: %f\n", *(float*)voidptr);

	printf("-----------------------------------------\n");
	voidptr = &ch;
	printf("addres: %p\n", (char*)voidptr);
	printf("value: %c\n", *(char*)voidptr);
}

void pointer_arrays() {
	int values[5] = {10, 20, 30, 40, 50};
	int *valuesPtr;

	printf("values: %p\n", values); //ilk elemanın adresini yazar
    //dikkat edersen 4 byte 4 byte artıyor yani her bir veri 4 byte yer tutuyor(itn degerleri)
    printf("&values[0]: %p\n", &values[0]);
    printf("&values[1]: %p\n", &values[1]);
    printf("&values[2]: %p\n", &values[2]);
    printf("&values[3]: %p\n", &values[3]);
    printf("&values[4]: %p\n", &values[4]);
    
    printf("-----------------------------------\n");
    
    valuesPtr = values; //direkt ilk elemanın adresini atare
    //valuesPtr = &values[0]; // şeklinde de tanımlayabilirdik
    
    printf("valuesPtr: %p\n", valuesPtr);
    printf("valuesPtr+1: %p\n", valuesPtr+1);
    printf("valuesPtr+2: %p\n", valuesPtr+2);
    printf("valuesPtr+3: %p\n", valuesPtr+3);
    printf("valuesPtr+4: %p\n", valuesPtr+4);

    printf("-----------------------------------\n");
    printf("valuesPtr: %d\n", *(valuesPtr));
    printf("valuesPtr+1: %d\n", *(valuesPtr+1));
    printf("valuesPtr+2: %d\n", *(valuesPtr+2));
    printf("valuesPtr+3: %d\n", *(valuesPtr+3));
    printf("valuesPtr+4: %d\n", *(valuesPtr+4));
}

void swap_pass_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    
    printf("in swap a: %d b: %d\n", a, b);
    }
void swap_pass_by_value_main() {
    int a = 100;
    int b = 200;
    
    printf("Before swap a: %d, b: %d\n", a, b);
    swap_pass_by_value(a, b);
    printf("After swap a: %d, b: %d\n", a, b);
    }
    
void swap_pass_by_reference(int *a, int *b) {
    printf("in swap a: %p b: %p\n", a, b);
    printf("in swap a: %d b: %d\n", *a, *b);
    
    int temp = *a;
    *a = *b;
    *b = temp;
    
    printf("in swap a: %p b: %p\n", a, b);
    printf("in swap a: %d b: %d\n", *a, *b);
    }
void swap_pass_by_reference_main() {
    int a = 100;
    int b = 200;
    
    printf("Before swap a: %d, b: %d\n", a, b);
    swap_pass_by_reference(&a, &b);
    printf("After swap a: %d, b: %d\n", a, b);
    }

int* return_pointer_ex(int a, int b) {
    int *result = NULL;

	int c = (a + b);

	result = &c;

	return result;
}
int main()
{   printf("1---------------------------------------------------\n");
    first_example();
    printf("1---------------------------------------------------\n");
	const_pointers1();    
    printf("3---------------------------------------------------\n");
    const_pointers2();
    printf("4---------------------------------------------------\n");  
    const_pointers3();
    printf("5---------------------------------------------------\n"); 
	void_pointers();
    printf("6---------------------------------------------------\n");
	pointer_arrays();
    printf("7---------------------------------------------------\n");
    swap_pass_by_value_main();
    printf("8---------------------------------------------------\n");
    swap_pass_by_reference_main();
    printf("9---------------------------------------------------\n");
	int *result = NULL;
    int a= 5;
    int b= 3;
	result = return_pointer_ex(a, b);

	printf("addres: %p\n", result);
	printf("value: %d\n", *result);
	return 0;
}
