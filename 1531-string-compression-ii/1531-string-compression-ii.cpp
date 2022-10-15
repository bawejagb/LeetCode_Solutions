int dp[101][101];
class Solution {
    string st;
    int findLength(int idx, int K){
        int k = K;
        if(st.size()-idx<=k) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int res = k ? findLength(idx+1, k-1): 1e5;
        int cnt = 1;
        for(int i=idx+1;i<=st.size();++i){
            int notMiss = 1+findLength(i, k);
            notMiss += (cnt>=100?3:(cnt>=10?2:(cnt>1?1:0)));
            res = min(res, notMiss);
            if(i==st.size()) break;
            if(st[i]==st[idx]) cnt++;
            else if(--k<0) break;
        }
        return dp[idx][K] = res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        st = s;
        memset(dp,-1,sizeof(dp));
        return findLength(0, k);
    }
};