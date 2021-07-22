class Solution {
public:
    int maxSubArray(vector<int>& v) {
    int maxsofar = v[0];
    int n = v.size();
    vector<int>dp(n);
    dp[0] = v[0];
    for(int i=1;i<n;i++)
    {
        dp[i] = max(dp[i-1] + v[i],v[i]);
        maxsofar = max(maxsofar,dp[i]);
    }
    return maxsofar;
    }
};
