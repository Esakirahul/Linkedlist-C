#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

// Function to count the number of nodes in the linked list
int countNodes(struct node *head) {
    int count = 0;            // Initialize the counter
    struct node *temp = head; // Start from the head node

    while (temp != NULL) {    // Traverse the list
        count++;
        temp = temp->next;
    }
    return count;             // Return the final count
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

    // Display the linked list
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");

    // Count and display the number of nodes
    int count = countNodes(head);
    printf("Number of nodes: %d\n", count);

    return 0;
}
