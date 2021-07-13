class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>decode{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<int,string>mp;
        map<string,int>out;
        for(int i=1;i<=decode.size();i++)
        {
            mp[i] = decode[i-1];
        }
        for(int i=0;i<words.size();i++)
        {
            string curr = words[i];
            string res = "";
            for(auto j:curr)
            {
                res = res + mp[int(j)-96];
            }
            out[res]++;
        }
        int ret = 0;
        for(auto x:out)
        {
            ret++;
        }
        return ret;
    }
};
