class Solution {
    vector<string> grid_;
    vector<vector<vector<bool>>> visited;
    int H,W;
    bool border(int row, int col){
        return (row>=0&&row<H&&col>=0&&col<W);
    }
    void dfs(int row, int col, int type){
        if(!border(row, col) || visited[row][col][type]) return;
        visited[row][col][type] = true;
        switch (type){
            case 0:
                dfs(row-1,col,2);
                break;
            case 1:
                dfs(row,col+1,3);
                break;
            case 2:
                dfs(row+1,col,0);
                break;
            case 3:
                dfs(row,col-1,1);
                break;
        }
        if(grid_[row][col]!='/')
            dfs(row,col,type^1);
        if(grid_[row][col]!='\\')
            dfs(row,col,type^3);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        grid_ = grid;
        H = grid.size();
        W = grid[0].size();
        visited.clear();
        visited.resize(H,vector<vector<bool>>(W,vector<bool>(4,false)));
        int regions = 0;
        for(int i=0;i<H;i++){
           for(int j=0;j<W;j++){
               for(int k=0;k<4;k++){
                   if(visited[i][j][k]) continue;
                   dfs(i,j,k);
                   regions++;
               }
           } 
        }
        return regions;
    }
};