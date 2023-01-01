class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> di(m,0), dj(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    di[i]=1;
                    dj[j]=1;
                }
            }
        }
        for(int k=0;k<m;k++){
            if(di[k])
                for(int i=0;i<n;i++) matrix[k][i] = 0;
        }
        for(int k=0;k<n;k++){
            if(dj[k])
                for(int i=0;i<m;i++) matrix[i][k] = 0;
        }
    }
};