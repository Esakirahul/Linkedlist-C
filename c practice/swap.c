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

// Function to display the linked list
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to swap two nodes in the linked list (without swapping data)
void swapNodes(struct Node **head, int x, int y) {
    if (x == y) {
        return; // No need to swap if both nodes are the same
    }

    // Initialize previous and current pointers for both x and y
    struct Node *prevX = NULL, *currX = *head;
    struct Node *prevY = NULL, *currY = *head;

    // Find the x node and its previous node
    while (currX != NULL && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Find the y node and its previous node
    while (currY != NULL && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not found, return
    if (currX == NULL || currY == NULL) {
        printf("One or both nodes not found.\n");
        return;
    }

    // If x is not the head node
    if (prevX != NULL) {
        prevX->next = currY;
    } else { // If x is the head node
        *head = currY;
    }

    // If y is not the head node
    if (prevY != NULL) {
        prevY->next = currX;
    } else { // If y is the head node
        *head = currX;
    }

    // Swap the next pointers of x and y
    struct Node *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
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

    printf("Original Linked List: ");
    display(head);

    // Swap nodes with data 20 and 40
    swapNodes(&head, 20, 40);

    printf("Linked List after swapping 20 and 40: ");
    display(head);

    return 0;
}
