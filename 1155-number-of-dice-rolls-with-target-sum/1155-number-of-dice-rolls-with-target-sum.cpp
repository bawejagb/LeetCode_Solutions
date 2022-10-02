class Solution {
public:
    int mod=1e9+7;
    int count(int n,int k,int target,vector<vector<int>>&dp){
        if(n==0 && target==0) return 1;
        if(target<0 || n==0) return INT_MIN;
        
        if(dp[target][n] != -1) return dp[target][n];
        int ans=0,tmp;
        for(int i=1;i<=k;i++){
            tmp=count(n-1,k,target-i,dp);
            if(tmp>0) ans=(ans+tmp)%mod;
        }
        
        return dp[target][n]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(target+5,vector<int>(n+5,-1));
        return count(n,k,target,dp);
    }
};