class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> v;
        int keys = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '@') v = {i, j, 0, 0};
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f') ++keys;
            }
        }
        int total_key = pow(2, keys) - 1;
        
        queue<vector<int> > q;
        q.push(v);
        vector<vector<bool> > visited(m * n, vector<bool>(total_key + 1, false));
        visited[v[0] * n + v[1]][0] = true;
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            // collecting all the keys, exit.
            if(p[2] == total_key) return p[3];
            
            for(int k=0; k<4; ++k) {
                int nx = p[0] + dx[k], ny = p[1] + dy[k];
                // out of bounds.
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                // position is wall.
                if(grid[nx][ny] == '#') continue;
                // position is a key.
                if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f') {
                    int key = grid[nx][ny] - 'a';
                    int new_key = p[2] | (1 << key);
                    if(!visited[nx * n + ny][new_key]) {
                        q.push({nx, ny, new_key, p[3] + 1});
                        visited[nx * n + ny][new_key] = true;
                    }
                // position is a lock, check if the matching key is available.
                } else if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F') {
                    int lock = grid[nx][ny] - 'A';
                    if(((1 << lock) & p[2]) && !visited[nx * n + ny][p[2]]) {
                        q.push({nx, ny, p[2], p[3] + 1});
                        visited[nx * n + ny][p[2]] = true;
                    }
                // position is empty.
                } else if(!visited[nx * n + ny][p[2]]) {
                    q.push({nx, ny, p[2], p[3] + 1});
                    visited[nx * n + ny][p[2]] = true;
                }
            }
        }
        
        return -1;
    }
};