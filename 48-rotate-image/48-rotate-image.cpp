class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int up,down,left,right;
        up = left = 0;
        down = right = matrix.size()-1;
        while(up < down){
            for(int i = left; i < right; i++){
                swap(matrix[up][i],matrix[i][right]);
                swap(matrix[up][i],matrix[down-i+left][left]);
                swap(matrix[down-i+left][left],matrix[down][right-i+left]);
            }
            left++,up++;
            right--,down--;
        }
    }
};