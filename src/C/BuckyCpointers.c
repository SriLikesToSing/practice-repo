#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
//pointers
int main()
{

    int tuna = 19;


    //%p stands for pointer
    printf("Address \t Name \t value \t \n");
    //&tuna and ptuna is the same thing
    printf("%p \t tuna \t %d \n ", &tuna, tuna);

    //
    int * pTuna = &tuna;

    printf("%p \t %s \t %d \n", pTuna, "tuna", tuna);



    return 0;
}
