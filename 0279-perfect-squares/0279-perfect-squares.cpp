class Solution {
public:
    int numSquares(int n) {
        vector<int> square, dp(n+1,0);
        for(int i=1;i<=sqrt(n);i++)
            square.push_back(i*i);
        for(int i=1;i<=n;i++){
            int val = INT_MAX;
            for(int sq : square){
                if(i-sq>=0){
                    val = min(val, dp[i-sq]+1);
                }
                else break;
            }
            dp[i] = val;
        }
        return dp[n];
    }
};