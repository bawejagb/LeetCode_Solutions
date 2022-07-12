class Solution {
    int dp[1 << 16][5];
public:
    int side;

    bool solve(vector<int>& nums, int mask, int completed, int total) {
        if(__builtin_popcount((unsigned int)(mask)) == 0) return completed == 4;
        
        if(dp[mask][completed] != -1) return dp[mask][completed];
        
        for(int i = 0; i < nums.size(); i++) {
            if(mask&(1 << i)) {
                if(solve(nums,mask^(1 << i),completed+((total+nums[i])%side == 0),total+nums[i]))
                    return dp[mask][completed] = true;
            }
        }

        return dp[mask][completed] = false;
    }

    bool makesquare(vector<int>& matchsticks) {
        memset(dp,-1,sizeof dp);
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4) return false;
        else this->side = sum/4;
        return solve(matchsticks,(1 << n)-1,0,0);
    }
};