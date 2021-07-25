class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while(x!=0)
        {
            int pop = x%10;
            x/=10;
            if(num > INT_MAX/10 || (num == INT_MAX/10 && pop >7))
            {
                return 0;
            }
            else if(num < INT_MIN/10 || (num == INT_MIN/10 && pop <-8))
            {
                return 0;
            }
            else
            {
            num = num*10 + pop;
            }
        }
        return num;
    }
};
