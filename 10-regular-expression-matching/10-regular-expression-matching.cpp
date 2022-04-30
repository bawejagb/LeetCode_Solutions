class Solution {
    bool dfs(int i, int j, string s, string p,vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=s.size()&&j>=p.size()) return dp[i][j] = 1;
        if(j>= p.size()) return dp[i][j] = 0;
        bool match = i<s.size()&&(s[i]==p[j] || p[j]=='.');
        if((j+1)<p.size() && p[j+1]=='*')
            return dp[i][j] = (dfs(i,j+2,s,p,dp)||(match&&dfs(i+1,j,s,p,dp)));
        if(match)
            return dp[i][j] = dfs(i+1,j+1,s,p,dp);
        return dp[i][j] = 0;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return dfs(0,0,s,p,dp);
    }
};