#include <stdio.h>
#include <stdlib.h>

//Binary Search Tree
int root;
struct BstNode{
  int data;
  struct BstNode* left;
  struct bstNode* right;


};


struct BstNode *GetNewNode(int data){
  struct BstNode *newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
  (*newNode).data = data;
  (*newNode).left = NULL
  (*newNode).right = NULL;
  return struct newNode;


}

BstNode *Insert(struct BstNode *root, int data){
  if(root == NULL){
    root = GetNewNode(data);
  }else if(data <= root->data){
    root->left = Insert(root->left, data);
  }else{
    root->right = Insert(root->right, data);
  }
}
  return root;
int main(){
  struct BstNode *root; // pointer to root node
  root = NULL; // setting tree as empty
  root = Insert(root, 15);
  root = Insert(root, 13);
  root = Insert(root, 20);

  return 0;

}
