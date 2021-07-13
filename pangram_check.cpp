class Solution {
public:
    bool checkIfPangram(string sentence) {
        // check pangram
        //every letter appears atleast once
        map<char,int>mp; //will store the count of the alphabets and it's occurence val
        for(auto x:sentence)
        {
            mp[x]++;
        }
        int j=0;
        for(auto i:mp)
        {
            j++;
            if(i.first == 0)
            {
                return false;
            }
            else
            {
                continue;
            }
            j++;
        }
        cout<<j;
        if(j==26)
        {
        return true;
        }
        return false;
    }
};
