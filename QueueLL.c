#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*head=NULL,*current,*newnode,*temp;

void main()
{
    int ch;
    printf("Queue operations:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
    while(1)
    {
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            newnode = (struct node *)malloc(sizeof(struct node));
                        if (newnode == NULL)
            {
                printf("Memory allocation has been failed.\n");
            }
            printf("Enter the element to be inserted:\n");
            scanf("%d", &newnode->data);
            newnode->link = NULL;
            if (head == NULL)
            {
                head = newnode;
                current = newnode;
            }
            else
            {
                current->link = newnode;
                current = newnode;
            }
            break;
             
             case 2:
             if (head == NULL)
            {
                printf("The linked list is empty.\n");
            }
            else
            {
                current = head;
                temp = current->link->link;
                current->link->link = temp->link;
                free(temp);
            }
            break;

            case 3:
            current = head;
            printf("The linked list is:\n");
            while (current != NULL)
            {
                printf("%d\n", current->data);
                current = current->link;
            }
            break;

            case 4:
            current = head;
            while (current->link != NULL)
            {
                current = current->link;
            }
            printf("The peek element in the stack is:%d\n", current->data);
            break;

            case 5:
            printf("Exiting the program");
            exit(1);

            default:
            printf("Invalid choice");
        }
    }
}