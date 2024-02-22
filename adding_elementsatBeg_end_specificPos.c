//Adding elements at beg,end,specific position

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
Node *newnode,*start,*temp;
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
    int len=0;
    temp = start;
    printf("The Linked list is:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        len++;
    }
    printf("\nThe length of the linked list is %d",len);
}

void addatbeg(int value)
{
    newnode = (Node*) malloc (sizeof(Node));
    if (start == NULL)
    {
        newnode->data = value;
        newnode->next = NULL;
    }
    else 
    {
         newnode->data = value;
        temp = start;
        newnode->next = temp;
        start = newnode;
    }
}

void addatend(int value)
{
    newnode = (Node*)malloc(sizeof(Node));
    if (start == NULL)
    {
        newnode->data = value;
        newnode->next = NULL;
        start = newnode;
    }
    else 
    {
        newnode->data = value;
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
}

void addatpos(int value,int pos)
{
    newnode = (Node*)malloc(sizeof(Node));
    int i=1,len=0;
    temp=start;
    while (temp != NULL)
    {
        len++;
        temp=temp->next;
    }
    if (pos>len)
    {
        printf("Cannot Add at this position");
    }
    else
    {
        newnode->data = value;
        temp = start;
        while (i < (pos-1))
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

}

int main()
{
    int nodes,i,value,position;
    printf("Enter how many nodes:");
    scanf("%d",&nodes);
    for (i=1;i<=nodes;i++)
    {
        printf("Enter the %d value:",i);
        scanf("%d",&value);
        create(value);
    }
    display();
    printf("\nEnter the value to be add at beginning:");
    scanf("%d",&value);
    addatbeg(value);
    display();
    printf("\nEnter the value to be added at the end:");
    scanf("%d",&value);
    addatend(value);
    display();
    printf("\nEnter the value to be added at the specific position:");
    scanf("%d",&value);
    printf("Enter the position:");
    scanf("%d",&position);
    addatpos(value,position);
    display();
    return 0;
}