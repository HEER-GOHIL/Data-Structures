#include<bits/stdc++.h>
using namespace std;
class graph {
    int V;
    list<int>*adjv;
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
    list<int>adjlist = adjv[strt];
    cout<<strt<<" ";
    for(auto i = adjlist.begin();i!=adjlist.end();i++)
    {
        if(!visited[*i])
        {
            dfs(*i);
        }
    }

}
int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,3);
    g.dfs(0);

    return 0;
}