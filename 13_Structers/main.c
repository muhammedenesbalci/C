#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct employee {
char name[30];
char date[15];
float salary;
};

void basic_example() {
    /*declare and initialization of structure variable*/
	struct employee emp={"Mike","7/16/15",76909.00f};

	printf("\n Name: %s"	,emp.name);
	printf("\n Hire Date: %s"		,emp.date);
	printf("\n Salary: %.2f\n",emp.salary);

	printf("\nEnter employee information: \n");

	printf("Name: ");
	scanf("%s", emp.name);

	printf("\nHire Date: ");
	scanf("%s", emp.date);

	printf("\nSalary: ");
	scanf("%f", &emp.salary);

	printf("\n Name: %s"	,emp.name);
	printf("\n Hire Date: %s"		,emp.date);
	printf("\n Salary: %.2f\n",emp.salary);
    }


void struct_basics() {
    
    struct date {
        int month;
        int day;
        int year;
    };
    
    struct date day1;
    day1.month = 9;
    day1.day = 12;
    day1.year = 2012;
    
    printf("----------------------------------\n");
    printf("month: %d\n", day1.month);
    printf("day: %d\n", day1.day);
    printf("year: %d\n", day1.year);
    
    struct date day2={4, 2, 1999};

    printf("----------------------------------\n");
    printf("month: %d\n", day2.month);
    printf("day: %d\n", day2.day);
    printf("year: %d\n", day2.year);
    
    struct date day3={.month=4, .day=2, .year=1999};

    printf("----------------------------------\n");
    printf("month: %d\n", day3.month);
    printf("day: %d\n", day3.day);
    printf("year: %d\n", day3.year);
    
    struct date day4={.month=4, .day=2};

    printf("----------------------------------\n");
    printf("month: %d\n", day4.month);
    printf("day: %d\n", day4.day);
    printf("year: %d\n", day4.year);
    }
    
void struct_arrays() {
    struct date {
        
        int month;
        int day;
        char year[5];
    };
    
    struct date myDate1[2];
    
    myDate1[0].month = 4;
    myDate1[0].day = 2;
    //myDate1[0].year = "1999"; stringleri ilk tanimladigin anda initalize etmen lazim sonrdan bu sekilde edemeyizs
    myDate1[0].year[0] = '1';
    myDate1[0].year[1] = '9';
    myDate1[0].year[2] = '9';
    myDate1[0].year[3] = '9';
    
    printf("----------------------------------\n");
    printf("month: %d\n", myDate1[0].month);
    printf("day: %d\n", myDate1[0].day);
    printf("year: %s\n", myDate1[0].year);
    printf("month: %d\n", myDate1[1].month);
    printf("day: %d\n", myDate1[1].day);
    printf("year: %s\n", myDate1[1].year);
    
    
    struct date myDate2[2] = {
        {4, 2, {'1', '9', '9', '9'}},
        {9, 12, {'2', '0', '1', '2'}}
    }; 
    
    /* struct larda bu sekilde bir tanimlama yapamiyoruz
    myDate2 = {
        {4, 2, {'1', '9', '9', '9'}},
        {9, 12, {'2', '0', '1', '2'}}
    };
    */
    
    printf("----------------------------------\n");
    printf("month: %d\n", myDate2[0].month);
    printf("day: %d\n", myDate2[0].day);
    printf("year: %s\n", myDate2[0].year);
    printf("month: %d\n", myDate2[1].month);
    printf("day: %d\n", myDate2[1].day);
    printf("year: %s\n", myDate2[1].year);
    
    
    struct date myDate3[4] = {
        [0] = {4, 2, {'1', '9', '9', '9'}},
        [1] = {9, 12, {'2', '0', '1', '2'}}
    }; 
        
    printf("----------------------------------\n");
    printf("month: %d\n", myDate3[0].month);
    printf("day: %d\n", myDate3[0].day);
    printf("year: %s\n", myDate3[0].year);
    printf("month: %d\n", myDate3[1].month);
    printf("day: %d\n", myDate3[1].day);
    printf("year: %s\n", myDate3[1].year);
    printf("month: %d\n", myDate3[2].month);
    printf("day: %d\n", myDate3[2].day);
    printf("year: %s\n", myDate3[2].year);
    
    
    struct date myDate4[4] = {
        [0].month = 4,
        [0].day = 2,
        [0].year[0] = '1',
        [0].year[1] = '9',
        [0].year[2] = '9',
        [0].year[3] = '9',
    }; 
        
    printf("----------------------------------\n");
    printf("month: %d\n", myDate4[0].month);
    printf("day: %d\n", myDate4[0].day);
    printf("year: %s\n", myDate4[0].year);
    printf("month: %d\n", myDate4[1].month);
    printf("day: %d\n", myDate4[1].day);
    printf("year: %s\n", myDate4[1].year);
    printf("month: %d\n", myDate4[2].month);
    printf("day: %d\n", myDate4[2].day);
    printf("year: %s\n", myDate4[2].year);
    
    printf("month: %d\n", myDate4[5].month);
    printf("day: %d\n", myDate4[5].day);
    printf("year: %s\n", myDate4[5].year);
    }

