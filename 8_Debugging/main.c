#include <stdio.h>

//Complier errors bazilarini build yaparekn verilen warninglerdir

//stack bir data structure terimdir
//LIFO diye bilinir last in first out 
//https://cs.gmu.edu/~kauffman/cs222/stack-demo.html  function call examples
//Debuger start debug dont forget to add brakepoints

//1------------------------------------------------------------------------------------
int mogrify(int a, int b){
   int tmp = a*4 - b / 3;                  // First line of mogrify (mogrify)
   return tmp;                             // (mogrify_return)
 }
 double truly_half(int x){
   double tmp = x / 2.0;                   // First line of turly_half (truly_half)
   return tmp;                             // (truly_half_return)
 }
 
 void first_example() {
   int a = 7, y = 17;                      // First line of main (main)
   int mog = mogrify(a,y);                 // Call to mogrify (mogrify_call)
   printf("Done with mogrify\n");          // (first_print)
 
   double x = truly_half(y);               // Call to truly_half (truly_half_call)
   printf("Done with truly_half\n");       // (second_print)
 
   a = mogrify(x,mog);                     // (mogrify2)
 
   printf("Results: %d %lf\n",mog,x);      // (last_print)
   //return 0;                               // (main_return)
}


//2------------------------------------------------------------------------------------
void print(int a1, int a2, int a3, double average) {
    printf("Mean %d %d %d is %f", a1, a2, a3, average);
    }
    

double average(int a1, int a2, int a3) {
    
    int sum = 0;
    double average = 0.0;
    
    sum = a1 + a2 + a3;
    
    average = sum / 3.0;
    
    return average;
    }
    
void second_example() {
    int a1, a2, a3;
    printf("Enter: ");
    
    scanf("%d %d %d", &a1, &a2, &a3);
    
    print(a1, a2, a3, average(a1, a2, a3));
    
    }
    
 int main(){
    //first_example();
    
    second_example();
}