class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_map<string,int>mp;
        int k = 0;
        for(int i=0;i<word.length();i++)
        {
            string str = "";
            if(int(word[i])>=48 && int(word[i])<=57)
            {
                while(int(word[i])>=48 && int(word[i])<=57)
                {
                    str = str + word[i];
                    i++;
                }
                k = 0;
                while (str[k] == '0')
                {
                k++;
                }
                str.erase(0, k);
                mp[str]++;
            }
            
        }
        k = 0;
        for(auto x:mp)
        {
            k++;
        }
        return k;
    }
};
