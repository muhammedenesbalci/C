#include <stdio.h>
#include <stdbool.h>

void basic_data_types(){
    int a = 5;
    float b = 3.14;
    double c = 3.144444444444444444444444444444;
    _Bool d = 1;
    
    //#include <stdbool.h> we can use bool data type
    bool myBoolean = true;
    }
    
void enum_ex(){
    enum gender {male, female};
    
    enum gender myGender = male;
    printf("myGender: %d\n", myGender);
    
    enum gender anotherGender = female;
    printf("anotherGender: %d\n", anotherGender);
    
    bool isEqual = (myGender == anotherGender);

    printf("Result: %d\n", isEqual);
    
}

void char_ex() {
    char myChar = 'E';
    printf("%c", myChar);

    char escape = '\n';
    printf("%c", escape);
    
    //Sadece ilk karakteri yazdırır
    char a = 'aaaaaa';
    printf("%c", a);
    printf("%c", escape);

    //Saçma bir şey yazdırır 5 gibi
    char bullshit = "bullshit";
    printf("%c", bullshit);
    printf("%c", escape);
}

void data_specifiers() {
    int a = 5;
    float b = 3.14;
    double c = 3.14444444;
    char myChar = 'c';
    _Bool d = 1;
    bool myBoolean = false;

    // önüne yazdığımız sayı kaç karkter yer kaplayacağı anlamın geliyor 5 karakterlik yer kaplayacak mesela
    printf("integer %5i\n", a);
    printf("float %2f\n", b);
    printf("double %5e\n", c);
    printf("char %c\n", myChar);
    printf("_Bool %i\n", d);
    printf("bool %i\n", myBoolean);

    float x = 3.999999999999;
    printf("my float: %f", x);
    
    //Noktadan sonra 3 basamak al demek
    printf("my float: %.3f", x);
    
}

void area_perimeter_rect(double w, double h) {
    //Bu kısımda parametre eklemeyi yapıcaz main fonksiyona
    double perimeter, area;

    perimeter = 2.0 * (w + h);
    area = w * h;

    printf("Perimeter is : %f\n", perimeter);
    printf("Area is: %f\n", area);
   
}

int main(int argc, char *argv[])
{    
    //basic_data_types();
    //enum_ex();
    //char_ex();

    //data_specifiers();

    /*
    double w = atoi(argv[1]);
    double h = atoi(argv[2]);
    area_perimeter_rect(w, h);
  */
    
    int numberOfArgument = argc;
    char *arg1 = argv[0];
    char *arg2 = argv[1];
    char *arg3 = argv[2];

    printf("Number of argument is argc: %d\n", numberOfArgument);
    printf("1st argument is name of program: %s\n", arg1);
    printf("2nd argument is: %s\n", arg2);
    printf("3rd argument is: %s\n", arg3);
    
    
	return 0;
}
