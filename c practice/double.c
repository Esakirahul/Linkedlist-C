#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}


int main(){
    struct node *head=NULL,*old=NULL,*n=NULL;
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
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    


}