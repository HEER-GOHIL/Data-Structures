class Solution {
public:
    void nextPermutation(vector<int>& v) {
    int n = v.size();
    int i,k = -2;
    for(i=n-1 ; i>0 ;i--)
    {
        if(v[i]>v[i-1])
        {
            k = i-1;
            break;
        }
    }
    if(k==-2)
    {
        reverse(v.begin(),v.end());
        return;
    }
    int curr = v[k];
    int swappos = 0;
    int max  = INT_MAX;
    for(i=k;i<n;++i)
    {
        if(v[i]>=curr && v[i]<=max &&v[i]!=curr)
        {
            swappos = i;
            max = v[i];
        }
    }

    int temp = v[k];
    v[k] = v[swappos];
    v[swappos] = temp;
    //---
    reverse(v.begin()+k+1,v.end());
    }
};
