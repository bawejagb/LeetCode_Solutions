class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rowSize = mat.size();
        int colSize = mat[0].size();
        vector<int> temp;
        for(int c = 0; c < colSize; c++){
            temp.clear();
            for(int i = 0, j = c; i<rowSize && j<colSize; i++,j++)
                temp.push_back(mat[i][j]);
            sort(temp.begin(),temp.end());
            for(int i = 0, j = c,k=0; i<rowSize && j<colSize &&k<temp.size(); i++,j++,k++)
                mat[i][j] = temp[k];
        }
        for(int r = 1; r < rowSize; r++){
            temp.clear();
            for(int i = r, j = 0; i<rowSize && j<colSize; i++,j++)
                temp.push_back(mat[i][j]);
            sort(temp.begin(),temp.end());
            for(int i = r, j = 0,k=0; i<rowSize && j<colSize &&k<temp.size(); i++,j++,k++)
                mat[i][j] = temp[k];
        }
        return mat;
    }
};