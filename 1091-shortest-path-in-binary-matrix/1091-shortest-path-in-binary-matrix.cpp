class Solution {
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n,vector<bool>(n,false));
        queue<pair<int,int>> qt;
        //dx and dy in anticlock from top left
        int dx[8] = {-1,-1,-1,0,1,1,1,0};
        int dy[8] = {-1,0,1,1,1,0,-1,-1};
        qt.push({0,0});
        int a,b,na,nb, res = 0;
        if(grid[0][0]||grid[n-1][n-1]) return -1;
        visit[0][0]=1;
        while(!qt.empty()){
            int sz = qt.size();
            res++;
            while(sz--){
                auto [a,b] = qt.front();
                qt.pop();
                if(a==n-1&&b==n-1) return res;
                for(int i=0;i<8;i++){
                    na = a + dx[i];
                    nb = b + dy[i];
                    if(na<0||nb<0||na>=n||nb>=n||visit[na][nb]||grid[na][nb]) continue;
                    qt.push({na,nb});
                    visit[na][nb]=1;
                }
            }
        }
        return -1;
    }
};