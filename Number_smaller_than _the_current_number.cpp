class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int>mp; //use map to add the integers and it's count
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        int sum = 0;
        int temp = 0;
        for(auto &i:mp)
        {
            temp = i.second;
            i.second = sum;
            sum = sum + temp;
        }
        int i= 0;
        while(i!=nums.size())
        {
            nums[i] = mp[nums[i]];
            i++;
        }
        return nums;
    }
};
