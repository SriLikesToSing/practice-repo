#include <stdio.h>
#include <stdlib.h>


int main()
{
    //Conversion characters are placeholders
    //This is basically string formatting
    //$s is the placeholder and is for string only
    printf("%s is the best $s ever\n", "E.T", "Alien");
    //This is for digit
    printf("%d paneer pieces are left\n", 1);
    // number with decimal place is float and you need to use %f
    //If you put a number in between % and f you can select how many numbers you want
    printf("%.2f is the test score i got >:(\n", 21.91111);

    int number;
    number = 5;
    printf("%d", number);




    return 0;




}
