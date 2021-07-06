class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //using the minimum heap (pq) to get the largest two values
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            if(pq.size()>=2 && pq.top()<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
            else if(pq.size()<2)
            {
                pq.push(nums[i]);
            }
        }
        int ans = 1;
        while(!pq.empty())
        {
            ans = ans*(pq.top()-1);
            pq.pop();
        }
        return ans;
    }
};
