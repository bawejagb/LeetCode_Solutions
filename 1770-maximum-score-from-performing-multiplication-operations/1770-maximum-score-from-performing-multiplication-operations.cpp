class Solution {
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        int dp[1001][1001]{};
        for(int i = m-1; i>=0; i--){
            for(int left = i; left>=0; left--){
                dp[i][left] = max(nums[left]*multipliers[i]+dp[i+1][left+1],
                                 nums[n-1-i+left]*multipliers[i]+dp[i+1][left]);
            }
        }
        return dp[0][0];
    }
};