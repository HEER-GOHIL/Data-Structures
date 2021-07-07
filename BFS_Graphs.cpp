#include <iostream>
#include <list>
#include<queue>
using namespace std;
class graph
{
  int numvertices;
  list<int>* adjlist;
  bool* visited;
  public:
  graph(int numvertices);
  void addedge(int u, int v);
  void bfs(int origin);
};
graph::graph(int v)
{
    numvertices = v;
    adjlist = new list<int>[v];
}
void graph::addedge(int u, int v)
{
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}
void graph::bfs(int origin)
{
    visited = new bool[numvertices];
    for(int i=0;i<numvertices;i++)
    {
        visited[i] = false;
    }
    queue<int>q;
    visited[origin] = true;
    q.push(origin);
    list<int>::iterator i;
    while(!q.empty())
    {
        int curvertex = q.front();
        cout<<curvertex<<" ";
        q.pop();
        for(i = adjlist[curvertex].begin();i!=adjlist[curvertex].end();++i)
        {
            int adjvertex = *i;
            if(!visited[adjvertex])
            {
                visited[adjvertex]= true;
                q.push(adjvertex);
            }
        }
    }
}
int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    g.bfs(2);

    return 0;
}
// reference  - https://www.programiz.com/dsa/graph-bfs
