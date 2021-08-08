class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='a' || s[i]=='u'|| s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='A' || s[i]=='U')
            {
                v.push_back(s[i]);
            }
        }
        int n = v.size();
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='a' || s[i]=='u'|| s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='A' || s[i]=='U')
            {
                s[i] = v[n-1];
                n--;
            }
        }
        return s;
    }
};
