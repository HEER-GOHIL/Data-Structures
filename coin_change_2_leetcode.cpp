class Solution {
public:
    int change(int sum, vector<int>& v) {
        int size = v.size();
         int dp[size+1][sum+1];

    for(int i=0;i<=sum;i++)
    {
        dp[0][i] = 0;
    }
    for(int i=0;i<=size;i++)
    {
        dp[i][0] = 1;
    }
    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j >= v[i-1])
            {
            dp[i][j] = dp[i-1][j] + dp[i][j-v[i-1]];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[size][sum];
    }
};
