#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

// Function to reverse the linked list
struct node* reverse(struct node* head) {
    struct node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev forward
        current = next;        // Move current forward
    }
    return prev;  // New head of the reversed list
}

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

    // Display the original linked list
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");

    // Reverse the linked list
    head = reverse(head);

    // Display the reversed linked list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
