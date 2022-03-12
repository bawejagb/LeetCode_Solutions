class Solution {
    vector<vector<int>> res;
    void backTrack(vector<int>&nums, vector<int>&curr, int pos){
        if(pos==nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[pos]);
        backTrack(nums, curr, pos+1);
        curr.pop_back();
        while(pos+1<nums.size()&&nums[pos]==nums[pos+1]) pos++;
        backTrack(nums, curr, pos+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> cur;
        backTrack(nums, cur, 0);
        return res;
    }
};