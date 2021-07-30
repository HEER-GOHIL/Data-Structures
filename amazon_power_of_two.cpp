class Solution {
public:
    bool isPowerOfTwo(int n) {
        long int l = 1;
        while(n!=l)
        {
            l = l*2;
            if(l>n)
            {
                return false;
            }
        }
        return true;
    }
};
