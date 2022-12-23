class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[5002][2]{};
        for(int i=n-1;i>=0;i--){
            dp[i][1] = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            dp[i][0] = max(prices[i]+dp[i+2][1],dp[i+1][0]);
        }
        return dp[0][1];
    }
};