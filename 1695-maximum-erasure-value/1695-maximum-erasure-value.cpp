class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0, max_sum =-1,n=nums.size(), start=0;
        unordered_map<int, int> map;
        vector<int> prefix_sum(n+1, 0);
        
        for(int i=0; i<n; i++){
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
            if(map.find(nums[i]) != map.end()){
                start = max(map[nums[i]]+1, start);
            }
            map[nums[i]] = i;
            sum = prefix_sum[i+1] - prefix_sum[start];
            max_sum = max(max_sum, sum);
            
        }
        return max_sum;
    }
};