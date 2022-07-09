#include <stdio.h>
#include <stdlib.h>

// Creating the node of a single linked list
typedef struct node node;
struct node
{
    int data;
    node *link;
};

void printList(node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d", head->data);
            if (head->link != NULL)
            {
                printf("->");
            }
            head = head->link;
        }
        printf("\n");
    }
}

void createList(node *head, int n)
{
    int i;
    node *current;

    printf("Creating list...\n");
    for (i = 1; i < n; i++)
    {
        current = malloc(sizeof(node));
        current->data = i;
        current->link = NULL;
        head->link = current;
        head = current;
    }
    printf("List created\n");
}

int listLenght(node *head)
{

    if (head != NULL)
    {
        printf("Counting...\n");
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->link;
        }
        printf("%d nodes\n", count);
        return count;
    }
    else
    {
        printf("Empty list");
    }
}

void addAtEnd(node *head, int data)
{
    printf("Adding at end...\n");
    node *end = malloc(sizeof(node));
    end->data = data;
    end->link = NULL;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = end;
}

void *addAtHead(node **head, int data)
{
    node *newHead = malloc(sizeof(node));
    newHead->data = data;
    newHead->link = *head;
    *head = newHead;
}

void addNodeAtPosition(node *head, int data, int position)
{
    int i = 0;
    node *new = malloc(sizeof(node));

    if (position > listLenght(head))
    {
        printf("Overflow...\n");
    }
    else if (head != NULL)
    {
        printf("Positionning...\n");
        while (i < position)
        {
            if (i == position - 1)
            {
                new->data = data;
                new->link = head->link;
                head->link = new;
            }
            i++;
            head = head->link;
        }
    }
    else
    {
        printf("Empty list");
    }
}

node *deleteHead(node *head)
{
    if (head != NULL)
    {
        printf("Deleting first node...\n");
        node *secund = head;
        head = head->link;
        free(secund);
        return head;
    }
    else
    {
        printf("Empty list\n");
    }
}

void deleteLastNode(node *head)
{

    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        printf("Deleting last node...\n");
        node *tmp1 = head;
        node *tmp2 = head;
        while (tmp1->link != NULL)
        {
            tmp2 = tmp1;
            tmp1 = tmp1->link;
        }
        tmp2->link = NULL;
        free(tmp1);
        tmp1 = NULL;
        printf("Deleted...\n");
    }
}

node *reverse(node *head)
{
    node *prev = NULL;
    node *next = NULL;
    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main()
{
    node *head = NULL;
    head = malloc(sizeof(node));
    head->data = 0;
    head->link = NULL; 

    createList(head, 10);
    printList(head);
    addNodeAtPosition(head, 155, 3);
    head = deleteHead(head);
    printList(head);
    deleteLastNode(head);
    printList(head);
    head = reverse(head);
    printList(head);

    return 0;
}
