class Solution {
public:
    int uniquePaths(int m, int n) {
        int prev, dp[n];
        for(int i=0;i<n;i++) dp[i]=1;
        for(int i=1;i<m;i++){
            prev=1;
            for(int j=1;j<n;j++){
                dp[j]=dp[j]+prev;
                prev =dp[j];
            }
        }
        return dp[n-1];
    }
};