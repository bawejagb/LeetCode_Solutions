class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size() , n = s2.size();
        if(m + n != s3.size() ) return false;
        bool dp[101][101]{};
        dp[0][0] = 1;
        for(int i=1; i<= m; i++) dp[i][0] = (s1[i-1] == s3[i-1] ) && (dp[i-1][0]) ;
        for(int i=1; i<= n; i++) dp[0][i] = (s2[i-1] == s3[i-1] ) && (dp[0][i-1]) ;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = (s3[i+j-1] == s1[i-1] ? dp[i-1][j] : 0 ) || 
                    (s3[i+j-1] == s2[j-1] ? dp[i][j-1] : 0)  ;
            }
        }

        return dp[m][n];
    }   
};