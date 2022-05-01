class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m,n,res=0;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            stack<int> st;
            int idx, val;
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    if(i==0) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j]+1;
                }
                while(!st.empty()&&dp[i][j]<dp[i][st.top()]){
                    idx = st.top();
                    st.pop();
                    val = dp[i][idx]*(st.empty()?j:j-1-st.top());
                    res = max(res,val);
                }
                st.push(j);
            }
            while(!st.empty()){
                idx = st.top();
                st.pop();
                val = dp[i][idx]*(st.empty()?n:n-1-st.top());
                res = max(res,val);
            }
        }
        return res;
    }
};