#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to find the nth node from the end of the list
void findNthFromEnd(struct Node *head, int n) {
    struct Node *mainPtr = head;
    struct Node *refPtr = head;

    // Move refPtr n nodes ahead
    for (int i = 0; i < n; i++) {
        if (refPtr == NULL) {
            printf("The list has fewer than %d nodes.\n", n);
            return;
        }
        refPtr = refPtr->next;
    }

    // Move both pointers one step at a time until refPtr reaches the end
    while (refPtr != NULL) {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }

    // mainPtr points to the nth node from the end
    printf("The %dth node from the end is: %d\n", n, mainPtr->data);
}

// Function to display the linked list
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node *head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Linked List: ");
    display(head);

    int n = 3; // Change this value to test for other positions
    findNthFromEnd(head, n);

    return 0;
}
