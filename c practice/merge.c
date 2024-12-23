#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to merge two sorted linked lists
struct node *mergeSortedLists(struct node *list1, struct node *list2) {
    // Create a dummy node to simplify operations
    struct node dummy;
    dummy.next = NULL;
    struct node *tail = &dummy;

    // Traverse both lists and merge them in sorted order
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes from either list
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // Return the merged list, skipping the dummy node
    return dummy.next;
}

// Function to display the linked list
void display(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct node *list1 = NULL, *list2 = NULL;

    // Create the first sorted linked list
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);
    insertAtEnd(&list1, 7);

    // Create the second sorted linked list
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);
    insertAtEnd(&list2, 8);

    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    // Merge the two lists
    struct node *mergedList = mergeSortedLists(list1, list2);
    printf("Merged List: ");
    display(mergedList);

    return 0;
}
