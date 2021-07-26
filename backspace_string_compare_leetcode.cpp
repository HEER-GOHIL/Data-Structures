class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char>v1;
        vector<char>v2;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='#')
            {
                v1.push_back(s[i]);
            }
            else
            {
                if(v1.size()!=0)
                {
                v1.pop_back();
                }
            }
        }
        for(int i=0;i<t.length();i++)
        {
            if(t[i]!='#')
            {
                v2.push_back(t[i]);
            }
            else
            {
                if(v2.size()!=0)
                {
                v2.pop_back();
                }
            }
        }
        if(v1==v2)
        {
            return true;
        }
        return false;
    }
};
