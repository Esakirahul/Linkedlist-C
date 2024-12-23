#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *createnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

}
void findsumtarget(struct node *head,int target){
    struct node *ptr1,*ptr2;
    int found=0;
    for(ptr1=head;ptr1!=NULL;ptr1=ptr1->next){
        for(ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next){
            if(ptr1->data + ptr2->data == target){
                printf("%d%d",ptr1->data,ptr2->data);
                found=1;
            }
        }
    }
    if(!found){
        printf("NO pairs");
    }
}
int main(){
    int num,data,target;
    struct node *head,*old;
    struct node *n;
    scanf("%d",&num);
    scanf("%d",&data);
    head=createnode(data);
    old=head;

    for (int i = 2; i <= num; i++)
    {
        scanf("%d",&data);
        n=createnode(data);
        n->prev=old;
        old->next=n;
        old=n;

    }
    scanf("%d",&target);
    findsumtarget(head,target);
    // while(head!=NULL){
    //     printf("%d ",head->data);
    //     head=head->next;
    // }
    
}