void struct_nested() {
    struct Address {
    char street[50];
    char city[30];
    int zipCode;
    };

    struct Person {
    char name[50];
    int age;
    struct Address address; // Address struct'ını içerir
    };

    struct Person person1 = {"John Doe", 25, {"123 Main St", "Anytown", 12345}};

    // Elemanlara erişim örnekleri
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Address:\n");
    printf("  Street: %s\n", person1.address.street);
    printf("  City: %s\n", person1.address.city);
    printf("  Zip Code: %d\n", person1.address.zipCode);
}

void struct_pointers1() {
    struct date {
        int month;
        int day;
        int year;
        char myName[30];
    };

    struct date today;
    struct date *todayPtr;
    todayPtr = &today;


    //today = {4, 2, 1999};
    today.month = 4;
    today.day = 2;
    today.year = 1999;
    today.myName[0] = 'B';
    today.myName[1] = 'A';
    today.myName[2] = 'L';
    today.myName[3] = 'C';
    today.myName[4] = 'I';
    today.myName[5] = '\0'; //bunu eklemeliyiz yoksa sacma seyler yazdirir


    printf("today.month: %d\n", today.month);
    printf("today.day: %d\n", today.day);
    printf("today.year: %d\n", today.year);
    printf("today.myName: %s\n", today.myName);

    printf("(*todayPtr).month: %d\n", (*todayPtr).month);
    printf("(*todayPtr).day: %d\n", (*todayPtr).day);
    printf("(*todayPtr).year: %d\n", (*todayPtr).year);
    printf("(*todayPtr).myName: %s\n", (*todayPtr).myName);

    printf("todayPtr->month: %d\n", todayPtr->month);
    printf("todayPtr->day: %d\n", todayPtr->day);
    printf("todayPtr->year: %d\n", todayPtr->year);
    printf("todayPtr.myName: %s\n", todayPtr->myName);

    //Fazladan 2 byte var neden anlamadim
    printf("size of today; %ld\n", sizeof(today));
    printf("size of today.month; %ld\n", sizeof( today.month));
    printf("size of today.day; %ld\n", sizeof( today.day));
    printf("size of today.year; %ld\n", sizeof( today.year));
    printf("size of today.myName; %ld\n", sizeof( today.myName));

}

void struct_pointers2 () {

    struct intPointers {
        int *ptr1;
        int *ptr2;
    };

    struct intPointers intPtr;
    int i1 = 100;
    int i2;

    intPtr.ptr1 = &i1;
    intPtr.ptr2 = &i2;

    *(intPtr.ptr2) = -92;

    printf("intPtr.ptr1: %p\n", intPtr.ptr1);
    printf("intPtr.ptr2: %p\n", intPtr.ptr2);

    printf("*(intPtr.ptr1): %d\n", *(intPtr.ptr1));
    printf("*(intPtr.ptr2): %d\n", *(intPtr.ptr2));   

    printf("*size of: %ld\n", sizeof(intPtr)); 
}

