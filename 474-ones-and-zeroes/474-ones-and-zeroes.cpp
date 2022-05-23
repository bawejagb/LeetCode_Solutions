class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101]{};
        int zero, one;
        for( string s : strs){
            zero = count(s.begin(),s.end(),'0');
            one  = s.size()-zero;
            for(int i=m;i>=zero;i--){
                for(int j=n;j>=one;j--)
                    dp[i][j] = max(dp[i][j], dp[i-zero][j-one]+1);
            }
        }
        return dp[m][n];
    }
};