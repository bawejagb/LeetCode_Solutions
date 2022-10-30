class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> remain_k(m, vector<int>(n,-1));
        queue<array<int,4>> q;
        q.push({0,0,0,k});
        while(q.size()) {
            auto [x,y,dist,cur_k] = q.front(); q.pop();
            if(x < 0 || y < 0 || x >= m || y >= n)
                continue;
            if(x  == m-1 and y == n-1)
                return dist;
            if(grid[x][y]) {
                if(cur_k) cur_k--;
                else continue;
            }
            if(remain_k[x][y] != -1 and remain_k[x][y] >= cur_k)
                continue;
            remain_k[x][y] = cur_k;
            
            q.push({x+1, y, dist+1, cur_k});
            q.push({x-1, y, dist+1, cur_k});
            q.push({x, y+1, dist+1, cur_k});
            q.push({x, y-1, dist+1, cur_k});
        }
        return -1;
    }
};