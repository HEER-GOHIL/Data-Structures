class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {
                nums[i] = 51;
                c++;
            }
        }
        sort(nums.begin(),nums.end());
        return nums.size()-c;
    }
};
