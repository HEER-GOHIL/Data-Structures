class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() + 1;i++)
        {
            if(i<nums.size() && nums[i]!=i)
            {
                return i;
            }
            else if(i==nums.size())
            {
                return i;
            }
        }
        return 1;
    }
};

//---------------------second approach-------------------------
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = accumulate(nums.begin(), nums.end(), 0);
        int sum = n*(n+1)/2;
        return sum - x;
    }
};
