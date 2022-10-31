class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n = grid.size();
        pq.push({grid[0][0],{0,0}});
        int time=0;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        vector<vector<bool>> visit(n,vector<bool>(n,false));
        visit[0][0] = true;
        while(!pq.empty()){
            int curTime = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            time = max(time,curTime);
            if(x==n-1 and y==n-1) break;
            pq.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0||ny<0||nx==n||ny==n||visit[nx][ny]) continue;
                visit[nx][ny]=true;
                pq.push({grid[nx][ny],{nx,ny}});
            }
        }
        return time;
    }
};