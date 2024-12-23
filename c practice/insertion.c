#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insertAtBegin(struct node **head,int data){
    struct node *newnode=createnode(data);
    newnode->next=*head;
    *head=newnode;
}
void insertAtEnd(struct node **head,int data){
    struct node *newnode=createnode(data);
    struct node *temp=*head;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    
}
void insertAtMiddle(struct node **head,int data,int position){
    struct node *newnode=createnode(data);
    if(position==1){
        insertAtBegin(head,data);
    }
    struct node *temp=*head;
    for(int i=1;i<position-1;i++){
       if(temp==NULL){
         printf("Position out of range");
         return;
       }
       temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;

}
void display(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    struct node *head=NULL;
    insertAtBegin(&head,10);
    insertAtEnd(&head,30);
    insertAtMiddle(&head,20,2);

    display(head);
}
