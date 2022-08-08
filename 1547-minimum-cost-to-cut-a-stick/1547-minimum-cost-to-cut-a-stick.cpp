class Solution {
    int dp[102][102];
public:
    int minCost(int n, vector<int>& cuts) {
        int sz=cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        for(int i=sz;i>=1;i--){
            for(int j=1;j<=sz;j++){
                if(i>j) continue;
                int val=1e9;
                for(int k=i;k<=j;k++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    val=min(val,cost);
                }
                 dp[i][j]=val;
            }
        }       
        return dp[1][sz];
    }
};