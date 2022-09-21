class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
        vector<int> res;
        int sum = 0;
        for(int val : nums){
            if(val%2==0) sum += val;
        }
        for(auto q : queries){
            if(nums[q[1]]%2==0){
                sum -= nums[q[1]];
            }
            nums[q[1]]+=q[0];
            if(abs(nums[q[1]])%2==0){
                sum += nums[q[1]];
            }
            res.push_back(sum);
        }
        return res;
    }
};