class Solution {
    int bfs(vector<vector<int>>& grid, int a, int b){
        int res = 1;
        grid[a][b] = 0;
        if(a>0 && grid[a-1][b] == 1)
            res += bfs(grid,a-1,b);
        if(b>0 && grid[a][b-1] == 1)
            res +=bfs(grid,a,b-1);
        if(a < grid.size()-1 && grid[a+1][b] == 1)
            res += bfs(grid,a+1,b);
        if(b < grid[0].size()-1 && grid[a][b+1] == 1)
            res += bfs(grid,a,b+1);
        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m,n;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==1){
                    res = max(res, bfs(grid,i,j));
                }
            }
        }
        return res;
    }
};