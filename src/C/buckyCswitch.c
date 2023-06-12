#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{

    char grade = 'C';

    switch(grade){
        case 'A' :  printf("MAMA MIAAA \n");
                    break;

        case 'B' : printf("Your so bad lmao xD \n");
                   break;

        case 'C' : printf("lmao go kill yourself xD \n");
                   break;

        case 'D' : printf("GO SUCK ON MY D xD \n");
        //If a, b, c or D is not valid then run this by default
        default  : printf("That doesent even make sense loser!");

    }




    return 0;

}
