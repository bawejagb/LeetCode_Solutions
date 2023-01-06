class Solution {
    bool findSum(vector<int>& nums, int sum){
        vector<vector<bool>> dp(nums.size(),vector<bool>(sum+1,false));
        for(int i=0;i<nums.size();i++)
            dp[i][0]=true;
        if(sum>nums[0])
            dp[0][nums[0]]=true;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i]<=j)
                    dp[i][j] = dp[i][j] | dp[i-1][j-nums[i]];
            }
        }
        return dp[nums.size()-1][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sm = 0;
        for(int num : nums)
            sm += num;
        if(sm%2) return false;
        sm /= 2;
        return findSum(nums,sm);
    }
};