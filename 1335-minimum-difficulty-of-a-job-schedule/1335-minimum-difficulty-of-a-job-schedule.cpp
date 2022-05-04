class Solution {

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if(n<d) return -1;
        
        int dp[d][n];
        
        dp[0][0] = jobDifficulty[0];
        for(int i=1;i<n;i++)
            dp[0][i] = max(dp[0][i-1],jobDifficulty[i]);
        
        for(int i=1;i<d;i++){
            for(int j=i;j<n;j++){
                int mxLocal = jobDifficulty[j];
                int mnVal = INT_MAX;
                for(int k=j;k>=i;k--){
                   mxLocal = max(mxLocal, jobDifficulty[k]);
                    mnVal = min(mnVal, dp[i-1][k-1]+mxLocal);
                }
                dp[i][j] = mnVal;
            }
        }
        return dp[d-1][n-1];
    }
};