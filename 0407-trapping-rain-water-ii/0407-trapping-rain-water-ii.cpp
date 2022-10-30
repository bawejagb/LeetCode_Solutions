class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int R = heightMap.size();
        int C = heightMap[0].size();
        int volume=0; 
        vector<vector<bool>> visit(R,vector<bool>(C,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(i==0||j==0||i==R-1||j==C-1){
                    pq.push({heightMap[i][j],{i,j}});
                    visit[i][j]=true;
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int maxHt = 0;
        while(!pq.empty()){
            int ht = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            maxHt = max(maxHt,ht);
            pq.pop();
            for(int i=0;i<4;i++){
                int nx = r+dx[i];
                int ny = c+dy[i];
                if(nx<0||ny<0||nx==R||ny==C || visit[nx][ny]) continue;
                visit[nx][ny]=true;
                if(heightMap[nx][ny]<maxHt) volume+=(maxHt-heightMap[nx][ny]);
                pq.push({heightMap[nx][ny],{nx,ny}});
            }
        }
        return volume;
    }
};