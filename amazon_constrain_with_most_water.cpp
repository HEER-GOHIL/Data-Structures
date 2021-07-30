// Time limited exceeded approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxa = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int minh = min(height[i],height[j]);
                maxa = max(maxa, minh*(j-i));
            }
        }
        return maxa;
    }

};

//optimized solution 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxh = INT_MIN;
        int i=0;
        int j = height.size()-1;
        while(i<j)
        {
            int minh = min(height[i],height[j]);
            maxh = max(maxh,minh*(j-i));
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxh;
    }

};
