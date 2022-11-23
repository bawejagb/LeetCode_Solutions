class Solution {
    bool checkBoard(vector<vector<char>>&board, char c, int i, int j){
        for(int k=0;k<9;k++){
            if(k==i) continue;
            if(board[k][j]==c) return false;
        }
        for(int k=0;k<9;k++){
            if(k==j)continue;
            if(board[i][k]==c) return false;
        }
        int x = i/3*3;
        int y = j/3*3;
        for(int a=x;a<x+3;a++){
            for(int b=y;b<y+3;b++){
                if(a==i and b==j) continue;
                if(board[a][b]==c) return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(!checkBoard(board,board[i][j],i,j)) return false;
            }
        }
        return true;
    }
};