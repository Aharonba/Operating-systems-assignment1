// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Number of vertices in the graph
#define MAX_VERTIX 1000

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[], int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int V)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[MAX_VERTIX][MAX_VERTIX], int V, int src)
{
    int dist[V]; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, V);
}

void scanMtraix(int adjMatrix[MAX_VERTIX][MAX_VERTIX], int numOfVertix)
{
    int ch;
    for (int i = 0; i < numOfVertix; i++)
    {
        printf("Enter the weight of the egdes from vertix %d to the other vertices: ", i);
        for (int j = 0; j < numOfVertix; j++)
        {
            int value;

            // Checking that the user enters valid values into the metric

            if (scanf("%d", &value) != 1 || value < 0)
            {
                printf("invalid value");
                exit(1);
            }

            adjMatrix[i][j] = value;
        }

        /** Checking that the user enters an exact number of values per line,
        if the user inserted unnecessary spaces at the end of the line the program will continue to run
        */
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            if (!isspace(ch))
            {
                printf("Error: You entered too many values in a line.\n");
                exit(1);
            }
        }
    }
}
// driver's code
int main()
{

    for (;;)
    {
        int ch;
        int numOfVertix;
        int adjMatrix[MAX_VERTIX][MAX_VERTIX];

        printf("Enter the number of the vertix in the graph:");
        scanf("%d", &numOfVertix);

        // Checking that the user entered a valid value of number of vertices

        if ((ch = getchar()) != '\n' && ch != EOF)
        {
            printf("Error:You entered invalid value .\n");
            return 1;
        }

        else if (numOfVertix > MAX_VERTIX)
        {
            printf("The maximum number of vertices is 1000");
            return 1;
        }

        // After entering a correct value, the scanMatrix function is called in order to receive the graph values from the user

        scanMtraix(adjMatrix, numOfVertix);

        // Running the Dijkstra algorithm

        dijkstra(adjMatrix, numOfVertix, 1);
    }

    return 0;
}
