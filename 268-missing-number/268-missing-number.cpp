class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,n=nums.size(),sum_n=0;
        for(int i=0;i<n; i++) sum+=nums[i];
        for(int i=1;i<=n;i++) sum_n+=i;
        return sum_n-sum;
    }
};