class Solution {
    int dfs(int i, int j, int m, int n, int prev, vector<vector<int>> &depth,vector<vector<int>> &matrix){
        if(i<0||j<0||i>=m || j>=n) return 0;
        if(prev >= matrix[i][j]) return 0;
        if(depth[i][j]!= -1) return depth[i][j];
        int cnt1 = dfs(i-1,j,m,n,matrix[i][j],depth,matrix);
        int cnt2 = dfs(i,j-1,m,n,matrix[i][j],depth,matrix);
        int cnt3 = dfs(i+1,j,m,n,matrix[i][j],depth,matrix);
        int cnt4 = dfs(i,j+1,m,n,matrix[i][j],depth,matrix);
        return depth[i][j] = max({cnt1, cnt2, cnt3, cnt4})+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m,n,len=0;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> depth(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(depth[i][j]==-1)
                    len = max(len,dfs(i,j,m,n,-1,depth,matrix));
            }
        }
        return len;
    }
};