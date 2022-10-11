class Solution {
    bool isSafe(vector<vector<char>>& board, int a, int b, char val){
        for(int i=0;i<9;i++){
            if(board[i][b]==val || board[a][i]==val) return false;
        }
        int sa = a - a%3;
        int sb = b - b%3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[sa+i][sb+j]==val) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k = '1'; k<= '9'; k++){
                        if(isSafe(board, i,j,k)){
                            board[i][j] = k;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};