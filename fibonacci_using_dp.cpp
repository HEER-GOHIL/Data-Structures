int dp[31];
class Solution {
public:
    int fib(int n) {
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        if(n>1)
        {
            getfib(n);
        }
        return dp[n];
    }
    int getfib(int n)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n] = getfib(n-1) + getfib(n-2);
    }
};
