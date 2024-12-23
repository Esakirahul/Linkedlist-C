#include <stdio.h>
#include <stdlib.h>

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

// Function to detect and remove a loop in a linked list
void detectAndRemoveLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect loop using Floyd's cycle detection algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, loop exists
        if (slow == fast) {
            break;
        }
    }

    // If no loop is detected
    if (fast == NULL || fast->next == NULL) {
        printf("No loop detected.\n");
        return;
    }

    // Remove the loop
    slow = head;
    struct Node* prev = NULL;

    // If the loop starts at the head
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }

    // Move slow and fast one step at a time
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the loop
    fast->next = NULL;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver program to test the function
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Create a loop for testing
    head->next->next->next->next->next = head->next;

    detectAndRemoveLoop(head);
    printf("Linked list after removing the loop:\n");
    printList(head);

    return 0;
}
