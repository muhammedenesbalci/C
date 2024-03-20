#include <stdio.h>
#include <stdlib.h> //Declareing constant
#include <time.h> // for random ints

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

void if_elseif_else_ex() {
    // declare variables
   int hours = 0;
   double grossPay = 0.0;
   double taxes = 0.0;
   double netPay = 0.0;

   printf("Please enter the number of hours worked this week: ");

   // get the input
   scanf("%d", &hours);

   // calculate the gross pay
   if (hours <= 40)
       grossPay = hours * PAYRATE;
   else
   {
     grossPay = 40 * PAYRATE;
     double overTimePay = (hours - 40) * (PAYRATE * 1.5);
     grossPay += overTimePay;
   }

   // calculate taxes
   if (grossPay <= 300)
   {
       taxes = grossPay * TAXRATE_300;
   }
   else if(grossPay > 300 && grossPay <= 450)
   {
       taxes = 300 * TAXRATE_300;
       taxes += (grossPay - 300) * TAXRATE_150;    
   }
   else if (grossPay > 450)
   {
       taxes = 300 * TAXRATE_300;
       taxes += 150 * TAXRATE_150;
       taxes += (grossPay - 450) * TAXRATE_REST;
   }

   // calculate the netpay
   netPay = grossPay - taxes;

   // display output
   printf("Your gross pay this week is: %.2f\n", grossPay);
   printf("Your taxes this week is: %.2f\n", taxes);
   printf("Your net pay this week is: %.2f\n", netPay);
}

void ternary_statement_ex() {
    int x;
    int y = 10;
    // if y is greater than 7 than  x = 1 (true), if not then x = 0 (false)
    x = y > 7 ? 1 : 0;
    printf("x: %d\n", x);

    y = 5;
    x = y > 7 ? 1 : 0;
    printf("x: %d\n", x);

}

void switch_case_ex(){
    enum Weekdays {monday, tuesday, wednesday};
    enum Weekdays today = monday;

    switch(today) {
        case wednesday:
            printf("wednesday\n");
            break;
        case tuesday:
            printf("tuesday\n");
            break;
        case monday:
            printf("monday\n");
            break;
        default:
            printf("empty");
    }
}

void for_ex() {
    unsigned long long sum = 0LL;
    unsigned int count = 0;

    printf("Enter the number of integers that you want to sum\n");
    scanf("%u", &count);

    for(unsigned int i = 1; i<=count;i++) {
        sum+=i;
    }

    printf("sum of numbers: %llu\n", sum);
}

void infinite_for_ex() {
    int i = 0;

    printf('for loop-------------------\n');
    for(;;) {
        i+=1;

        printf("i: %d\n", i);

        if (i == 5) {
            break;
        }
    }
    i = 0;
    while(true) {
        printf('while loop---------------\n');
        printf('%d', 1)
        if(i == 5) {
            break;
        } else {
            continue;
        }
    }
}

void while_loop_ex() {

    int i = 0;

    while(i < 5) {
        i++;
        printf("%d", i);
    }
}

void do_while_ex() {
    int number = 0;
    do{
        number++;
        printf("number: %d", number);
    }
    while(number < 5);

    printf("--------------------------")

    number = 0;
    do{
        number++;
        printf("number: %d", number);
    }
    while(number < 0);    
}

void guess_the_number_ex() {
    int randomNumber = 0;
    int guess = 0;
    int numberOfGuesses = 0;
    time_t t = 0;

    // Initialization of random number generator
    srand((unsigned) time(&t));

    // get the random number
    randomNumber = rand() % 21;

    printf("\nThis is a guessing game.");
    printf("\nI have chosen a number between 0 and 20, which you must guess. \n");

    for(numberOfGuesses = 5; numberOfGuesses > 0; --numberOfGuesses)
    {
        printf("\nYou have %d tr%s left.", numberOfGuesses, numberOfGuesses == 1 ? "y" : "ies");
        printf("\nEnter a guess: ");
        scanf("%d", &guess);

        if(guess == randomNumber)
        {
            printf("\nCongratulations.  You guessed it!\n");
        }
        else if(guess < 0 || guess > 20)  // checking for an invalid guess
            printf("I said the number is between 0 and 20.\n");
        else if(randomNumber > guess)
            printf("Sorry, %d is wrong.  My number is greater than that.\n", guess);
        else if(randomNumber < guess)
            printf("Sorry, %d is wrong.  My number is less than that.\n", guess);
    }
    printf("\nYou have had five tries and failed. The number was %d\n",randomNumber);
    }

int main()
{    
    //if_elseif_else_ex();
    //ternary_statement_ex();
	//switch_case_ex();
    //for_ex();
    //infinite_for_ex();
    //guess_the_number_ex();
    //while_loop_ex();
    do_while_ex();
    return 0;
}
