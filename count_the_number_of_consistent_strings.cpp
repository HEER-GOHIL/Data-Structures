class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<int,int>mp;
        for(int i=0;i<allowed.length();i++)
        {
            mp[allowed[i]]++;
        }
        int retval = 0;
        for(int i=0;i<words.size();i++)
        {
            string curr = words[i];
            int v = 0; //checking how many number are same 
            for(auto j:curr)
            {
                if(mp[j]>0)
                {
                    v++;
                }
            }
            if(v==curr.length())
            {
                retval ++;
            }
        }
        return retval;
    }
};
