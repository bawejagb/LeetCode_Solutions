class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k==0||n<=1) return 0;
        if(2*k>n){
            int res=0;
            for(int i=1;i<n;i++){
                if(prices[i]>prices[i-1])
                    res += (prices[i]-prices[i-1]);
            }
            return res;
        }
        int dp[2*k+1];
        dp[0] = -prices[0];
        for(int i=1;i<2*k+1;i++){
            if(i%2==0)
                dp[i]=INT_MIN;
            else
                dp[i]=0;
        }
        for(int j=0;j<n;j++)
        for(int i=0;i<2*k+1;i++){
            if(i==0)
                dp[i] = max(dp[i], -prices[j]);
            else if(i%2==0)
                dp[i] = max(dp[i],dp[i-1]-prices[j]);
            else
                dp[i] = max(dp[i],dp[i-1]+prices[j]);
        }
        return dp[2*k-1];
    }
};