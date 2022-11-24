class Solution {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool check(vector<vector<char>>&board, string word, int m, int n, int x, int y, int idx){
        if(idx==word.size()) return true;
        char c = board[x][y];
        board[x][y] = '.';
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||ny<0||nx==m || ny==n || board[nx][ny]!=word[idx]) continue;
            if(check(board, word, m, n, nx, ny, idx+1)) return true;
        }
        board[x][y] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(check(board,word,m,n,i,j,1)) return true;
                }
            }
        }
        return false;
    }
};