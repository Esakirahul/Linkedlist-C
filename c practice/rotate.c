#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node
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

// Function to get the length of the linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to rotate the linked list to the right by k positions
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k <= 0) return head;

    int length = getLength(head);
    k = k % length; // Handle cases where k is greater than the length of the list
    if (k == 0) return head;

    struct Node* current = head;
    for (int i = 1; i < length - k; i++) {
        current = current->next;
    }

    struct Node* newHead = current->next;
    current->next = NULL;

    struct Node* temp = newHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;

    return newHead;
}

// Function to rotate the linked list to the left by k positions
struct Node* rotateLeft(struct Node* head, int k) {
    if (head == NULL || k <= 0) return head;

    int length = getLength(head);
    k = k % length; // Handle cases where k is greater than the length of the list
    if (k == 0) return head;

    struct Node* current = head;
    for (int i = 1; i < k; i++) {
        current = current->next;
    }

    struct Node* newHead = current->next;
    current->next = NULL;

    struct Node* temp = newHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;

    return newHead;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);

    int k = 2;
    printf("\nList after rotating right by %d positions:\n", k);
    head = rotateRight(head, k);
    printList(head);

    k = 3;
    printf("\nList after rotating left by %d positions:\n", k);
    head = rotateLeft(head, k);
    printList(head);

    return 0;
}
