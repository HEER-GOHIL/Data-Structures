/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<bits/stdc++.h>
#define V 9
//min distance funtion to find the min of the curr and new value
int findmindist(int dist[],bool sptset[])
{
    int min = INT_MAX, min_index; //to store the min value and it's index
    for (int v = 0; v < V; v++)
    {
        if (sptset[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    }
    return min_index;
}
// print dist arr
int printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d tt %d\n", i, dist[i]);
}
// main function
void dij(int graph[V][V], int src)
{
    int dist[V]; //holding all the shortest distances
    bool sptset[V]; // to check if the node is processed or not 
    //initial conditions
    for(int i=0;i<V;i++)
    {
        dist[i] = INT_MAX;
        sptset[i] = false;
    }
    dist[src] = 0;
    
    for(int i=0;i<V-1;i++) //iterate V-1 times - last node is the dest(default)
    {
        int u = findmindist(dist,sptset);
        sptset[u] = true;
        for(int v=0;v<V;v++)
        {
            if(!sptset[v] && graph[u][v] && dist[u]!=INT_MAX && (dist[u] + graph[u][v]) < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist,V);
}
int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dij(graph,0);
    return 0;
}
