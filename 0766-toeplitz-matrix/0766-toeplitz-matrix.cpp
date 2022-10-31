class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        for(int i=0;i<C-1;i++){
            for(int j=1;j<R;j++){
                if(i+j>=C) break;
                if(matrix[j][i+j]!=matrix[j-1][j+i-1]) return false;
            }
        }
        for(int i=1;i<R-1;i++){
            for(int j=1;j<C;j++){
                if(i+j>=R) break;
                if(matrix[i+j][j]!=matrix[i+j-1][j-1]) return false;
            }
        }
        return true;
    }
};