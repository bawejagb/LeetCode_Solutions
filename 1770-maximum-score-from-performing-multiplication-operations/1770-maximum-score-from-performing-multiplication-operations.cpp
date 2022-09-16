class Solution {
    int helper(vector<int>& nums, vector<int>& mul, int idx, int left, vector<vector<int>>&dp){
        if(idx==mul.size()) return 0;
        if(dp[left][idx]!=INT_MAX) return dp[left][idx];
        int l = mul[idx]*nums[left]+helper(nums,mul,idx+1,left+1,dp);
        int r = mul[idx]*nums[nums.size()-1-idx+left]+helper(nums,mul,idx+1,left,dp);
        return dp[left][idx] = max(l,r);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1,INT_MAX));
        return helper(nums, multipliers, 0, 0,dp);
    }
};