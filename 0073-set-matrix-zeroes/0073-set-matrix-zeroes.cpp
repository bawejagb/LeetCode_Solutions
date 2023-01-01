class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> lst;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(matrix[i][j]==0)
                    lst.push_back({i,j});
        }
        for(auto pr: lst){
            int x = pr.first;
            int y = pr.second;
            for(int i=0;i<m;i++) matrix[i][y] = 0;
            for(int j=0;j<n;j++) matrix[x][j] = 0;
        }
    }
};