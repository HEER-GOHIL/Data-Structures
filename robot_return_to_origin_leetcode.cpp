class Solution {
public:
    bool judgeCircle(string s) {
        int arr[2];
        arr[1] = 0;
        arr[0] = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='U')
            {
                arr[0]++;
            }
            if(s[i]=='D')
            {
                arr[0]--;
            }
            if(s[i]=='R')
            {
                arr[1]++;
            }
            if(s[i]=='L')
            {
                arr[1]--;
            }
        }
        if(arr[0]!=0 || arr[1]!=0)
        {
            return false;
        }
        return true;
    }
};
