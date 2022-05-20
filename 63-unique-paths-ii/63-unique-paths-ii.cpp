class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m,n;
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        vector<vector<int>> dp(2,vector<int>(m,0));
        if (!obstacleGrid[0][0])
        dp[0][0]=1;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (i+j==0) continue;
                dp[i%2][j]=0;
                if (obstacleGrid[i][j]) continue;
                if (i) dp[i%2][j]+=dp[(i-1)%2][j];
                if (j) dp[i%2][j]+=dp[i%2][j-1];
            }
        }
        return dp[(n-1)%2][m-1];
    }
};