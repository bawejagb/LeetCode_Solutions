class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1,n+1);
        dp[0] = 0;
        for(int i=0;i<=n;i++){
            int left = max(0,i-ranges[i]);
            int right = min(n, i+ranges[i]);
            for(int j = left; j <= right; j++){
                dp[j] = min(dp[j], dp[left]+1);
            }
        }
        return dp[n]==n+1? -1 : dp[n];
    }
};