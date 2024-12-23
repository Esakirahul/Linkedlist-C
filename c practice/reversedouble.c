#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *createnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}
 void reverse(struct node **head) {
        struct node *temp=NULL;
        struct node *current=*head;
        while(current!=NULL){
            temp=current->prev;
            current->prev=current->next;
            current->next=temp;
            current=current->prev;
        }
        if(temp!=NULL){
            *head=temp->prev;
        }
    }
int main(){
    struct node *head=NULL;
    struct node *old=NULL;
    struct node *n=NULL;
    int data,num;
    scanf("%d",&num);
    scanf("%d",&data);
    head=createnode(data);
    old=head;

    for(int i=2;i<=num;i++){
        scanf("%d",&data);
        n=createnode(data);
        n->prev=old;
        old->next=n;
        old=n;
    }
    struct node *temp=head;
    //printf("Originla list");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
   
    reverse(&head);
    //printf("Reverse list");
    temp=head;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}