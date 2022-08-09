class Solution {
    int MOD= 1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int res=0;
        if(arr.size()==1)
            return 1;
        unordered_map<int,int> mp;
        vector<int> dp(arr.size(),1);
        sort(arr.begin(),arr.end());
        mp[arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            mp[arr[i]]=i+1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int k= arr[i]/arr[j];
                    if(mp[k]){
                         dp[i]+= ((1LL*dp[mp[arr[j]]-1])*(1LL*dp[mp[k]-1]))%MOD;
                         dp[i]= dp[i]%MOD;
                    }
                }
            }
        }
        for(auto it: dp){
            res+= it;
            res= res%MOD;
        }
        return res;
    }
};