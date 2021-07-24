class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int dp[l1+1][l2+1];
        for(int i=0;i<=l1;i++)
        {
            dp[i][0] = i;
        }
        for(int i=0;i<=l2;i++)
        {
            dp[0][i] = i;
        }
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = findmin(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
                
            }
        }
        return dp[l1][l2];
    }
    int findmin(int a, int b,int c)
    {

        if(a<=b && a<=c)
        {
            return a;
        }
        if(b<=a && b<=c)
        {
            return b;
        }
        if(c<=a && c<=b)
        {
            return c;
        }
        return 0;
    }
};
