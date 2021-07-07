class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int asize = arr.size(); 
        unordered_map<int,int>mp; //unordered map
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++ ;//counting the freq!
        }
        priority_queue<pair<int,int>>p;
        for(auto[k, i] : mp)
        {
            p.push({i,k});
        }
        int flag = 0;
        int ch = 0;
        int count = 0;
        while(flag!=1)
        {
            ch = ch + p.top().first;
            count ++;
            if(ch >=asize/2)
            {
                return count;
            }
            p.pop();
        }
        return 0;
    }
};
