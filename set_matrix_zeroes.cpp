class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>>cor;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    vector<int>v;
                    v.push_back(i);
                    v.push_back(j);
                    cor.push_back(v);
                }
            }
        }
        int r2 = cor.size();
        for(int i=0;i<r2;i++)
        {
            for(int k=0;k<c;k++)
            {
                matrix[cor[i][0]][k] = 0;
            }
            for(int k=0;k<r;k++)
            {
                matrix[k][cor[i][1]] = 0;
            }
        }
    }
};
