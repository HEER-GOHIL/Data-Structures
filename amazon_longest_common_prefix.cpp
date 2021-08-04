class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp  = "";
        if(strs.size()==0)
        {
            return lcp;
        }
        int index = 0;
        for(auto c:strs[0])
        {
            for(int i=1;i<strs.size();i++)
            {
                if(index>=strs[i].size() || c!=strs[i][index])
                {
                    return lcp;
                }
            }
            lcp +=c;
            index ++;
        }
        return lcp;
        
    }
};