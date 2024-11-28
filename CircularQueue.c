#include <stdio.h>
#include <stdlib.h>
void main()
{
    int a[100], front = -1, rear = -1, i, x, y;
    printf("Enter the size of the queue:");
    scanf("%d", &x);
    int b[x];
    while (1)
    {
        printf("Circular Queue Operations are:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            if ((rear + 1) % x == front)
            {
                printf("The circular queue is full.\n");
            }
            else
            {
                if (front == -1)
                {
                    front = 0;
                }
                rear = (rear + 1) % x;
                printf("Enter the element to be inserted:\n");
                scanf("%d", &b[rear]);
            }
            break;

        case 2:
            if (front == -1)
            {
                printf("The circular queue is empty.\n");
            }
            else
            {
                printf("The element that has been deleted from the circular queue is:%d\n", b[front]);
                front = (front + 1) % x;
            }
            break;

        case 3:
            if (front == -1)
            {
                printf("The circular queue is empty.\n");
            }
            else
            {
                if (rear > front)
                {
                    printf("The elements in the circular queue are:\n");
                    for (i = front; i <= rear; i++)
                    {
                        printf("%d\n", b[i]);
                    }
                }
                if(front > rear)
                {
                    printf("The elements in the circular queue are:\n");
                    for (i = front; i < x; i++)
                    {
                        printf("%d\n", b[i]);
                    }
                    for (i = 0; i <= rear; i++)
                    {
                        printf("%d\n", b[i]);
                    }
                }
            }
            break;

        case 4:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}