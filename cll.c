#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Creation of 3 nodes
void create()
{
    struct Node *first, *second, *third;

    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = first;

    head = first;
}

// Display
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("(Back to Head)\n");
}

// Insert at Beginning
void insertBeginning(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at End
void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Insert at Middle / Any Position
void insertMiddle(int value, int pos)
{
    struct Node *newNode, *temp;
    int i;

    if (pos <= 1)
    {
        insertBeginning(value);
        return;
    }

    if (head == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (i != pos - 1)
    {
        printf("Invalid Position\n");
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from Beginning
void deleteBeginning()
{
    struct Node *temp, *deleteNode;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    deleteNode = head;
    head = head->next;
    temp->next = head;

    free(deleteNode);
}

// Delete from End
void deleteEnd()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    prev = NULL;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// Delete from Middle / Any Position
void deleteMiddle(int pos)
{
    struct Node *current, *temp;
    int i;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (pos <= 1)
    {
        deleteBeginning();
        return;
    }

    current = head;

    for (i = 1; i < pos - 1 && current->next != head; i++)
    {
        current = current->next;
    }

    if (current->next == head || i != pos - 1)
    {
        printf("Invalid Position\n");
        return;
    }

    temp = current->next;
    current->next = temp->next;

    free(temp);
}

// Searching
void search(int key)
{
    struct Node *temp = head;
    int pos = 1;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    do
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;

    } while (temp != head);

    printf("Element not found\n");
}

// Main Function
int main()
{
    int choice, data, key, pos;

    create();

    do
    {
        printf("\n--- Circular Linked List ---\n");
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
                display();
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                display();
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertMiddle(data, pos);
                display();
                break;

            case 4:
                deleteBeginning();
                display();
                break;

            case 5:
                deleteEnd();
                display();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteMiddle(pos);
                display();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 9:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 9);

    return 0;
}