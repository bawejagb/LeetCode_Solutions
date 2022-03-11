class Solution {
    vector<vector<int>> res;
    void backTrack(vector<int>&nums, vector<bool>&visit, vector<int>&path){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        unordered_set<int> hset;
        for(int i=0;i<nums.size();i++){
            if(hset.find(nums[i])!=hset.end()) continue;
            if(!visit[i]){
                hset.insert(nums[i]);
                visit[i]=1;
                path.push_back(nums[i]);
                backTrack(nums, visit, path);
                visit[i]=0;
                path.pop_back();
            }
        }
        
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visit(n,0);
        vector<int> path;
        backTrack(nums,visit,path);
        return res;
    }
};