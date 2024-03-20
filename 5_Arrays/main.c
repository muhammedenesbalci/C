#include <stdio.h>

void create_and_use_arrays() {
	int grades[10];
	int count = 10;
	long sum = 0;
	float average = 0.0f;

	for (int i = 0; i < count; i++) {
		printf("%d\n", grades[i]);		//garbage elements
	}

	printf("Enter numbers --- \n");

	for (int i = 0; i < count; i++) {
		printf("%2u>", i + 1);
		scanf("%d", &grades[i]);
		sum+=grades[i];
	}

	average = sum / count;
	printf("average: %f", average);	
}

#define MONTHS 12
void array_initilization() {
	int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int index;

	for (index = 0; index < MONTHS; ++index) {
		printf("Month %d %2d days.\n", index + 1, days[index]);
	}
}

void two_dim_array() {
    int numbers[3][4] = {{1,2,3,4},
                         {1,2,3,4},
                         {1,2,3,4}};

    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("[%d][%d]", i, j);
        }
    }
}

#include <stdbool.h>

void generate_prime_number() {
	int p = 0;
    int i = 0;

    int primes[50] = {0};

	//bir tanesini tanımladığımız icin 0 değerlerini atıyor
	//index dışındaki değerleri saçma sayılar atıyor
	for (int i = 0; i < 51; i++) {
		printf("%d\n", primes[i]);	
	}
	printf("--------------------\n");
    int primeIndex = 2;

    bool isPrime = false;

    // hardcode prime numbers
    primes[0] = 2;
    primes[1] = 3;

    for(p = 5; p <= 100; p = p + 2)
    {
        isPrime = true;

        for (i = 1; isPrime && p / primes[i] >= primes[i]; ++i)
            if (p % primes[i] == 0)
                isPrime = false;

        if (isPrime == true)
        {
            primes[primeIndex] = p;
            ++primeIndex;
        }
    }

    for ( i = 0;  i < primeIndex;  ++i )
         printf ("%i  ", primes[i]);

    printf("\n");
}

#define MONTHS 12
#define YEARS 5
void weather_ex() {
	// initialize rainfall data for 2011-2015
    float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

    int year = 0, month = 0;
    float subtot = 0.0, total = 0.0;

    printf("YEAR\t\tRAINFALL  (inches)\n");

    for (year = 0, total = 0; year < YEARS; year++)
    {
        for(month = 0, subtot = 0; month < MONTHS; month++)
        {
            subtot += rain[year][month];
        }
        printf("%5d \t%15.1f\n", 2010 + year, subtot);
        total += subtot;
    }

    printf("\nThe yearly average is %.1f inches.\n\n",total/YEARS);

    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0, subtot = 0; year < YEARS; year++)
            subtot += rain[year][month];

        printf("%4.1f ", subtot/YEARS);
    }

    printf("\n");
}

int main()
{    
    //create_and_use_arrays();
	//array_initilization();
	//enerate_prime_number();
	//weather_ex();

	//size of an array int 4 byte yer tutar mantıken 40 byte yer kaplamasi lazım
    int my_array[10] = {0, 1, 2, 3, 4, 5, 6, 7 ,8, 9};
	printf("array size: %ld\n", sizeof(my_array));

	return 0;
}
