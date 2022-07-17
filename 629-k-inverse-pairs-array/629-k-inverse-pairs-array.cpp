class Solution {
    int m = 1e9+7;
public:
    int kInversePairs(int n, int k) {
        if(k==0)
            return 1;
        int i,j; 
        int dp[1001][1001]{};
        dp[0][0]=1;
        for(i=1;i<=n;i++){
            dp[i][0]=1;
            for(j=1;j<=k;j++){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j])%m;
                if(j>=i)
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + m)%m;
            }
        }
        return dp[n][k];
    }
};