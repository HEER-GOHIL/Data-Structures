#include <iostream>
#include<bits/stdc++.h>
#include <list>
using namespace std;
class graph
{
public:
  unordered_map<string,list<pair<string,int>>> l;
  void addedge(string u, string v, bool bidirec, int wt);
  void printadjlist();
  
};
// add edges
void graph::addedge(string u, string v, bool bidirec, int wt)
  {
      l[u].push_back(make_pair(v,wt));
      if(bidirec)
      {
          l[v].push_back(make_pair(u,wt));
      }
  }
// printing the adjacent list
void graph::printadjlist()
{
    for(auto p:l)
    {
        string node = p.first;
        cout<<node<<": ";
        list<pair<string,int>> nbr = p.second;
        for(auto j:nbr)
        {
            cout<<j.first<<"("<<j.second<<") "; //the node and the weight
        }
        cout<<endl;
    }
}

int main()
{
    graph g; //create a graph with 4 vertices 
    g.addedge("A", "B",true,20);
    g.addedge("B","D",true,40);
    g.addedge("A","C",false,10);
    g.addedge("C","D",true,40);
    g.addedge("A","D",true,40);
    g.printadjlist();
    return 0;
}
