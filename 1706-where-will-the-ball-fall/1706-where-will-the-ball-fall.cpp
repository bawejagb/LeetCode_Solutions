class Solution {
    int solve(vector<vector<int>>& grid, int r, int c){
        if (r == grid.size()) return c;
        int nextColumn = c + grid[r][c];
        if (nextColumn < 0 || nextColumn > grid[0].size() - 1 ||
            grid[r][c] != grid[r][nextColumn]) {
            return -1;
        }
        return solve(grid, r + 1, nextColumn );
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i] = solve(grid, 0,i);
        }
        return res;
    }
};