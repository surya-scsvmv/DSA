#include <stdio.h>
#include <stdlib.h>
 
// Create node for linked list
struct Node
{
    int data;
    struct Node *next; // To hold the address of next node
};
 
// To create a node and it returns address of newly created node
struct Node *CreateNode(int data)
{
    // STACK = (char *)malloc(MAX * sizeof(char));
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node with data %d inserted at beginning successfully  .\n", data);
}
 
void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Node with data %d inserted at the end successfully.\n", data);
}
 
void InsertAtPosition(struct Node **head, int data, int position)
{
    // Considering that the position starts from 1 (Head at 1)
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
 
    if (position == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }
 
    struct Node *prev = *head;
    for (int k = 1; (k < position - 1 && prev != NULL); k++)
    {
        prev = prev->next;
    }
 
    if (prev == NULL)
    {
        printf("Given position is out of range!\n");
        return;
    }
 
    // Only when given position is valid
    struct Node *newNode = CreateNode(data);
    newNode->next = prev->next;
    prev->next = newNode;
 
    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}
 
// Delete a node by value
void DeleteNode(struct Node **head, int valueToDelete)
{
    if (*head == NULL)
    {
        printf("Linked List is empty, deletio operation can't be performed");
        return;
    }
 
    struct Node *temp = *head;
 
    // If head itself holds the value
    if (temp->data == valueToDelete)
    {
        *head = temp->next;
        free(temp);
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }
 
    // Search for the value
    /* while (temp != NULL && temp->data != valueToDelete)
    {
        prev = temp;
        temp = temp->next;
    }*/
 
    struct Node *prev = *head;
    while (prev->next != NULL)
    {
        if (prev->next->data == valueToDelete)
        {
            temp = prev->next;
            prev->next = temp->next;
            free(temp);
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        prev = prev->next;
    }
 
    // If key not found
    if (prev->next == NULL)
    {
        printf("Element %d not found.\n", valueToDelete);
        return;
    }
}
 
// Display all elements
void DisplayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
 
    struct Node *temp;
    temp = head;
    printf("\nLinked List Nodes: ");
    while (temp != NULL)
    {
        // if(temp == head)
        // {
        //     printf("|head|%p| ->", temp);
        // }
        printf(" |At=%p|%d|Next=%p| -> ", temp, temp->data, temp->next);
        temp = temp->next;
    }
   // printf("NULL\n");
}
 
// Main function
int main()
{
    struct Node *head = NULL;
    int choice, data, pos;
 
    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data and position to insert: ");
            scanf("%d %d", &data, &pos);
            InsertAtPosition(&head, data, pos);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            DeleteNode(&head, data);
            break;
        case 5:
            DisplayList(head);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
