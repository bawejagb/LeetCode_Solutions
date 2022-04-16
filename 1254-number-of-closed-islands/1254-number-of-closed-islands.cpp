class Solution {
    void dfs(vector<vector<int>>&grid,int i, int j,int &flag){
        if(i<1 || j<1||i>=grid.size()-1|| j>=grid[0].size()-1)
        {
            if(i==0 || j==0||i==grid.size()-1 ||j==grid[0].size()-1)
                if(grid[i][j]==0)
                    flag=1;
            return;
        }
        if(grid[i][j]==1 || grid[i][j]==2)
            return;
        
        grid[i][j]=2;
        
        dfs(grid,i+1,j,flag);
        dfs(grid,i-1,j,flag);
        dfs(grid,i,j+1,flag);
        dfs(grid,i,j-1,flag);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int cnt =0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                int flag=0;
                if(grid[i][j]==0)
                {
                    dfs(grid,i,j,flag);
                    if(flag==0)
                        cnt++;
                }
            }
        }
        
        return cnt;
    }
};