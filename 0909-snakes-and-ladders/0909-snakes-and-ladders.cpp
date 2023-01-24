class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> qt;
        qt.push(1);
        vector<int> dp(n*n+1,-1);
        vector<bool> visit(n*n+1,0);
        int steps=0;
        dp[1]=0;
        while(!qt.empty()){
            int cur,pos = qt.front();
            qt.pop();
            visit[pos]=1;
            cur = pos;
            for(int i=1;i<=6&&i<=n*n-cur;i++){
                pos = cur+i;
                int r,c;
                r = n-1- (pos-1)/n;
                c = ((pos-1)/n)%2? n-1-(pos-1)%n:(pos-1)%n;
                if(board[r][c]!=-1){
                    pos = board[r][c];
                }
                if(visit[pos]) continue;
                qt.push(pos);
                visit[pos]=1;
                dp[pos]=dp[cur]+1;
            }
        }
        return dp[n*n];
    }
};