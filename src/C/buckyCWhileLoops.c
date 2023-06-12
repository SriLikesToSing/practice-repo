#include <stdio.h>
#include <stdlib.h>

int main()
{

    int day = 1;

    float penny = .01;

    while(day <= 31){
        penny *= 2;
        day++;
        printf("%f\n", penny);
    }






    return 0;
}
