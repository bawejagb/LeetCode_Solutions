class Solution {
    void dfs(vector<vector<char>>& grid, int a, int b){
        grid[a][b]='2';
        if(a>0&& grid[a-1][b]=='1') dfs(grid, a-1,b);
        if(b>0&& grid[a][b-1]=='1') dfs(grid, a,b-1);
        if(a<grid.size()-1&&grid[a+1][b]=='1') dfs(grid, a+1,b);
        if(b<grid[0].size()-1&&grid[a][b+1]=='1') dfs(grid, a,b+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};