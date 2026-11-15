#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// 1. Creation of 3 Nodes
void create()
{
    struct Node *first, *second, *third;

    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    first->data = 10;
    first->prev = NULL;
    first->next = second;

    second->data = 20;
    second->prev = first;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    head = first;
}

// 2. Display
void display(struct Node *head)
{
    struct Node *current = head;

    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }

    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// 3. Insertion at Beginning
void insertBeginning(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

// 4. Insertion at End
void insertEnd(int data)
{
    struct Node *newNode, *current;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

// 5. Insertion in the Middle
void insertMiddle(int data, int pos)
{
    struct Node *newNode;
    struct Node *current;

    if (pos <= 1)
    {
        printf("Invalid position");
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    newNode->data = data;
    current = head;

    for (int i = 1; i < pos - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid Middle position");
        free(newNode);
        return;
    }

    newNode->prev = current;
    newNode->next = current->next;

    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

// 6. Delete from Beginning
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);
}

// 7. Delete from End
void deleteEnd()
{
    struct Node *current;

    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->prev->next = NULL;

    free(current);
}

// 8. Delete from Middle
void deleteMiddle(int pos)
{
    struct Node *current;

    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }

    current = head;

    for (int i = 1; i < pos && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid position");
        return;
    }

    if (current->prev == NULL || current->next == NULL)
    {
        printf("Not a Middle position");
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current);
}

// 9. Searching
void search(struct Node *head, int key)
{
    struct Node *current = head;

    while (current != NULL)
    {
        if (current->data == key)
        {
            printf("Element found");
            return;
        }

        current = current->next;
    }

    printf("Element not found");
}

// Main Function
int main()
{
    int choice, data, pos, key;

    create();

    do
    {
        printf("\n\n--- Doubly Linked List ---\n");

        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Middle");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Middle");
        printf("\n7. Display");
        printf("\n8. Search");
        printf("\n9. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                display(head);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                display(head);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertMiddle(data, pos);
                display(head);
                break;

            case 4:
                deleteBeginning();
                display(head);
                break;

            case 5:
                deleteEnd();
                display(head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteMiddle(pos);
                display(head);
                break;

            case 7:
                display(head);
                break;

            case 8:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(head, key);
                break;

            case 9:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid choice");
        }

    } while (choice != 9);

    return 0;
}