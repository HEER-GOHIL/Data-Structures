#include<bits/stdc++.h>
#include<iostream>
#include<list>
using namespace std;
class HASH{
    int bucket;
    list<int>*table;
    public:
    HASH(int v);
    void insertitem(int x);
    void deleteitem(int key);
    void displayhash();
    int hashf(int x)
    {
        return (x%bucket);
    }
};
HASH::HASH(int b)
{
    this->bucket = b;
    table = new list<int>[bucket];
}
void HASH::insertitem(int data)
{
    int index = hashf(data); //returns the index at which the data is to inserted
    table[index].push_back(data);
}
void HASH::deleteitem(int key)
{
    int index = hashf(key);
    list<int>::iterator i;
    for(i=table[index].begin();i!=table[index].end();i++)
    {
        if(*i==key)
        {
            break;
        }
    }
    if(i!=table[index].end())
    {
        table[index].erase(i);
    }
}
void HASH::displayhash()
{
    for(int i=0;i<bucket;i++)
    {
        cout<<i;
        for(auto x:table[i])
        {
            cout<<"-->"<<x;
        }
        cout<<endl;
    }
}
int main()
{
    int arr[] = {1,4,7,56,34,23,89,76,34,88,62,85,17,56};
    int size = sizeof(arr)/sizeof(arr[0]);
    HASH h (6);
    for(int i=0;i<size;i++)
    {
        h.insertitem(arr[i]);
    }
    h.displayhash();
    h.deleteitem(76);
    h.deleteitem(34);
    cout<<"After Deletion"<<endl;
    h.displayhash();
    return 0;
}
