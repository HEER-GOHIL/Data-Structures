class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newc) {
        int curr = image[sr][sc];
        callbfs(image,sr,sc,newc,curr);
        return image;
        
    }
    void callbfs(vector<vector<int>>&image,int i,int j,int newc, int curr)
    {
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j]==newc)
        {
            return;
        }
        if(image[i][j]==curr)
        {
        image[i][j] = newc;
        callbfs(image,i+1,j,newc,curr);
        callbfs(image,i,j+1,newc,curr);
        if(i-1>=0 && j>=0)
        {
            callbfs(image,i-1,j,newc,curr);
        }
        if(j-1>=0 && i>=0)
        {
            callbfs(image,i,j-1,newc,curr);
        }
        }
    }
};
