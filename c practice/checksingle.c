#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *createnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
int iscircular(struct node *head){
    if(head==NULL){
        return 1;
    }
    struct node *temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    return(temp==head);
}

int main()
{
    struct node *head1=createnode(10);
    head1->next=createnode(20);
    head1->next->next=createnode(30);
    head1->next->next->next=head1;

    struct node *head2=createnode(1);
    head2->next=createnode(2);
    head2->next->next=createnode(3);

    if(iscircular(head1)){
        printf("List1 is circular\n");
    }
    else{
        printf("List1 is not circular\n");
    }
    if(iscircular(head2)){
        printf("List2 is circular\n");
    }
    else{
        printf("List2 is not circular\n");
    }
}