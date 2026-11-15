#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node*next;
};
struct Node*head=NULL;
void search(int key)
{
    struct Node *current = head;
    int position = 1;

    while (current != NULL)
    {
        if (current->data == key)
        {
            printf("Found at %d", position);
            return;
        }

        current = current->next;
        position++;
    }

    printf("Not found");
}
void display()
{
    struct Node *current = head;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL");
}
void insertBeginning(int data)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
void insertEnd(int data)
{
    struct Node *newNode;
    struct Node *current;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}
void insertPosition(int data, int position)
{
    struct Node *current;
    struct Node *newNode;

    if (position < 1)
    {
        printf("Invalid position");
        return;
    }

    if (position == 1)
    {
        insertBeginning(data);
        return;
    }

    current = head;

    for (int i = 1; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid position");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
}
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("No node exists");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}
void deleteEnd()
{
    struct Node *current;

    if (head == NULL)
    {
        printf("No node exists");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    current = head;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}
void deletePosition(int position)
{
    struct Node *current;
    struct Node *temp;

    if (position < 1 || head == NULL)
    {
        printf("Invalid position or empty list");
        return;
    }

    if (position == 1)
    {
        deleteBeginning();
        return;
    }

    current = head;

    for (int i = 1; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("Invalid position");
        return;
    }

    temp = current->next;
    current->next = temp->next;

    free(temp);
}
void reverse() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int main() {
	struct Node*first = malloc(sizeof(struct Node));
	struct Node*second = malloc(sizeof(struct Node));
	struct Node*third = malloc(sizeof(struct Node));
	if(first==NULL || second==NULL || third==NULL){
		printf("memory allocation failed");
		return 1;
	}
	first->data=10;
	second->data=20;
	third->data=30;
	first->next=second;
	second->next=third;
	third->next=NULL;
	head=first;

    int choice, data, key, pos;
    display();

    while (1) {
        printf("\n\n--- Singly Linked List ---");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Middle");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Middle");
        printf("\n7. Display");
        printf("\n8. Reverse");
        printf("\n9. Search");
        printf("\n10. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                insertPosition(data, pos);
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
                deletePosition(pos);
                display();
                break;

            case 7:
                display();
                break;
            case 8:
            	reverse();
            	display();
            	break;
            case 9:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 10:
                printf("Exiting program...");
                return 0;

            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}
