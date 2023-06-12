#include <stdio.h>
#include <stdlib.h>

int main()
{
    int answer1;
    int a = 5, b = 10, answer =  0;
    // ++a adds one to a before before it changes the equation
    answer = ++a * b;
    printf("Answer: %d \n", answer);


    a = 5, b = 10, answer =  0;

    answer = a++ * b;
    //Change "a" now
    printf("Answer: %d \n", answer);
    printf(" %d", a);
    return 0;
}
