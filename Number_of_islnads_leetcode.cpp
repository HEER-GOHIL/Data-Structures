class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count = count + 1;
                    callbfs(grid,i,j);
                }
            }
        }
        return count;
    }
    void callbfs(vector<vector<char>>&grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0')
        {
            return;
        }
        grid[i][j] = '0';
        callbfs(grid,i+1,j);
        callbfs(grid,i,j+1);
        if(i-1>=0 && j>=0)
        {
        callbfs(grid,i-1,j);
        }
        if(j-1>=0 && i>=0)
        {
        callbfs(grid,i,j-1);
        }

    }
};
