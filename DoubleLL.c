#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*current,*newnode,*temp;

void insertEnd()
{
    newnode=malloc(sizeof(struct node));
    printf("enter the element : ");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    newnode->prev=NULL;
    if (head==NULL)
    {
        head=newnode;
        current=newnode;
    }
    else
    {
        current->next=newnode;
        newnode->prev=current;
        current=newnode;
    } 
}

void insertBeg()
{
    newnode=malloc(sizeof(struct node));
    printf("enter the element : ");
    scanf("%d",&(newnode->data));
    newnode->next=NULL;
    newnode->prev=NULL;
    if (head==NULL)
    {
        head=newnode;
        current=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    } 
}

void display()
{
    temp=head;
    while (temp!=NULL)
    {
        printf("%d<-->",temp->data);
        temp=temp->next;
    }
} 

void delete_end()
{
    
}

int main()
{
    int c;
    do
    {
        printf("\n1.Insertion at end\n2.Insertion at beginning\n3.display\n4.exit\nenter the operation : ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            insertEnd();
            break;
        case 2:
            insertBeg();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
        printf("invalid input");
            break;
        }
    } while (1);
}