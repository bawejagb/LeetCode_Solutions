class Solution {
    queue<pair<int,int>> qt;
    int res;
    void dfs(vector<vector<int>> &grid, int a, int b){
        if(a<0||b<0||a==grid.size()||b==grid.size()) return;
        if(grid[a][b]!=1) return;
        grid[a][b]=2;
        dfs(grid,a-1,b);
        dfs(grid,a+1,b);
        dfs(grid,a,b-1);
        dfs(grid,a,b+1);
    }
    void bfs(vector<vector<int>>& grid){
        int n=grid.size();
        while(!qt.empty()){
            int m = qt.size();
            res++;
            while(m--){
                auto pr = qt.front();
                qt.pop();
                int a,b;
                a = pr.first;
                b = pr.second;
                grid[a][b]=3;
                if(a<n-1&&grid[a+1][b]==0){
                    qt.push({a+1,b});
                    grid[a+1][b]=3;
                }
                else if(a<n-1&&grid[a+1][b]==2) return;
                if(b<n-1&&grid[a][b+1]==0){
                    qt.push({a,b+1});
                    grid[a][b+1]=3;
                }
                else if(b<n-1&&grid[a][b+1]==2) return;
                if(a>0&&grid[a-1][b]==0){
                    qt.push({a-1,b});
                    grid[a-1][b]=3;
                }
                else if(a>0&&grid[a-1][b]==2) return;
                if(b>0&&grid[a][b-1]==0){
                    qt.push({a,b-1});
                    grid[a][b-1]=3;
                }
                else if(b>0&&grid[a][b-1]==2) return;
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool fg=0;
        res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(fg&&grid[i][j]==1){
                   qt.push({i,j});
               }
               else if(grid[i][j]==1){
                    dfs(grid,i,j);
                    fg=1;
                }
                    
            }
        }
        bfs(grid);
        return res-1;
    }
};