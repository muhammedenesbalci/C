#include <stdio.h>


void basic_union() {
    union un {
        int member1;
        char member2;
        float member3;
    };

    union un var1;

	var1.member1 = 15;

	printf("The value stored in member1 = %i\n", var1.member1);
    printf("The value stored in member2 = %c\n", var1.member2);
    printf("The value stored in member3 = %f\n", var1.member3);
}

void size_of_unions() {
    union test1 {
        int x;
        int y;
    } Test1;
    
    union test2 {
        int x;
        char y;
    } Test2;
    
    union test3 {
        int arr[10];
        char y;
    } Test3;

    // finding size using sizeof() operator
    int size1 = sizeof(Test1);
    int size2 = sizeof(Test2);
    int size3 = sizeof(Test3);
 
    printf("Sizeof test1: %d\n", size1);
    printf("Sizeof test2: %d\n", size2);
    printf("Sizeof test3: %d\n", size3);
}

void addres_of_unions() {
    union MyUnion {
        int intValue;
        float floatValue;
    };

    union MyUnion u;
    printf("Address of intValue: %p\n", &u.intValue);
    printf("Address of floatValue: %p\n", &u.floatValue);
}

void same_data_type_in_union() {
    union test {
        int x, y;
    };

    // A union variable t
    union test t;
 
    t.x = 2; // t.y also gets value 2
    printf("After making x = 2:\n x = %d, y = %d\n", t.x, t.y);
 
    t.y = 10; // t.x is also updated to 10
    printf("After making y = 10:\n x = %d, y = %d\n", t.x, t.y);
}

void compare_struct_union_size() {
    struct MyStruct {
        int intValue;
        float floatValue;
    };

    union MyUnion {
        int intValue;
        float floatValue;
    };

    struct MyStruct s;
    union MyUnion u;

    printf("Size of struct: %zu\n", sizeof(s));
    printf("Size of union: %zu\n", sizeof(u));
}

void compare_struct_union_address() {
    struct MyStruct {
        int intValue;
        float floatValue;
        char charValue;
    };

    printf("* Struct\n");

    struct MyStruct s;
    printf("Address of intValue: %p\n", (void*)&s.intValue);
    printf("Address of floatValue: %p\n", (void*)&s.floatValue);
    printf("Address of charValue: %p\n", (void*)&s.charValue);

    union MyUnion {
        int intValue;
        float floatValue;
        char charValue;
    };

    printf("* Union\n");

    union MyUnion u;
    printf("Address of intValue: %p\n", (void*)&u.intValue);
    printf("Address of floatValue: %p\n", (void*)&u.floatValue);
    printf("Address of charValue: %p\n", (void*)&u.charValue);

}
int main()
{
    printf("\nBasic union #########################\n");
    basic_union();

    printf("\nsize_of_unions #########################\n");
    size_of_unions();

    printf("\naddres_of_unions #########################\n");
    addres_of_unions();

    printf("\nsame_data_type_in_union #########################\n");
    same_data_type_in_union();

    printf("\ncompare_struct_union_size #########################\n");
    compare_struct_union_size();

    printf("\ncompare_struct_union_address #########################\n");
    compare_struct_union_address();
	return 0;
}
