int dp[101][27][101][101];
class Solution {
    
    string st;
    int findLength(int idx, int prev, int cnt, int k){
        if(k<0) return INT_MAX;
        if(idx>=st.size()) return 0;
        if(dp[idx][prev][cnt][k]!=-1) return dp[idx][prev][cnt][k];
        int miss = findLength(idx+1, prev, cnt, k-1);
        int notMiss = 0;
        if(prev == st[idx]-'a'){
            if(cnt==1 || cnt==9 || cnt==99)
                notMiss++;
            notMiss += findLength(idx+1, prev, cnt+1, k);
        }
        else{
            notMiss = 1 + findLength(idx+1, st[idx]-'a', 1, k);
        }
        return dp[idx][prev][cnt][k] = min(miss,notMiss);
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        st = s;
        memset(dp,-1,sizeof(dp));
        return findLength(0,26, 0, k);
    }
};