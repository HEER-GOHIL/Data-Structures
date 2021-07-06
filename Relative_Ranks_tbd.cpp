class Solution {
public:
   vector<string> findRelativeRanks(vector<int>& score) 
    {
        priority_queue<pair<int,int>> p;
        
        for(int i=0;i<score.size();i++)
        {
            p.push({score[i],i});
        }
        
        vector<string> v(score.size());
        string s;
        for(int i=0;i<score.size();i++)
        {
            if(i<3)
            {
                switch(i)
                {
                    case 0:
                        s="Gold Medal";
                        break;
                    case 1:
                        s="Silver Medal";
                        break;
                    case 2:
                        s="Bronze Medal";
                        break;
                }
            }
            
            else s=to_string(i+1);

            v[p.top().second]=s;
            p.pop();
            
        }
        
        return v;
        
    }
};
// Not my code :')
