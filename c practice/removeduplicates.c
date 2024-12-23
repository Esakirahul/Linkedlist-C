#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to remove duplicates from the linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    // Traverse the linked list
    while (current != NULL && current->next != NULL) {
        struct Node* temp = current;

        // Compare current node with the next nodes
        while (temp->next != NULL) {
            if (current->data == temp->next->data) {
                // Duplicate found, remove it
                struct Node* duplicate = temp->next;
                temp->next = temp->next->next;
                free(duplicate);
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(10);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(20);

    printf("Original List:\n");
    printList(head);

    removeDuplicates(head);

    printf("\nList After Removing Duplicates:\n");
    printList(head);

    return 0;
}
