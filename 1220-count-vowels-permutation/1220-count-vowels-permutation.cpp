class Solution {
public:
    int countVowelPermutation(int n) {
        long long dp[20001][5]{};
        //INDEX: a = 0, e = 1, i = 2, o = 3, u = 4
        int mod = (int)1e9 + 7;
        
        for(int i=0;i<5;i++)
            dp[1][i] = 1;
        
        for(int j=2;j<=n;j++){
            dp[j][0] = (dp[j-1][1] + dp[j-1][2] + dp[j-1][4]) % mod; //a
            dp[j][1] = (dp[j-1][0] + dp[j-1][2]) % mod; //e
            dp[j][2] = (dp[j-1][1] + dp[j-1][3]) % mod; //i
            dp[j][3] = dp[j-1][2] % mod; // o
            dp[j][4] = (dp[j-1][2] + dp[j-1][3])%mod; //u
        }
        
        long long sum = 0;
        for(int i=0;i<5;i++){
            sum += dp[n][i];
        }
        
        return sum % mod;
    }
};