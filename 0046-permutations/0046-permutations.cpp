class Solution {
    void perm(vector<int>& nums, vector<vector<int>>& res, int idx){
        if(idx==nums.size())
            res.push_back(nums);
        for(int i=idx; i<nums.size();i++){
            swap(nums[idx],nums[i]);
            perm(nums,res,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        perm(nums,res,0);
        return res;
    }
};