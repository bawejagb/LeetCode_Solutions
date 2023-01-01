class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool di[200]{},dj[200]{};
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    di[i]=1;
                    dj[j]=1;
                }
            }
        }
        for(int k=0;k<200;k++){
            if(di[k])
                for(int i=0;i<n;i++) matrix[k][i] = 0;
            if(dj[k])
                for(int i=0;i<m;i++) matrix[i][k] = 0;
        }
    }
};