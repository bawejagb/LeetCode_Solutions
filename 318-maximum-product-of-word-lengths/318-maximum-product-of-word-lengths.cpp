class Solution {
public:
    int maxProduct(vector<string>& words) {
        int dp[1001][26]{};
        int res=0, n = words.size();
        for(int i=0;i<n;i++){
            for(char c : words[i])
                dp[i][c-'a']++;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool fg=0;
                for(int k=0;k<26;k++){
                    if(dp[i][k]&&dp[j][k]){
                        fg=1;
                        break;
                    }
                }
                if(!fg){
                    int sz = words[i].size()*words[j].size();
                    res = max(res,sz);
                }
            }
        }
        return res;
    }
};