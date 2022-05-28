class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total, sum;
        sum = n*(n+1)/2;
        total=0;
        for(int x : nums)
            total += x;
        return sum-total;
    }
};