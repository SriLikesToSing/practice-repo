#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int main()
{

    int x;
    int diceRoll;

    for(x=0; x<20; x++){
        diceRoll = ( rand()%6 + 1);

        printf("%d \n", diceRoll);

    }







    return 0;
}
