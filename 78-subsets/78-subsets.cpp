class Solution {
    void backtrack(int idx, int first, vector<int> &temp, vector<int> &nums, vector<vector<int>> &res){
        if(temp.size()==idx){
            res.push_back(temp);
            return;
        }
        for(int i=first;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(idx,i+1,temp, nums, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=0;i<=nums.size();i++){
            backtrack(i,0,temp,nums,res);
        }
        return res;
    }
};