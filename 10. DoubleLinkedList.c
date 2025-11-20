/*
  Aim:
  Create a doubly linked list and perform insertion, deletion
  and forward/backward traversal.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for DLL
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;   // start of the list

// Insert at beginning of DLL
void insertBeg(int val) {
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL) {
        printf("Memory error\n");
        return;
    }

    t->data = val;
    t->prev = NULL;
    t->next = head;

    if(head != NULL) {
        head->prev = t;     // link old head back to new node
    }

    head = t;
    printf("Inserted %d at beginning\n", val);
}

// Insert at end of DLL
void insertEnd(int val) {
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL) {
        printf("Memory error\n");
        return;
    }

    t->data = val;
    t->next = NULL;

    if(head == NULL) {
        t->prev = NULL;
        head = t;
        printf("Inserted %d at end\n", val);
        return;
    }

    struct Node *cur = head;
    while(cur->next != NULL)
        cur = cur->next;

    cur->next = t;
    t->prev = cur;

    printf("Inserted %d at end\n", val);
}

// Delete node by value
void deleteVal(int key) {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *cur = head;

    // find the node
    while(cur != NULL && cur->data != key)
        cur = cur->next;

    if(cur == NULL) {
        printf("Value %d not found\n", key);
        return;
    }

    // if deleting the first node
    if(cur->prev == NULL) {
        head = cur->next;
        if(head != NULL)
            head->prev = NULL;
    } else {
        cur->prev->next = cur->next;
    }

    // connect the next node back if exists
    if(cur->next != NULL)
        cur->next->prev = cur->prev;

    free(cur);
    printf("Deleted %d\n", key);
}

// Print DLL from left to right
void displayForward() {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *cur = head;
    printf("Forward: ");

    while(cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// Print DLL from right to left
void displayBackward() {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    // go to last node
    struct Node *cur = head;
    while(cur->next != NULL)
        cur = cur->next;

    printf("Backward: ");
    while(cur != NULL) {
        printf("%d <- ", cur->data);
        cur = cur->prev;
    }
    printf("NULL\n");
}

int main() {
    int ch, val, key;

    while(1) {
        printf("\n1.Insert Beg\n2.Insert End\n3.Delete\n4.Display Forward\n5.Display Backward\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBeg(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteVal(key);
                break;

            case 4:
                displayForward();
                break;

            case 5:
                displayBackward();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
