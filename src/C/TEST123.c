#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 25;
    int i;

    int *A = (int*)malloc(n*sizeof(int));
    for ( i =0;i<n;i++){;
        A[i] = i+1;
    }
    int *B = (int*)realloc(A, 2*n*(sizeof(int)));
    for( i=0; i<n;i++){
        printf("%d", B[i]);
    }
    //int * d = (int*)calloc(3, sizeof(int));


    return 0;
}








