class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;
        int n = s.size();
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            if(s[i]==')'&&s[i-1]=='(')
                dp[i] = (i>=2?dp[i-2]:0)+2;
            if(s[i]==')'&&s[i-1]==')'&&i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
                dp[i] = dp[i-1]+(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0)+2;
            res = max(res,dp[i]);
        }
        return res;
    }
};