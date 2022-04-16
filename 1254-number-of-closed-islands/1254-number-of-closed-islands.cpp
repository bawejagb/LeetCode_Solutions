class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||j==0||i==n-1||j==m-1)&&grid[i][j]==0){
                    queue<pair<int,int>> qt;
                    qt.push({i,j});
                    while(!qt.empty()){
                        auto p = qt.front();
                        qt.pop();
                        int a = p.first;
                        int b = p.second;
                        grid[a][b] = 2;
                        if(a>0&&grid[a-1][b]==0) qt.push({a-1,b});
                        if(a<n-1&&grid[a+1][b]==0) qt.push({a+1,b});
                        if(b>0&&grid[a][b-1]==0) qt.push({a,b-1});
                        if(b<m-1&&grid[a][b+1]==0) qt.push({a,b+1});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    res++;
                    queue<pair<int,int>> qt;
                    qt.push({i,j});
                    while(!qt.empty()){
                        auto p = qt.front();
                        qt.pop();
                        int a = p.first;
                        int b = p.second;
                        grid[a][b] = 2;
                        if(a>0&&grid[a-1][b]==0) qt.push({a-1,b});
                        if(a<n-1&&grid[a+1][b]==0) qt.push({a+1,b});
                        if(b>0&&grid[a][b-1]==0) qt.push({a,b-1});
                        if(b<m-1&&grid[a][b+1]==0) qt.push({a,b+1});
                    }
                }
            }
        }
        return res;
    }
};