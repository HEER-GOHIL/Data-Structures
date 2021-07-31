class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)     {
        int dist = 0;
        priority_queue<pair<int, pair<int, int>>>  pq;
        // distance and pair of points
        for(int i=0;i<points.size();i++)
        {
            dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            pq.push({dist,{points[i][0],points[i][1]}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        int i = 0;
        vector<vector<int>>ans;
        while(!pq.empty())
        {
             vector<int> r={pq.top().second.first, pq.top().second.second};
            ans.push_back(r);
            pq.pop();
        }
        return ans;
        
    }
};
