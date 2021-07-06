class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
        while(true)
        {
            if(pq.size()==0)
            {
                return 0;
            }
            if(pq.size()==1)
            {
                return pq.top();
            }
            int a = 0;
            a = pq.top();
            pq.pop();
            if(a==pq.top())
            {
                pq.pop();
            }
            else
            {
                int temp = abs(a - pq.top());
                pq.pop();
                pq.push(temp);
            }
            
        }
        return pq.top();
    }
};
