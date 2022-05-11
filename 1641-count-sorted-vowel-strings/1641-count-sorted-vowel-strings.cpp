class Solution {
    int dfs(int n, int idx, vector<vector<int>>& dp){
        if(n==0) return 1;
        if(dp[n][idx]!=-1) return dp[n][idx];
        int res=0;
        for(int i=idx; i<5;i++)
            res += dfs(n-1,i,dp);
        return dp[n][idx] = res;
    }
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        return dfs(n,0,dp);
    }
};