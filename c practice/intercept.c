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

// Function to get the length of a linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the intersection point of two linked lists
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Align both lists to the same starting point
    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) {
            head1 = head1->next;
        }
    } else if (len2 > len1) {
        int diff = len2 - len1;
        while (diff--) {
            head2 = head2->next;
        }
    }

    // Traverse both lists to find the intersection point
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; // No intersection point
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
    // Create two linked lists
    struct Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = createNode(30);

    struct Node* head2 = createNode(15);
    head2->next = createNode(25);

    // Create an intersection
    struct Node* common = createNode(50);
    head1->next->next->next = common;
    head2->next->next = common;
    common->next = createNode(60);

    printf("List 1: \n");
    printList(head1);

    printf("List 2: \n");
    printList(head2);

    struct Node* intersection = findIntersection(head1, head2);
    if (intersection != NULL) {
        printf("\nIntersection point: %d\n", intersection->data);
    } else {
        printf("\nNo intersection point found.\n");
    }

    return 0;
}
