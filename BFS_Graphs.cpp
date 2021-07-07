#include <iostream>
#include <list>
#include<queue>
using namespace std;
class graph
{
  int numvertices;
  list<int>* adjlist; //adjacent matrix
  bool* visited; // to check if the node is already visited before or not 
  public:
  //functions which can be called by a class member
  graph(int numvertices); 
  void addedge(int u, int v);
  void bfs(int origin);
};
//declaring a graph
graph::graph(int v)
{
    numvertices = v; //setting the private member to value of num of vertices so that it can be called by other functions
    adjlist = new list<int>[v]; //create a list to store the adjacent matrix
}
//adding edges
void graph::addedge(int u, int v)
{
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  /*
  u  v
  |  |
  |  |
  v  v
  v  u
  */
}
void graph::bfs(int origin)
{
    visited = new bool[numvertices]; //vertex repetition checker
    for(int i=0;i<numvertices;i++)
    {
        visited[i] = false; //set all to false initially
    }
    queue<int>q; //queue :)
    visited[origin] = true; //the first node is visited
    q.push(origin); //push in the queue
    list<int>::iterator i; //iterator to iterate through the list
    while(!q.empty())
    {
        int curvertex = q.front(); //pop the first element and add it's adjacent 
        cout<<curvertex<<" "; 
        q.pop();
        for(i = adjlist[curvertex].begin();i!=adjlist[curvertex].end();++i) //iterate throught he sublist to find the adjacents
        {
            int adjvertex = *i; // set the iterator to the curr adjacent value
            if(!visited[adjvertex]) // is that node already visited?
            {
                visited[adjvertex]= true; // if not - set true and than push the same in the queue - now it has been visited :)
                q.push(adjvertex); //push it in the queue
            }
        }
    }
}
int main()
{
    graph g(4); //create a graph with 4 vertices 
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    g.bfs(2); //return bfs with 2 as origin :)

    return 0;
}

