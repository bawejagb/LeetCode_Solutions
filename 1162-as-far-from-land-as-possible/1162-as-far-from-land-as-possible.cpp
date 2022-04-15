class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int res = -1;
        int n = grid.size();
        queue<pair<int,int>> qt;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    qt.push({i,j});
                }
            }
        }
        if(qt.size()==n*n||qt.empty()) return res;
        while(!qt.empty()){
            int s = qt.size();
            while(s--){
                auto p = qt.front();
                qt.pop();
                int a = p.first;
                int b = p.second;
                res = max(res,grid[a][b]);
                if(a+1<n&&!grid[a+1][b]) grid[a+1][b]=grid[a][b]+1, qt.push({a+1,b});
                if(a-1>=0&&!grid[a-1][b]) grid[a-1][b]=grid[a][b]+1, qt.push({a-1,b});
                if(b+1<n&&!grid[a][b+1]) grid[a][b+1]=grid[a][b]+1, qt.push({a,b+1});
                if(b-1>=0&&!grid[a][b-1]) grid[a][b-1]=grid[a][b]+1, qt.push({a,b-1});
            }
            
            
        }
        return res-1;
    }
};