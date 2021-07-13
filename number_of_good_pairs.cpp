class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int gpair=0;
        for(auto i:mp)
        {
            int n = i.second;
            gpair = gpair + n*(n-1)/2;
        }
        return gpair;
    }
};
