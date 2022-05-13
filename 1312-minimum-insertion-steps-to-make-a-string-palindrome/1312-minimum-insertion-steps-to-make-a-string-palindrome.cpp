class Solution
{
    public:
        int minInsertions(string s)
        {
            int n = s.size();
            int dp[501][501] {};
            string sRev = string(s.rbegin(), s.rend());
            
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (s[i - 1] == sRev[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
            
            return n - dp[n][n];
        }
};