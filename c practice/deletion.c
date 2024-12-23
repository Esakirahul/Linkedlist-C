#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createnode(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a node at the end of the list
void insertion(struct node **head, int data) {
    struct node *newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Function to delete a node from the beginning
void deleteAtBegin(struct node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next; // Move head to the next node
    free(temp); // Free the old head
    printf("Node deleted at the beginning.\n");
}

// Function to delete a node from the end
void deleteAtEnd(struct node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        // If there's only one node
        free(*head);
        *head = NULL;
        printf("Node deleted at the end.\n");
        return;
    }
    struct node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next); // Free the last node
    temp->next = NULL; // Set second-last node's next to NULL
    printf("Node deleted at the end.\n");
}

// Function to delete a node from a specific position
void deleteAtPos(struct node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (pos == 1) {
        // If the position is 1, delete the first node
        deleteAtBegin(head);
        return;
    }
    struct node *temp = *head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of range.\n");
            return;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct node *del = temp->next; // Node to be deleted
    temp->next = del->next; // Link the previous node to the next node
    free(del); // Free the deleted node
    printf("Node deleted at position %d.\n", pos);
}

// Function to display the linked list
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node *head = NULL;

    // Insert some nodes
    insertion(&head, 10);
    insertion(&head, 20);
    insertion(&head, 30);
    insertion(&head, 40);
    insertion(&head, 50);

    printf("Original list: ");
    display(head);

    // Delete at the beginning
    deleteAtBegin(&head);
    printf("After deleting at beginning: ");
    display(head);

    // Delete at the end
    deleteAtEnd(&head);
    printf("After deleting at end: ");
    display(head);

    // Delete at a specific position
    deleteAtPos(&head, 2);
    printf("After deleting at position 2: ");
    display(head);

    return 0;
}
