class Solution {
    int solve(vector<vector<int>>& grid, int r, int c, int m, int n){
        if(r==m) return c;
        if(c==0 and grid[r][c]==-1) return -1;
        if(c==n-1 and grid[r][c]==1) return -1;
        if(grid[r][c]==1 and grid[r][c+1]==-1) return -1;
        if(grid[r][c]==-1 and grid[r][c-1]==1) return -1;
        if(grid[r][c]==1) return solve(grid,r+1,c+1,m,n);
        return solve(grid,r+1,c-1,m,n);
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i] = solve(grid, 0,i, m,n);
        }
        return res;
    }
};