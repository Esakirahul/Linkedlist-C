#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

int main() {
    struct node *head, *old, *n;
    int num;

    // Input the number of nodes
    scanf("%d", &num);

    // Create the head node
    head = malloc(sizeof(struct node));
    scanf("%d", &head->info);
    head->next = NULL;
    old = head;

    // Create the remaining nodes
    for (int i = 1; i < num; i++) {
        n = malloc(sizeof(struct node));
        scanf("%d", &n->info);
        n->next = NULL;
        old->next = n;  // Properly link the nodes
        old = n;
    }

    // Display the linked list
    //p = head;
    while (head != NULL) {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n");

    return 0;
}
