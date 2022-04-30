class Solution {
    unordered_map<string,bool> dp;
    bool dfs(int i, int j, string s, string p){
        string pr = to_string(i)+" "+to_string(j);
        if(dp.find(pr)!=dp.end()) return dp[pr];
        if(i>=s.size()&&j>=p.size()) return dp[pr] = true;
        if(j>= p.size()) return dp[pr] = false;
        bool match = i<s.size()&&(s[i]==p[j] || p[j]=='.');
        if((j+1)<p.size() && p[j+1]=='*')
            return dp[pr] = (dfs(i,j+2,s,p)||(match&&dfs(i+1,j,s,p)));
        if(match)
            return dp[pr] = dfs(i+1,j+1,s,p);
        return dp[pr] = false;
    }
public:
    bool isMatch(string s, string p) {
        return dfs(0,0,s,p);
    }
};