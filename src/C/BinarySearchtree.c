#include <stdio.h>
#include <stdlib.h>

int root;
struct node{
    int data;
    struct node *left;
    struct node *right;

};


struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;

}

struct node* Insert(struct node* car, int data){
    if(car == NULL){
        car = newNode(data);
    }else if(data <= car->data){
        car->left = Insert(car->left, data);
    }else{
        car->right = Insert(car->right, data);
    }return car;
}


void Inorder(struct node *root)
{
    if(root == NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);

}
int main()
{

    struct node *root;
    root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 25);
    root = Insert(root, 155);
    root = Insert(root, 0);
    root = Insert(root, 24);
    root = Insert(root, 25);
    printf("%d\n", *root);

    Inorder(root);




    return 0;
}
