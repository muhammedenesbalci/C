#include <stdio.h>

void basic_operators_1() {
	int a = 33;
	int b = 15;
	int result = 0;

	result = a + b;
	printf("a=%d | b=%d\n", a, b);
	printf("a + b = %d\n", result);

	result = a % b;
	printf("a=%d | b=%d\n", a, b);
	printf("a percent b = %d\n", result);

	a++;
	printf("a++ : %d\n", a);

	++a;
	printf("++a : %d\n", a);

	int c;

	a = 0;
	c = ++a;
	printf("++a|c=%d | a=%d\n", c, a);
	
	a = 0;
	c = a++;
	printf("a++|c=%d | a=%d\n", c, a);
}

void basic_operators_2() {
	int a = 12;
	int b = 20;
	_Bool result;

	result = a && b;
	printf("result: %d\n", result);

	result = a || b;
	printf("result: %d\n", result);
	
	result = a == b;
	printf("result: %d\n", result);
}

void bitwise_operators() {
    printf("----------------------------------------------\n");
	//compares bit one by one and writes as a decimal
	unsigned int a = 60; //0011 1100
	unsigned int b = 13; //0000 1101
	int result = 0;

	// Compare
	result = a & b; //0000 1100 = 12
	printf("a & b: %d\n", result);

	result = a | b; //0011 1101 = 61
	printf("a | b: %d\n", result);

	result = a ^ b; //0011 0001 = 49
	printf("a ^ b: %d\n", result);
    
    result = ~a; 
	printf("~a: %d\n", ~a); //inverse of a

	//Shifting
	unsigned int x = 60; //0000 0000 0000 0000 0000 0000 0011 1100 32 bits 4 bytes
	unsigned int y = 13; //0000 0000 0000 0000 0000 0000 0011 1101

	//2 bits to left shift
	result = x << 2; //0000 0000 0000 0000 0000 0000 1111 0000 =240
	printf("x << 2: %d\n", result);

	//2 bits to right shift
	result = y >> 2; //0000 0000 0000 0000 0000 0000 0000 0011 = 3
	printf("y >> 2: %d\n", result);
}

void size_of_operators() {
	printf("sizes of primitive data types----------------------------------\n");

	printf("char byte: %u\n", sizeof(char));

	printf("short byte: %u\n", sizeof(short));

	printf("long byte: %lu\n", sizeof(long));
	printf("long long byte: %llu\n", sizeof(long long));
    printf("long long byte: %llu\n", sizeof(long long int));

    printf("unsigned int byte: %u\n", sizeof(unsigned int));
	printf("short int byte: %u\n", sizeof(short int));
	printf("int byte: %u\n", sizeof(int));
	printf("long int byte: %lu\n", sizeof(long int));

	printf("float byte: %u\n", sizeof(float));

	printf("double byte: %u\n", sizeof(double));
	printf("long double byte: %lu\n", sizeof(long double));
}

void cast_operator(){
	printf("cast operator --------------------------------------------------------\n");

    float myFloat = 3.1234;
    int my_int = (int) myFloat;

    printf("my_int: %d\n", my_int);
    printf("myFloat: %f\n", myFloat);

    double myDouble = (double) my_int;
    printf("myDouble: %e\n", myDouble);
    }

int main()
{    
	basic_operators_1();
	basic_operators_2();

	bitwise_operators();
	size_of_operators();
	cast_operator();
	return 0;
}
