/* Delete First Occurrence of a Key - Implement 
using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove
 it by adjusting previous node's next pointer.*/

 #include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node *next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
    return head;
}

// Delete first occurrence of key
struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // If list is empty
    if(head == NULL)
        return head;

    // If head contains key
    if(head->data == key) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Search for key
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key found
    if(temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

// Print linked list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, key;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    printList(head);

    return 0;
}