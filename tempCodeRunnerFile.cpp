#include<bits/stdc++.h>
using namespace std;
class graph {
    int V;
    list<int>adjv;
    bool *visited;
    public:
    graph(int V);
    void addedge(int src, int dest);
    void dfs(int startv);
};
graph::graph(int v)
{
    V = v;
    adjv = new list<int>[v];
    visited = new bool[v];
}
//add edge
void graph::addedge(int src, int dest)
{
    adjv[src].push_back(dest);
}
// dfs call
void graph::dfs(int strt)
{
    visited[strt] = true;
    ilst<int>adjv = adjv[V];
    cout<<strt<<" ";
    for(auto i = adjv.begin();i!=adjv.end();i++)
    {
        if(!visited[*i])
        {
            dfs(*i);
        }
    }

}
int main()
{
    graph g1(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,3);
    g.dfs(3);
    return 0;
}