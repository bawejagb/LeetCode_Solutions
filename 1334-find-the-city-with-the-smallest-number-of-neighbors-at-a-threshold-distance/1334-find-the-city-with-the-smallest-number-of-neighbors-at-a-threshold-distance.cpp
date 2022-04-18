class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        for(auto x: edges){
            dp[x[0]][x[1]] = x[2];
            dp[x[1]][x[0]] = x[2];
        }
        for(int i=0;i<n;i++)
            dp[i][i] = 0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][k]+dp[k][j]<dp[i][j])
                        dp[i][j] = dp[i][k]+dp[k][j];
                }
            }
        }
        int min_cnt = 1e9;
        int res = -1;
        for(int i= 0; i<n;i++){
            int cnt = 0;
            for(int j = 0; j < n;j++){
                if(dp[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(cnt <= min_cnt){
                min_cnt = cnt;
                res = i;
            }
        }
        return res;
    }
};