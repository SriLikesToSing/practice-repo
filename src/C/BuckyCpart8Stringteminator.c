#include <stdio.h>
#include <stdlib.h>

int root;
struct node{
    int data;
    struct node *left;
    struct node *right;

};
int main()
{
    struct node Yay;
    Yay.data = 4;
    printf("%d", Yay);

}
