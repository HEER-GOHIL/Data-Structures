// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        while(left<right)
        {
            int midpoint = left + (right - left)/2;
            if(isBadVersion(midpoint))
            {
                right = midpoint;
            }
            else
            {
                left = midpoint+1;
            }
        }
        if(left==right && isBadVersion(right))
        {
            return left;
        }
        return -1;
    }
};
