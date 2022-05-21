class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX-1);
        sort(coins.begin(),coins.end());
        dp[0]=0;
        for(int x : coins){
            for(int i=x; i<= amount; i++){
                if(dp[i-x] != INT_MAX-1){
                    dp[i]=min(dp[i],dp[i-x]+1);
                }
            }
        }
        return dp[amount]==INT_MAX-1?-1:dp[amount];
    }
};