class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, minSum=INT_MAX, sum=0, maxSum=INT_MIN, sum2=0;
        for(int num : nums){
            total += num;
            sum += num;
            sum2 += num;
            maxSum = max(maxSum, sum2);
            if(sum>0) sum=0;
            if(sum2<0) sum2=0;
            minSum = min(minSum,sum);
        }
        return total==minSum?maxSum:max(maxSum,total - minSum);
    }
};