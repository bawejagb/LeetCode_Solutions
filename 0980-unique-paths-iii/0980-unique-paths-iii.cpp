class Solution {
    int path=0;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void backtrack(vector<vector<int>>& grid, int a, int b, int cnt, int m, int n){
        for(int i=0;i<4;i++){
            int nx = dx[i]+a;
            int ny = dy[i]+b;
            if(nx<0||ny<0||nx==m||ny==n) continue;
            if(cnt==0 && grid[nx][ny]==2) path++;
            else if(grid[nx][ny]==0){
                grid[nx][ny]=-1;
                backtrack(grid,nx,ny,cnt-1,m,n);
                grid[nx][ny]=0;
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int empty=0;
        int m = grid.size();
        int n = grid[0].size();
        int a,b;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) empty++;
                else if(grid[i][j]==1) a=i,b=j;
            }
        }
        backtrack(grid,a,b,empty,m,n);
        return path;
    }
};