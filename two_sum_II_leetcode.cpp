class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int a_pointer = 0;
        int b_pointer = num.size() - 1;
        while(a_pointer<=b_pointer)
        {
            int sum = num[a_pointer] + num[b_pointer];
            if(sum>target)
            {
               b_pointer--;   
            }
            else if(sum<target)
            {
                a_pointer++;
            }
            else
            {
                return {a_pointer + 1,b_pointer+1};;
            }
        }
        return {a_pointer + 1,b_pointer+1};;
    }
};
