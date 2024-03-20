#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//1-----------------------------------------------------------------
// character constants
#define MYCHAR 'a'
#define MYSTRING "myString"

void strings_basics();

//2-----------------------------------------------------------------
int stringLength(const char string[]);
void concat(char result[], const char str1[], const char str2[]);
bool equalStrings(const char s1[], const char s2[]);
bool equalStrings(const char s1[], const char s2[]);
void use_functions();

//3-----------------------------------------------------------------
void common_string_functions();
void common_string_functions2();
int main()
{
    //1-----------------------------------------------------------------	
	//strings_basics();    

    //2-----------------------------------------------------------------
    //use_functions();
    
    //3-----------------------------------------------------------------
    //common_string_functions();
    common_string_functions2();
    
	return 0;
}

//1-----------------------------------------------------------------
void strings_basics() {
	//Stringler \0 diye bir karakterle biter.
	printf("The null character\n\0 is used here");
    
    // özel karakterler yazabilmek için \ ibaresini kullan
    printf("for example \"\n");
    
    //string tamamlamak için char arrayı tanımlıyoruz tanımlayacağın karakterden 1 fazla olmalı,
    //Cünkü \0 içinde yer olmalı
    //ama burada küçük tanımlasak bile hata vermnedi yine de tuhaf çalışıyor o yüzden hep 1 büyük ver
    
    char myName[5] = {"Enes"};
    printf("%s\n", myName);
    
    for(int i = 0; i < 10; i++) {
        printf("myName[%d]: %c\n", i, myName[i]);
        }
    
    char yourName[4] = {"Efe"};
    printf("%s\n", yourName);
    
    char myNamee[] = {"Furkannn"};
    printf("%s\n", myNamee);
    //input alma & koymuyoruz
    //0 dan 9 a kadar girersen hata verir
    char inputString[9];
    
    scanf("%s", inputString);
    
    printf("your input :%s\n", inputString);
    
    //find len
    int count = 0;
    while(myName[count] != '\0') {
        count++;
        }
    printf("myName len: %d\n", count);
    
    //constants
    printf("my constant char: %c\n", MYCHAR);
    printf("myconstant string: %s\n", MYSTRING);
    
    //değiştirmeye çalışırsan complier error verir
    const char myNameConst[10] = {"Eness"}; 
    printf("%s\n", myNameConst);
}
//2-----------------------------------------------------------------
int stringLength(const char string[]){
    int count = 0;

    while (string[count] != '\0')
        ++count;

    return count;
}

void concat(char result[], const char str1[], const char str2[]){
    int i = 0, j = 0;

    for (i = 0; str1[i] != '\0'; ++i)
    {
        result[i] = str1[i];
    }

     for ( j = 0;  str2[j] != '\0';  ++j )
        result[i + j] = str2[j];

    result[i+j] = '\0';
}

bool equalStrings(const char s1[], const char s2[]){
    int i = 0;
    bool isEquals = false;

    while ( s1[i] == s2 [i]  &&
            s1[i] != '\0' &&
            s2[i] != '\0' )
        ++i;

    if ( s1[i] == '\0'  &&  s2[i] == '\0' )
       isEquals = true;
    else
       isEquals = false;

    return isEquals;
}

void use_functions() {
    const char word1[] = "jason";
    const char word2[] = "ok";
    const char word3[] = "whatever";
    char result[50];

    printf("%d    %d     %d\n", stringLength(word1), stringLength(word2), stringLength(word3));

    concat(result, word1, word2);

    printf("\n%s", result);

    printf("\n%d\n", equalStrings("Jason", "Jason"));
    printf("%d\n", equalStrings("Jasons", "Jason"));

}
//3-----------------------------------------------------------------
void common_string_functions() {
    char myString[] = "Muhammed Enes BALCI";
    
    //int de verebilirdik
    size_t sizeOfMyString = strlen(myString);
    printf("len of array: %ld\n", sizeOfMyString);
    
    int sizeOfArray = sizeof(myString);
    printf("size of array: %d\n", sizeOfArray);

    
    //copy
    char src[50], dest[50];
    
    strcpy(src, "this is source");
    strcpy(dest, "this is destination");
    
    printf("%s\n", src);
    printf("%s\n", dest);
    
    //concanate
    strncat(dest, src, sizeof(dest));
    printf("%s\n", dest);
    
    //Compaer strings
    printf("strcmp(A, A): %d\n", strcmp("A", "A"));
    printf("strcmp(A, B): %d\n", strcmp("A", "B"));
    printf("strcmp(B, A): %d\n", strcmp("B", "A"));
    printf("strcmp(C, A): %d\n", strcmp("C", "A"));
    printf("strcmp(Z, a): %d\n", strcmp("Z", "a"));
    printf("strcmp(apple, apples): %d\n", strcmp("apple", "apples"));
    printf("strcmp(apple, apple): %d\n", strcmp("apple", "apple"));
    }
    
void common_string_functions2() {
    char str[100];
    char name[25][50], temp[25];
    int l = 0, i = 0, n = 0, j = 0;

    printf("\n\nPrint individual characters of string in reverse order :\n");
    printf("----------------------------------------------------------\n");
    printf("Input the string :");
    scanf("%s", str);

    l = strlen(str);

    printf("The characters of the string in reverse are : \n");

    for (i = l; i >=0; i--)
    {
        printf("%c", str[i]);
    }

    printf("\n");
    printf("----------------------------------------------------------");

    printf("\n\nSorts the strings of an array using bubble sort :  \n");
    printf("---------------------------------------------------------\n");

    printf("Input number of strings :");
    scanf("%d", &n);

    printf("Input string %d : \n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", name[i]);
    }

    for(i=1;i<=n;i++)
        for(j=0;j<=n-i;j++)
            if(strcmp(name[j],name[j+1])>0)
            {
                strncpy(temp,name[j], sizeof(temp) - 1);
                strncpy(name[j],name[j+1], sizeof(name[j]) - 1);
                strncpy(name[j+1],temp, sizeof(name[j] + 1) - 1);
            }

    printf("The strings appear after sorting :\n");

    for (i = 0; i <= n; i++)
        printf("%s\n", name[i]);
    
    }