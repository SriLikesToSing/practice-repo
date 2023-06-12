#include <stdio.h>
#include <stdlib.h>

struct test{
    int age;
    int car;

};
int main()
{
    struct test em;

    struct test *pointer = &em;

    pointer->car = 3;
    printf("%d", em.car);


    return 0;

}
