#include <stdio.h>
#include <stdlib.h>

void convertToDollars(float euro);

int main()
{
    float i;


    float euroPrice1 = 1.00;
    float euroPrice2 = 5.50;
    for(i=0.00; i<5.00; i++){
        convertToDollars(i);
        printf("%f", i);
    }
    convertToDollars(euroPrice1);
    convertToDollars(2.456763343);





    return 0;
}




void convertToDollars(float euro)
{
    float usd = euro * 1.37;
    printf("%.2f Euros - %.2f USD\n", euro, usd);










    return;
}
