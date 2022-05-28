class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total=0, sum;
        sum = n*(n+1)/2;
        for(int i=0;i<n;i++) total += nums[i];
        return sum-total;
    }
};