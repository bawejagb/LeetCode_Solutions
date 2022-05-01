class Solution {
    int col[500][2];
    int dp[500];
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(!m) return 0;
        int n=matrix[0].size();
        if(!n) return 0;
        int ans=0;
        for(int i=0; i<m; ++i) {
            dp[i]=0;
        }
        for(int i, j=0, k, l, w; j<n; ++j) {
            k=0;
            col[0][0]=0;
            col[0][1]=-1;
            for(i=m-1; i>=0; --i) {
                w=dp[i]=matrix[i][j]=='0'? 0:dp[i]+1;
                for(l=k; l>=0 && col[l][0]>w; --l) {
                    ans=max(ans, col[l][0]*(col[l][1]-i));
                }
                if(++l>k) {
                    col[l][0]=w;
                    col[l][1]=i;
                } else {
                    col[l][0]=w;
                }
                k=l;
            }
            for(; k>=0; --k) {
                ans=max(ans, col[k][0]*(col[k][1]+1));
            }
        }
        return ans;
    }
};