#include<bits/stdc++.h>
using namespace std;
int main()
{
    //finding the pair 
    vector<int>v {1,5,7,20,45,12,87,47};
    int t;
    cin>>t; //target value
    //sort the vector
    sort(v.begin(),v.end());
    //1 5 7 12 20 45 47 87
    for(int i=0;i<v.size();i++)
    {
        for(int j=i;j<v.size();j++)
        {
            int diff = abs(v[j] -v[i]);
            if(diff == t)
            {
                cout<<v[j]<<" "<<v[i]<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;
    return 0;
}