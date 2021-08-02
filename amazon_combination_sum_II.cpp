class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cnd, int target)     {
        sort(cnd.begin(),cnd.end()); //sorted
        vector<vector<int>>result;
        vector<int>temp;
        findcombinations(cnd,0,target,temp,result);
        return result;
    }
    void findcombinations(vector<int>cnd,int index,int target,vector<int>& curr,vector<vector<int>>& result)
    {
        if(target==0)
        {
            result.push_back(curr);
            return;
        }
        if(target<0)
        {
            return;
        }
        for(int i=index;i<cnd.size();i++)
        {
            if(i==index || cnd[i]!=cnd[i-1])
            {
                curr.push_back(cnd[i]);
                findcombinations(cnd,i+1,target - cnd[i],curr,result);
                curr.pop_back();
            }
        }
    }
};
