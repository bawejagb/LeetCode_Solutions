class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i, up, down, left, right, row, col;
        up = 0;
        down = matrix.size()-1;
        left = 0;
        right = matrix[0].size()-1;
        vector<int> res;
        row = col = 0;
        while(left <= right && up <= down){
            for(i = left; i <= right; i++){
                res.push_back(matrix[row][i]);
            }
            col = right;
            up++;
            if(up > down)
                break;
            for(i = up; i <= down; i++){
                res.push_back(matrix[i][col]);
            }
            row = down;
            right--;
            if(left > right)
                break;
            for(i = right; i >= left; i--){
                res.push_back(matrix[row][i]);
            }
            col = left;
            down--;
            if(up > down)
                break;
            for(i = down; i >= up; i--){
                res.push_back(matrix[i][col]);
            }
            left++;
            row = up;
        }
        return res;
        
    }
};