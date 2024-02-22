// Creating and displaying of linked list

#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *newnode, *start, *temp;
void create(int value)
{
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void display()
{
    temp = start;
    printf("The Linked list is:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int nodes,i,value;
    printf("Enter how many nodes:");
    scanf("%d",&nodes);
    for (i=1;i<=nodes;i++)
    {
        printf("Enter the %d value",i);
        scanf("%d",&value);
        create(value);
    }
    display();
    return 0;
}