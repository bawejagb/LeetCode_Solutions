class Solution {
    bool solve(string &s,string &p,int &m,int &n,int a,int b, vector<vector<int>>&dp){
        if(a==m and b==n) return true;
        if(a==m){
            for(int i=b;i<n;i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(b==n) return false;
        if(dp[a][b]!=-1) return dp[a][b];
        bool ans = false;
        if(s[a]==p[b]){
            if(solve(s,p,m,n,a+1,b+1,dp))
                ans=true;
        }
        else if(p[b]=='?'){
            if(solve(s,p,m,n,a+1,b+1,dp))
                ans=true;
        }
        else if(p[b]=='*'){
            if(solve(s,p,m,n,a+1,b+1,dp))
                ans=true;
            if(solve(s,p,m,n,a,b+1,dp))
                ans=true;
            if(solve(s,p,m,n,a+1,b,dp))
                ans=true;
        }
        dp[a][b] = ans;
        return ans;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(s,p,m,n,0,0,dp);
    }
};