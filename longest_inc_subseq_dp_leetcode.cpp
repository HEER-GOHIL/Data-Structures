class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        dp[0] = 1;
        int retvalue = 1;
        for(int i=1;i<nums.size();i++)
        {
            int nmax = INT_MIN;
            int curr = nums[i];
            for(int j=0;j<i;j++)
            {
                if(nums[j]<curr && dp[j]>=nmax)
                {
                    nmax = dp[j] + 1;
                }
            }
            if(dp[i]<nmax)
            {
            dp[i] = nmax;
            }
            if(nmax>retvalue)
            {
                retvalue = nmax;
            }
        }
        return retvalue;
    }
};
