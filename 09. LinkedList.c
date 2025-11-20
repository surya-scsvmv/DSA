/*
  Aim:
  Perform insertion, deletion and traversal on a singly linked list.
*/

#include <stdio.h>
#include <stdlib.h>

// Simple node structure
struct Node {
    int data;
    struct Node *next;
};

// Create a new node (basic wrapper)
struct Node* createNode(int val) {
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL) {
        printf("Memory error!\n");
        return NULL;
    }
    t->data = val;
    t->next = NULL;
    return t;
}

// Insert at beginning
void insertBeg(struct Node **head, int val) {
    struct Node *t = createNode(val);
    t->next = *head;      // new node -> old head
    *head = t;            // head moved to new node
    printf("Inserted %d at beginning\n", val);
}

// Insert at end
void insertEnd(struct Node **head, int val) {
    struct Node *t = createNode(val);

    if(*head == NULL) {       // empty list case
        *head = t;
        printf("Inserted %d at end\n", val);
        return;
    }

    struct Node *cur = *head;
    while(cur->next != NULL)  // go till last node
        cur = cur->next;

    cur->next = t;
    printf("Inserted %d at end\n", val);
}

// Insert at any position (1-based indexing)
void insertPos(struct Node **head, int val, int pos) {
    if(pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1) {
        insertBeg(head, val);
        return;
    }

    struct Node *cur = *head;
    for(int i = 1; i < pos - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    if(cur == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node *t = createNode(val);
    t->next = cur->next;
    cur->next = t;

    printf("Inserted %d at position %d\n", val, pos);
}

// Delete a node by value
void deleteVal(struct Node **head, int val) {
    if(*head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *cur = *head;

    // if the node to delete is the head
    if(cur->data == val) {
        *head = cur->next;
        free(cur);
        printf("Deleted %d\n", val);
        return;
    }

    struct Node *prev = NULL;
    while(cur != NULL && cur->data != val) {
        prev = cur;
        cur = cur->next;
    }

    if(cur == NULL) {
        printf("Value %d not found\n", val);
        return;
    }

    prev->next = cur->next;
    free(cur);
    printf("Deleted %d\n", val);
}

// Print all nodes
void display(struct Node *head) {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *cur = head;
    printf("List: ");
    while(cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int ch, val, pos;

    while(1) {
        printf("\n1.Insert Beg\n2.Insert End\n3.Insert Pos\n4.Delete\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBeg(&head, val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertPos(&head, val, pos);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteVal(&head, val);
                break;

            case 5:
                display(head);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
