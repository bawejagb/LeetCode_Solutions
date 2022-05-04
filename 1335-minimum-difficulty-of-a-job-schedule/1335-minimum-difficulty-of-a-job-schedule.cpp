class Solution {
    vector<int> mxfar;
    int dfs(vector<int>& jd, int d, int idx, vector<vector<int>>&dp){
        int n = jd.size();
        if(d==1) return mxfar[idx];
        if(dp[d][idx]!=-1) return dp[d][idx];
        int ans = 1e9;
        int mxVal = 0;
        for(int i = idx; i< n-d+1;i++){
            mxVal = max(mxVal, jd[i]);
            ans = min(ans, mxVal+dfs(jd, d-1, i+1,dp));
        }
        return dp[d][idx]=ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d) return -1;
        mxfar.resize(n);
        mxfar[n-1] = jobDifficulty[n-1];
        for(int i=n-2;i>=0;i--)
            mxfar[i] = max(jobDifficulty[i],mxfar[i+1]);
        vector<vector<int>> dp(d+1,vector<int>(n,-1));
        return dfs(jobDifficulty, d, 0,dp);
    }
};