class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;//max heap
        vector<string>v;
        for(int i=0;i<score.size();i++)
        {
            pq.push({score[i],i});
        }
        for(int j=0;j<score.size();j++)
        {
            int i = pq.top().second;
            if(j<3)
            {
            if(j==0)
            {
                v[i] = "Gold Medal";
                break;
            }
            else if(j==1)
            {
                v[i] = "Silver Medal";
                break;
            }
            else
            {
                v[i] = "Bronze Medal";
                break;
            }
            }

                else v[i] = to_string(j+1);

            pq.pop();
        }
        return v;
    }
};
