class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        int retval = 0;
        int sum;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                sum = 0;
                if(grid[i][j]==1)
                {
                callbfs(grid,i,j,sum);
                if(sum>retval)
                    {
                    retval = sum;
                    }
                }
            }
            
        }
        return retval;
        
    }
    void callbfs(vector<vector<int>>& grid,int i, int j,int& sum)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0)
        {
            return;
        }
        sum ++;
        grid[i][j] = 0;

        callbfs(grid,i+1,j,sum);
        callbfs(grid,i,j+1,sum);
        if(i-1>=0)
        {
        callbfs(grid,i-1,j,sum);
        }
        if(j-1>=0)
        {
        callbfs(grid,i,j-1,sum);
        }
    }
};
