class Solution {
    int MOD = 2000000000;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m,n;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==m-1&&j==n-1) dp[i][j]=1;
                else if(j==n-1) dp[i][j] = dp[i+1][j];
                else if(i==m-1) dp[i][j] = dp[i][j+1];
                else dp[i][j] = (int)(1ll*dp[i+1][j]+1ll*dp[i][j+1])%MOD;
            }
        }
        return dp[0][0];
    }
};