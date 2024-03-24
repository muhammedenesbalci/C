#include <stdio.h>
#include <string.h>

void basic_example() {
    typedef long long ll;
    ll var = 20;
    printf("%ld", var);
}

void struct_example() {
    // using typedef to define an alias for structure
    typedef struct students_structure {
        char name[50];
        char branch[50];
        int ID_no;
    } student;
    
    //tanımlarken tekrar tekrar structure yazmak zorunda değliz
    student st;
    strcpy(st.name, "Kamlesh Joshi");
    strcpy(st.branch, "Computer Science And Engineering");
    st.ID_no = 108;
 
    printf("Name: %s\n", st.name);
    printf("Branch: %s\n", st.branch);
    printf("ID_no: %d\n", st.ID_no);
}

void pointer_example() {
    typedef int* ptr;
    ptr var;
    *var = 20;
 
    printf("Value of var is %d", *var);
}

void array_example() {
    typedef int Arr[4];

    Arr temp = { 10, 20, 30, 40 };
    printf("typedef using an array\n");
 
    for (int i = 0; i < 4; i++) {
        printf("%d ", temp[i]);
    }
}

int main()
{   
    printf("Basic Example ############################");
    basic_example();

    printf("Structure Example ############################");
    struct_example();

    printf("Array Example ############################");
    array_example();

 
    return 0;
}