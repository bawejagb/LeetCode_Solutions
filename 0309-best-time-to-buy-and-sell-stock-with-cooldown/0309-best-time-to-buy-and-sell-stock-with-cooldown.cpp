class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[3][2]{};
        for(int i=n-1;i>=0;i--){
            dp[0][1] = max(-prices[i]+dp[1][0],dp[1][1]);
            dp[0][0] = max(prices[i]+dp[2][1],dp[1][0]);
            dp[2][0] = dp[1][0];
            dp[2][1] = dp[1][1];
            dp[1][0] = dp[0][0];
            dp[1][1] = dp[0][1];
        }
        return dp[0][1];
    }
};