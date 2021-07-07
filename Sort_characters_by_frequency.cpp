class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto [a,b] : mp)
        {
            pq.push({b,a});
        }
        s = "";
        while(!pq.empty())
        {
            s = s + string(pq.top().first , pq.top().second);
            pq.pop();
        }
        return s;
    }
};
