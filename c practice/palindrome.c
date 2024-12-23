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

// Function to check if a linked list is a palindrome
int palindrome(struct Node *head) {
    struct Node *current = head;
    int arr[1000]; // Assuming the linked list will have at most 1000 nodes
    int size = 0;

    // Traverse the linked list and store elements in the array
    while (current != NULL) {
        arr[size++] = current->data;
        current = current->next;
    }

    // Check if the array is a palindrome
    int i = 0, j = size - 1;
    while (i < j) {
        if (arr[i] != arr[j]) {
            return 0; // Not a palindrome
        }
        i++;
        j--;
    }
    return 1; // Is a palindrome
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
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);

    printf("Linked List: ");
    display(head);

    // Check if the linked list is a palindrome
    if (palindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
