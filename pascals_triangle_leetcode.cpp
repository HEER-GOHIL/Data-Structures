class Solution {
public:
    vector<vector<int>> generate(int rows){
         vector<vector<int>>res = {{1}};
        while(--rows)
        {
            vector<int>temp(res.back().size()+1,1);
            for(int j=1;j<temp.size()-1;j++)
            {
                temp[j] = res.back()[j-1] + res.back()[j];
            }
            res.push_back(temp);
        }
        return res;
    }
};
