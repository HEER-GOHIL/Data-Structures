class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1);
        for(int i=1;i<=n;i++)
        {
            res[i] = (i%2==1?1:0) + res[i/2];
        }
        return res;
    }
};
