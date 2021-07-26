class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>mp;
        for(int i=0;i<trust.size();i++)
        {
                mp[trust[i][0]]--;   
                mp[trust[i][1]]++;
        }
        for(auto x:mp)
        {
            if(x.second==n-1)
            {
                return x.first;
            }
        }
        if(trust.size()==0 && n==1)
        {
            return 1;
        }
        return -1;
    }
};
