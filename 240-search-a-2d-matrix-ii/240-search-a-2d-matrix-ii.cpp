class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios::sync_with_stdio(0);
        int i = 0, j = matrix[0].size(), k;
        while(i < matrix.size() && j && (k = matrix[i][j-1]) != target) {
            if (k > target) j--;
            else if(k == target) return true;
            else i++;
        }
        
        while (matrix.size()) matrix.pop_back();
        
        return k == target;
    }
};