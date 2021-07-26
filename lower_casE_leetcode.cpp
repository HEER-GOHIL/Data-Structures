class Solution {
public:
    string toLowerCase(string s) {
        // a = 97
        // A = 65 - 90
        for(int i =0; i<s.length();i++)
        {
            if(int(s[i])>=65 && int(s[i])<=90)
            {
                s[i] = char(int(s[i]) + 32); 
            }
        }
        return s;
            
    }
};
