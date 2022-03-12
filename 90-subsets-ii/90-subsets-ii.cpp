class Solution {
    vector<vector<int>> res;
    void backTrack(vector<int>&nums,set<vector<int>> &hset, vector<int>&curr, int pos){
        if(pos==nums.size()){
            hset.insert(curr);
            return;
        }
        curr.push_back(nums[pos]);
        backTrack(nums, hset, curr, pos+1);
        curr.pop_back();
        backTrack(nums, hset, curr, pos+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> cur;
        set<vector<int>> hset;
        backTrack(nums, hset, cur, 0);
        for(auto x: hset)
            res.push_back(x);
        return res;
    }
};