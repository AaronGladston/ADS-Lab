#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL, *current, *newnode, *temp, *del;

void insertEnd()
{
    newnode = malloc(sizeof(struct node));
    printf("enter the element :\n");
    scanf("%d", &(newnode->data));
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
        current = newnode;
    }
    else
    {
        current = head;
        while(current->next!=NULL)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->prev = current;
        current = newnode;
    }
}

void insertBeg()
{
    newnode = malloc(sizeof(struct node));
    printf("enter the element :\n");
    scanf("%d", &(newnode->data));
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
        current = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void insertAny()
{
    int pos, i;
    newnode = malloc(sizeof(struct node));
    printf("Enter the element :\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("Enter the position :\n");
    scanf("%d", &pos);
    current = head;
    for (i = 1; i < pos - 1; i++)
    {
        current = current->next;
    }
    temp = current->next;
    current->next = newnode->next;
    newnode->prev = temp->prev;
    temp->prev = newnode;
    current->next = newnode;
}

void display()
{
    temp = head;
    if(temp==NULL)
    {
        printf("The linked list is empty.");
    }
    else{
        while (temp != NULL)
        {
            printf("%d<-->", temp->data);
            temp = temp->next;
        }
    }
}

void delete_End()
{
    current=head;
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
    }
    else if(head->next == NULL)
    {
        head = NULL; 
    }
    else
    { 
        while(current->next->next != NULL)
        {
            current = current->next;
        }
        current->next=NULL;
        
    }
    
}

void delete_Beg()
{
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
    }
    current = head;
    temp = current->next;
    del = temp->next;
    current->next = temp->next;
    del->prev = current;
    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
}

void delete_Any()
{
    int posd, i;
    if (head == NULL)
    {
        printf("The linked list is empty.\n");
    }
    printf("Enter the position:\n");
    scanf("%d", &posd);
    current = head;
    for (i = 1; i < posd - 1; i++)
    {
        current = current->next;
    }
    temp = current->next;
    del = temp->next;
    del->prev = temp->prev;
    current->next = temp->next;
    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
}

int main()
{
    int c;
    do
    {
        printf("\n1.Insertion at end\n2.Insertion at beginning\n3.Insertion at any point\n4.Display\n5.Deletion at end\n6.Deletion at beginning\n7.Deletion at any point\n8.Exit\nEnter the operation : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insertEnd();
            break;

        case 2:
            insertBeg();
            break;

        case 3:
            insertAny();
            break;

        case 4:
            display();
            break;

        case 5:
            delete_End();
            break;

        case 6:
            delete_Beg();
            break;

        case 7:
            delete_Any();
            break;

        case 8:
            printf("Exiting the program.\n");
            exit(0);
            break;

        default:
            printf("invalid input");
            break;
        }
    } while (1);
}