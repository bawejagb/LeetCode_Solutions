class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[1001]{};
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto x : nums) {
                if (x <= i) {
                    dp[i] += dp[i - x];
                }
            }
        }
        return dp[target];
    }
};