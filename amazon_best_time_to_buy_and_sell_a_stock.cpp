class Solution {
public:
    int maxProfit(vector<int>& v) {
        int profit = 0;
        if(v.size()>1)
        {
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]<v[i+1])
            {
                profit = profit + (v[i+1] - v[i]);
            }
            if(v[i]>v[i+1])
            {
                continue;
            }
        }
        }
        return profit;
    }
};
