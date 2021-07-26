//Given two arrays A and B of positive integers, elements of array B can be mapped to
//elements of array A only if both the elements have same value. The task is to compute the 
//positions in array A to which elements of array B will be mapped. Print NA if mapping for 
//a particular element cannot be done.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,list<int>>mp;
    vector<int>a{1,2,3,4,5,6,7};
    vector<int>b{2,4,9,10};
    int as = a.size();
    int bs = b.size();
    for(int i=0;i<as;i++)
    {
        mp[a[i]].push_back(i);
    }
    for(int i=0;i<bs;i++)
    {
        if(mp.find(b[i])!= mp.end() && mp[b[i]].size()>0)
        {
            cout<<mp[b[i]].front()<<" ";
        }
        else
        {
            cout<<"NA"<<" ";
        }
    }
    
    return 0;
}
