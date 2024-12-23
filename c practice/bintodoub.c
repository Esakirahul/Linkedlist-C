#include<stdio.h>
#include<stdlib.h>
//For BinaryTree
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct Node *createTreenode(int data){
    struct Node *newnode=malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
struct node *createnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}
struct Node *buildTree(){
    int data;
    scanf("%d",&data);
    if(data==-1) return NULL;
    struct Node *root=createTreenode(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void binaryTreeToDLL(struct Node *root,struct node **head,struct node **tail){
    if(root=NULL){
        return;
    }
    binaryTreeToDLL(root->left,head,tail);
    struct node *newnode=createnode(root->data);
    if(*tail==NULL){
        *head=newnode;
    }
    else{
        (*tail)->next=newnode;
        newnode->prev=*tail;
    }
    *tail=newnode;
    binaryTreeToDLL(root->right,head,tail);

}
void printTree(struct Node *root){
    if(root==NULL) return;
    printf("%d",root->data);
    printTree(root->left);
    printTree(root->right);
}
void printDLL(struct node *head){
    while(head!=NULL){
        printf("%d",head->data);
        head=head->next;
    }
}
int main(){
    struct Node *root=buildTree();
    printTree(root);
    struct node *head=NULL;
    struct node *tail=NULL;

    binaryTreeToDLL(root,&head,&tail);
    printDLL(head);

    return 0;

}
