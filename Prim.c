#include <stdio.h>
#define INF 999999
int v, i, j, a[20][20], start, visited[20];
void prim(int a[][], int start);
int minKey(int key[], int mstSet[]);
void printMST(int parent[], int a[][]);

int main()
{
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &v);
    for (i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    printf("Enter the adjacency matrix with the elements as the weights:\n");
    for (i = 0; i < v; i++)
    {
        printf("A[%d][%d] = ");
        scanf("%d", &a[i][j]);
    }
    printf("Enter the starting node: ");
    scanf("%d", &start);
    if (start < 0 || start >= v)
    {
        printf("Invalid entry.\n");
        return 0;
    }
    prim(a, start);
    return 0;
}

void prim(int a[v][v], int start)
{
    int parent[v];
    int key[v];
    int mstSet[v];
    for (i = 0; i < v; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }
    key[0] = start;
    parent[0] = -1;
    for (i = 0; i < v - 1; i++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (i = 0; i < v; i++)
        {
            if (a[u][v] && mstSet == 0 && a[u][v]<key[v])
            {
                parent[v] = u;
                key[v] = a[u][v];
            }
        }
    }
    printMST(parent,a); 
}

int minKey(int key[], int mstSet[])
{
    int min = INF, minIndex;
    for(j=0;j<v;j++)
    {
        if(mstSet[v] == 0 && key[v]<min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int a[v][v])
{
    printf("Edge\tWeight\n");
    for(i=1;i<v;i++)
    {
        printf("%d - %d \t%d \n",parent[i],i,a[i][parent[i]]);
    }
}