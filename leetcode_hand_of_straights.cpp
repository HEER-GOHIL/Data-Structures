class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        map<int,int>mp;
        for(auto x:hand)
        {
            mp[x]++;
        }
        int n=hand.size();
        for(int i=0;i<n;i++)
        {
            int num = hand[i];
            if(mp[num]==0)
            {
                continue;
            }
            for(int z=num;z<num+groupSize;z++)
            {
                mp[z]--;
                if(mp[z]<0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
