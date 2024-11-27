#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[50], i, j, m, n, x, choice, flag, pos, temp, ent = -1;
    printf("The array operations are:\n1. Insertion\n2. Deletion\n3. Searching\n4. Sorting\n5. Exit\n");
    printf("Enter the size of the array:\n");
    scanf("%d", &m);

    while (1)
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (ent == m - 1)
            {
                printf("The array is full.\n");
            }
            else
            {
                printf("Enter the position (1 to %d) where the element is to be inserted: ", ent + 2);
                scanf("%d", &pos);

                if (pos < 1 || pos > ent + 2)
                {
                    printf("Invalid position.\n");
                }
                else
                {
                    printf("Enter the element to insert: ");
                    scanf("%d", &x);

                    for (i = ent; i >= pos - 1; i--)
                    {
                        a[i + 1] = a[i];
                    }
                    a[pos - 1] = x;
                    ent++;
                    printf("Element inserted successfully.\n");
                }
            }
            break;

        case 2:
            if (ent == -1)
            {
                printf("There are no elements in the array.\n");
            }
            else
            {
                printf("Enter the position (1 to %d) of the element to delete: ", ent + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > ent + 1)
                {
                    printf("Invalid position.\n");
                }
                else
                {
                    printf("The element deleted is: %d\n", a[pos - 1]);
                    for (i = pos - 1; i < ent; i++)
                    {
                        a[i] = a[i + 1];
                    }
                    ent--;
                }
            }
            break;

        case 3:
            if (ent == -1)
            {
                printf("The array is empty. Nothing to search.\n");
            }
            else
            {
                printf("Enter the element to search: ");
                scanf("%d", &x);

                flag = 0;
                for (i = 0; i <= ent; i++)
                {
                    if (a[i] == x)
                    {
                        flag = 1;
                        pos = i;
                        break;
                    }
                }

                if (flag == 1)
                {
                    printf("Element found at position %d.\n", pos + 1);
                }
                else
                {
                    printf("Element not found.\n");
                }
            }
            break;

        case 4:
            if (ent == -1)
            {
                printf("The array is empty. Nothing to sort.\n");
            }
            else
            {
                for (i = 0; i < ent; i++)
                {
                    for (j = 0; j < ent - i; j++)
                    {
                        if (a[j] > a[j + 1])
                        {
                            temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                    }
                }

                printf("Sorted array is:\n");
                for (i = 0; i <= ent; i++)
                {
                    printf("%d ", a[i]);
                }
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting the program.\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}
