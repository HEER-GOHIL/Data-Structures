//Sort upto first k elements in 
//ascending order and remaining in descending order 
//remember to handle the corner cases of k>length of 
//array as in this case sort by ascending order entire array.
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k = 5;
    vector<int>v{7,2,5,4,1,9,6,3,8};
    int n = v.size();
    if(k>=n)
    {
        sort(v.begin(),v.end());
    }
    else
    {
    sort(v.begin(),v.begin()+k);
    sort(v.begin()+k,v.end());
    reverse(v.begin()+k,v.end());
    }
    for(int i=0;i<v.size();i++)
    {
	    cout<<v[i]<<" ";
    }
    return 0;
}
