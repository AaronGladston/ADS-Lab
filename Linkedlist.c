#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *newnode, *current, *temp;
void main()
{
    printf("Linked list opertions are:\n1.Insertion at the end\n2.Insertion at any point\n3.Insertion at beginnning\n4.Traversal and Display\n5.Deletion from end\n6.Deletion from any point\n7.Deletion from beginning\n8.Exit\n");
    while (1)
    {
        int n, pos, i, j, posd;
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
            printf("Enter the position where the element is to be entered:");
            scanf("%d", &pos);
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("Memory allocation has been failed.\n");
            }
            printf("Enter the element to be inserted:\n");
            scanf("%d", &newnode->data);
            newnode->link = NULL;
            current = head;
            for (i = 1; i < pos - 1; i++)
            {
                current = current->link;
            }
            if (i == pos - 1)
            {
                newnode->link = current->link;
                current->link = newnode;
            }
            break;

        case 3:
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("Memory allocation has been failed.\n");
            }
            printf("Enter the element to be inserted:\n");
            scanf("%d", &newnode->data);
            newnode->link = head;
            head = newnode;
            break;

        case 4:
            current = head;
            printf("The linked list is:\n");
            while (current != NULL)
            {
                printf("%d\n", current->data);
                current = current->link;
            }
            break;

        case 5:
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
                free(temp);
            }
            break;

        case 6:
            if (head == NULL)
            {
                printf("The linked list is empty.\n");
            }
            else
            {
                printf("Enter the position from where the element is to be deleted:\n");
                scanf("%d", &posd);
                current = head;
                for (j = 1; j < posd - 1; j++)
                {
                    current = current->link;
                }
                temp = current->link;
                current->link = temp->link;
                free(temp);
            }
            break;

        case 7:
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

        case 8:
            exit(1);

        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}