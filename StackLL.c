#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *current, *newnode, *temp;
void main()
{
    printf("Stack Operations:\n1.Push\n2.Display\n3.Peek\n4.Pop\n5.Exit\n");
    while (1)
    {
        int n;
        printf("Enter your choice:\n");
        scanf("%d", &n);
        switch (n)
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
            current = head;
            printf("The linked list is:\n");
            while (current != NULL)
            {
                printf("%d\n", current->data);
                current = current->link;
            }
            break;

        case 3:
            current = head;
            while (current->link != NULL)
            {
                current = current->link;
            }
            printf("The peek element in the stack is:%d\n", current->data);
            break;

        case 4:
            if (head == NULL)
            {
                printf("The linked list is empty.\n");
            }
            else
            {
                current = head;
                while (current->link->link != NULL)
                {
                    current = current->link;
                }
                current->link = NULL;
            }
            break;

        case 5:
            exit(1);

        default:
        printf("Invalid choice.\n");
        }
    }
}
