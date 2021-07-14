class Solution {
public:
    int countBalls(int low, int high) {
        unordered_map<int,int>mp;
        for(int i=low;i<=high;i++)
        {
            int dupi = i;
            int sum = 0;
            while(dupi!=0)
            {
                sum = sum + dupi%10;
                dupi = dupi/10;
            }
            mp[sum]++;
        }
        int max = 0;
        for(auto x:mp)
        {
            if(x.second>max)
            {
                max = x.second; 
            }
        }
        return max;
    }
};
