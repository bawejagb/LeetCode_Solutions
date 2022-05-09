class Solution
{
    public:
        int mergeStones(vector<int> &stones, int k)
        {
            int n = stones.size();
            if ((n - k) % (k - 1)) return -1;
            int presum[32] {};
            for (int i = 0; i < n; i++)
                presum[i + 1] = presum[i] + stones[i];
            int dp[32][32] {};
            for (int len = k; len <= n; len++)
            {
                for (int i = 0; i + len <= n; i++)
                {
                    int j = i + len - 1;
                    dp[i][j] = INT_MAX;

                    for (int t = i; t < j; t += (k - 1))
                        dp[i][j] = min(dp[i][j], dp[i][t] + dp[t + 1][j]);

                    if ((j - i) % (k - 1) == 0)
                        dp[i][j] += presum[j + 1] - presum[i];
                }
            }
            return dp[0][n - 1];
        }
};