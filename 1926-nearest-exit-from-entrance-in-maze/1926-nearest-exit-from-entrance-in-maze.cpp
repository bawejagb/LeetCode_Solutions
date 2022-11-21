class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int steps = 0;
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>> qt;
        qt.push({entrance[0],entrance[1]});
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!qt.empty()){
            int size = qt.size();
            while(size--){
                auto pos=qt.front();
                qt.pop();
                int x = pos.first;
                int y = pos.second;
                if(x==0 || y==0 || x==m-1 || y==n-1){
                    if(x!=entrance[0] || y != entrance[1])
                        return steps;
                }
                maze[x][y] = '+';
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx<0||ny<0||nx==m||ny==n||maze[nx][ny]!='.') continue;
                    qt.push({nx,ny});
                    maze[nx][ny] = '+';
                }
            }
            steps++;
        }
        return -1;
    }
};