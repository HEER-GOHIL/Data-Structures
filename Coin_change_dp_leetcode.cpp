class Solution {
public:
    int coinChange(vector<int>& v, int amt) {
    vector<double>dp(amt+1,INT_MAX);
    dp[0] = 0;
    sort(v.begin(),v.end());
    for(int i=1;i<=amt;i++)
    {
        for(auto c:v)
        {
            if(c<=i)
            {
                  dp[i] = min(dp[i],dp[i - c] + 1);
            }
        }
    }
        return dp.back()==INT_MAX?-1:dp.back();
    }
};
