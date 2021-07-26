class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>v;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>=48 && s[i]<=57) ||(s[i]>=65 && s[i]<=90)|| (s[i]>=97 &&s[i]<=122))
            {
                if(s[i]>=97)
                {
                v.push_back(char(int(s[i]) -32));
                }
                else
                {
                    v.push_back(s[i]);
                }
                cout<<s[i]<<" ";
            }
            else
            {
                continue;
            }
        }
        vector<char>dupv = v;
        reverse(v.begin(),v.end());
        if(v == dupv)
        {
            return true;
        }
        return false;
        
    }
};
