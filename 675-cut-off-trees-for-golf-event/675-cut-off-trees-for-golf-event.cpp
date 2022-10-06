
class Solution {
    int bfs(int src, int dest, vector<vector<int>> &forest, int m, int n) {
        if(src==dest) return 0;
        bool visited[52*52]{};
        int dist = 0;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty()) {
            int size = q.size();
            dist++;
            for (int i = 0; i < size; i++) {
                int x = q.front() / m;
                int y = q.front() % m;
                q.pop();
                if (x > 0 && !visited[(x - 1) * m + y] && forest[x - 1][y]) {
                    visited[(x - 1) * m + y] = true;
                    q.push((x - 1) * m + y);
                    if ((x - 1) * m + y == dest) return dist;
                }
                if (y > 0 && !visited[(x)*m + y - 1] && forest[x][y - 1]) {
                    visited[(x)*m + y - 1] = true;
                    q.push((x)*m + y - 1);
                    if ((x)*m + y - 1 == dest) return dist;
                }
                if (x < n - 1 && !visited[(x + 1) * m + y] && forest[x + 1][y]) {
                    visited[(x + 1) * m + y] = true;
                    q.push((x + 1) * m + y);
                    if ((x + 1) * m + y == dest) return dist;
                }
                if (y < m - 1 && !visited[(x)*m + y + 1] && forest[x][y + 1]) {
                    visited[(x)*m + y + 1] = true;
                    q.push((x)*m + y + 1);
                    if ((x)*m + y + 1 == dest) return dist;
                }
            }
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>> &forest) {
        vector<pair<int, int>> pos;
        int n = forest.size();
        int m = forest[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (forest[i][j] > 1) pos.push_back({forest[i][j], i * m + j});
            }
        }
        pos.push_back({0, 0});
        sort(pos.begin(), pos.end());
        int res = 0;
        for (int i = 0; i < pos.size() - 1; i++) {
            int temp = bfs(pos[i].second, pos[i + 1].second, forest, m, n);
            if (temp == -1) return -1;
            res += temp;
        }
        return res;
    }
};