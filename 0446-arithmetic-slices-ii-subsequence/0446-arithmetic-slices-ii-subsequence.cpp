class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        long long ans = 0, i, j, n = a.size(), d;
        vector <unordered_map <long, long>> dp(n);
        for (i=1;i<n;i++) {
            for (j=0;j<i;j++) {
                d = (long)a[i] - (long)a[j];
                dp[i][d] += dp[j][d] + 1;
                ans += dp[j][d];
            }
        }
        return ans;
    }
};