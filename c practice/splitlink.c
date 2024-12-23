#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void splitlist(struct node *head,int k){
    struct node *current=head;
    int totalnodes=0;

    while(current!=NULL){
        totalnodes++;
        current=current->next;
    }
    int basesize=totalnodes/k; 
    int extranodes=totalnodes%k;

    current=head;
    for(int i=0;i<k;i++){
        int partsize=basesize+(extranodes>0?1:0);
        extranodes--;

        for(int j=0;j<partsize;j++){
            if(current!=NULL){
                printf("%d",current->data);
                current=current->next;
            }
        }
        printf("\n");
    }
}

int main(){
    struct node *head,*old,*n;
    int num;
    scanf("%d",&num);
    //creating head node
    head=malloc(sizeof(struct node));
    scanf("%d",&head->data);
    head->next=NULL;
    old=head;

    //creating remaining nodes
    for(int i=1;i<num;i++)
    {
        n=malloc(sizeof(struct node));
        scanf("%d",&n->data);
        n->next=NULL;
        old->next=n;
        old=n;
    }
    int k;
    scanf("%d",&k);
    splitlist(head,k);


}
