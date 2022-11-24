class Solution {
    void dfs(vector<vector<char>>&board, int m, int n, int x, int y){
    if(x<0||y<0 ||x==m || y==n || board[x][y]!='X') return;
        board[x][y] = '.';
    dfs(board, m, n, x+1,y);
    dfs(board, m, n, x,y+1);
}
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    dfs(board, m,n, i,j);
                    res++;
                }
            }
        }
        return res;
    }
};