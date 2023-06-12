#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, howMany;
    int total;
    float average = 0.0
    int * pointArray;


    printf("How many numbers do you want ot average?\n");

    pointerArray = (int *) malloc(howMany * sizeof(int));

    printf("Enter them hoss! \n");

    for(i=0; i<howMany; i++){
        scanf(" %d", &pointArray[i]);
        total += pointArray[i];
    }

average = (float)total / (float)howMany;



    return 0;
}
