class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001]{};
        int n = text1.size();
        int m = text2.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[n][m];
    }
};