void struct_pointers3 () {
    struct intPointers {
        int *ptr1;
        int *ptr2;
    };

    struct intPointers intPtr;
    int i1 = 100;
    int i2;

    intPtr.ptr1 = &i1;
    intPtr.ptr2 = &i2;

    *(intPtr.ptr2) = -92;

    printf("intPtr.ptr1: %p\n", intPtr.ptr1);
    printf("intPtr.ptr2: %p\n", intPtr.ptr2);

    printf("*(intPtr.ptr1): %d\n", *(intPtr.ptr1));
    printf("*(intPtr.ptr2): %d\n", *(intPtr.ptr2));   

    //ponterleri structa tutuyoruz adresleri yani degerleri degil
    printf("*size of: %ld\n", sizeof(intPtr)); 
}

void struct_strings(){
    struct names_array {
        char first[20];
        char second[20];
    };

    struct names_array my_string_array = {"enes", "balcı"};
    printf("size of my_string_array.first %ld\n", sizeof(my_string_array.first));
    printf("size of my_string_array.second %ld\n", sizeof(my_string_array.second));
    printf("size of my_string_array %ld\n", sizeof(my_string_array));

    
    printf("---------------------------------------\n");

    struct names_pointer{
        char *first;
        char *second;
    };

    struct names_pointer my_string_pointer;
    char first_n[] = "enes";
    char second_n[] = "balcı";

    my_string_pointer.first = (char*)malloc(strlen(first_n) + 1);
    my_string_pointer.second = (char*)malloc(strlen(second_n) + 1);

    strcpy(my_string_pointer.first, first_n);
    strcpy(my_string_pointer.second, second_n);

    printf("size of my_string_pointer.first %ld\n", sizeof(my_string_pointer.first));
    printf("size of my_string_pointer.second %ld\n", sizeof(my_string_pointer.second));
    printf("size of my_string_pointer %ld\n", sizeof(my_string_pointer));

}


struct Family {
    char name[20];
    char father[20];
    char mother[20];
};

bool siblings_1(struct Family person1, struct Family person2) {

    if (strcmp(person1.father, person2.father) == 0) {
        return true;
    } else {
        return false;
    }
}

bool siblings_2(struct Family *person1, struct Family *person2) {

    if (strcmp(person1->father, person2->father) == 0) {
        return true;
    } else {
        return false;
    }
    
}
void struct_functions() {

    struct Family enes = {"enes", "isa"};
    struct Family efe = {"efe", "isa"};

    bool result_1 = siblings_1(enes, efe);

    printf("result: %d\n", result_1);
    printf("--------------------------\n");

    struct Family *enes_p;
    struct Family *efe_p;

    enes_p = &enes;
    efe_p = &efe;
    bool result_2 = siblings_2(enes_p, efe_p);

    printf("result: %d\n", result_2);
    printf("--------------------------\n");

}

int main(){  

    printf("Basic Example ##############################\n");  
    basic_example();

    printf("Struct Basic ##############################\n");
    struct_basics();

    printf("Struct Array ##############################\n");
    struct_arrays();

    printf("Struct Nested ##############################\n");
    struct_nested();

    printf("Struct Pointers 1 ##############################\n");
    struct_pointers1();

    printf("Struct Pointers 2 ##############################\n");
    struct_pointers2();

    printf("Struct Pointers 3 ##############################\n");
    struct_pointers3();

    printf("Struct Strings ##############################\n");
    struct_strings();

    printf("Struct Functions ##############################\n");
    struct_functions();

	return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

struct item
{
    char *itemName;
    int qty;
    float price;
    float amount;
};

void readItem(struct item *i);
void printItem(struct item *i);

int main()
{
    struct item itm = { NULL, 0, 0.0, 0.0 };
    struct item *pItem = NULL;

    pItem = &itm;

    pItem->itemName = (char *) malloc(30 * sizeof(char));

    if(pItem == NULL)
        exit(-1);

    // read item
    readItem(pItem);

    // print item
    printItem(pItem);

    free(pItem->itemName);

    return 0;
}

void readItem(struct item *i)
{
    printf("Enter product name: ");
    scanf("%s", i->itemName);

    printf("\nEnter price: ");
    scanf("%f", &i->price);

    printf("\nEnter quantity: ");
    scanf("%d", &i->qty);

    i->amount = (float)i->qty * i->price;
}

void printItem(struct item *i)
{

    printf("\nName: %s",i->itemName);
    printf("\nPrice: %.2f",i->price);
    printf("\nQuantity: %d",i->qty);
    printf("\nTotal Amount: %.2f",i->amount);
}

*/