class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c, int idx){
        if(r<0||r==grid.size()||c<0||c==grid.size()||grid[r][c]!=1) return 0;
        int row[] = {-1,0,1,0};
        int col[] = {0,-1,0,1};
        grid[r][c]=idx;
        int cnt = 1;
        for(int i=0;i<4;i++){
            int rr = r+row[i];
            int cc = c+col[i];
            cnt += dfs(grid, rr, cc, idx);
        }
        return cnt;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int area[250002]{};
        int idx = 2;
        int res=1;
        int row[] = {-1,0,1,0};
        int col[] = {0,-1,0,1};
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1){
                    area[idx]=dfs(grid,r,c,idx);
                    idx++;
                }
            }
        }
        for(int i=2;i<=idx;i++) res = max(res, area[i]);
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0){
                    set<int> hset;
                    for(int i=0;i<4;i++){
                        int rr = r+row[i];
                        int cc = c+col[i];
                        if(rr<0||rr==grid.size()||cc<0||cc==grid.size()) continue;
                        hset.insert(grid[rr][cc]);
                    }
                    int total = 1;
                    for(auto id : hset){
                        total += area[id];
                    }
                    res = max(res, total);
                }
            }
        }
        return res;
    }
};