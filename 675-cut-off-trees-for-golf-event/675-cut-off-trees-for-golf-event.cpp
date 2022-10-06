
class Solution {
    struct Tree{
      int val,x,y;  
    };
    static bool comp(const Tree &a,const Tree &b){
        return a.val < b.val;
    }
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int bfs(int x1,int y1, int x2, int y2, vector<vector<int>> &forest){
        int m = forest.size();
        int n = forest[0].size();
        bool visit[52][52]{};
        queue<pair<int,int>> qt;
        int level = 0;
        qt.push({x1,y1});
        while(!qt.empty()){
            int size = qt.size();
            while(size--){
                auto node = qt.front();
                qt.pop();
                int x = node.first;
                int y = node.second;
                if(x==x2 and y==y2) return level;
                if(visit[x][y]) continue;
                visit[x][y] = true;
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=0 and ny >= 0 and nx <m and ny <n and !visit[nx][ny] and forest[nx][ny]) qt.push({nx,ny});
                }
            }
            level++;
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        vector<Tree> nodes;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j]>1)
                    nodes.push_back({forest[i][j],i,j});
            }
        }
        nodes.push_back({0,0,0});
        sort(nodes.begin(),nodes.end(),comp);
        int ans=0;
        for(int i=0;i<nodes.size()-1;i++){
            int val = bfs(nodes[i].x,nodes[i].y,nodes[i+1].x,nodes[i+1].y, forest);
            if(val < 0) return -1;
            ans += val;
        }
        return ans;
    }
};