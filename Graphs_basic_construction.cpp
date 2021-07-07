#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>AM[], int u, int v)
{
    AM[u].push_back(v);
    AM[v].push_back(u);
}
void printgraph(vector<int>AM[],int V)
{
    
    for(int i=0;i<V;++i)
    {
        cout<<"For Node : "<<i<<" :";
        for(auto j : AM[i])
        {
            cout<<"->"<<j;
        }
        cout<<endl;
    }
}
int main()
{
    int V = 5; //number of vertices
    vector<int>AM[V]; //adjacent matrix with 5 rows
    // add edges 
    addEdge(AM, 0, 1);
    addEdge(AM, 0, 4);
    addEdge(AM, 1, 2);
    addEdge(AM, 1, 3);
    addEdge(AM, 1, 4);
    addEdge(AM, 2, 3);
    addEdge(AM, 3, 4);
    printgraph(AM, V);
    
    return 0;
}
