// To implement the operations like create, count, reverse and display in a singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(struct Node *head)
{
    struct Node *newNode, *temp;
    int n, i, value;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("\nError");
        return head;
    }
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\nMemory allocation failed");
            return head;
        }
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printf("\nList created successfully");
    return head;
}

int countNodes(struct Node *head)
{
    struct Node *temp;
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *nextNode;
    if (head == NULL)
    {
        printf("\nList is empty");
        return head;
    }
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    printf("\nList reversed successfully");
    return head;
}

void display(struct Node *head)
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    temp = head;
    printf("\nList: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    struct Node *head = NULL;
    int option;

    while (option != 5)
    {
        printf("\nMAIN MENU");
        printf("\n1. Create a list");
        printf("\n2. Count the nodes");
        printf("\n3. Reverse the list");
        printf("\n4. Display the list");
        printf("\n5. Exit");
        printf("\n\nEnter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head = createList(head);
            break;
        case 2:
            printf("\nTotal number of nodes: %d", countNodes(head));
            break;
        case 3:
            head = reverseList(head);
            break;
        case 4:
            display(head);
            break;
        case 5:
            while (head != NULL)
            {
                struct Node *temp = head;
                head = head->next;
                free(temp);
            }
            printf("\nExit");
            break;
        default:
            printf("\nInvalid option");
        }
    }
    return 0;
}
