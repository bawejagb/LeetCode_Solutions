class Solution {
    typedef unsigned long long ll;
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        ll dp[1001]{};
        dp[0] = 1LL;
        s = '#'+s;
        t = '#'+t;
        for(int i=1; i<=m; i++){
            for(int j=n; j>=1; j--){
                if(s[i]==t[j])
                    dp[j] += dp[j-1];
            }
        }
        return dp[n];
    }
};