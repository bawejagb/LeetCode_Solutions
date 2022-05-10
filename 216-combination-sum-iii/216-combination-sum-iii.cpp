class Solution {
    vector<vector<int>> res;
    void combinations(int k ,int n, int idx, vector<int>& nums){
        if(k==0){
            int sum = 0;
            for(int x : nums) sum += x;
            if(sum == n) res.push_back(nums);
            return;
        }
        if(idx>9) return;
        nums.push_back(idx);
        combinations(k-1,n,idx+1,nums);
        nums.pop_back();
        combinations(k,n,idx+1,nums);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        combinations(k,n,1, nums);
        return res;
    }
};