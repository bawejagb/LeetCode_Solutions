class Solution {
    vector<vector<int>> res;
    void backtrack(int idx, int sum, vector<int>&cad, int target, vector<int>& path){
        if(sum==target){
            res.push_back(path);
            return;
        }
        for(int i=idx; i<cad.size();i++){
            if(i>idx&& cad[i]==cad[i-1]) continue;
            if(sum + cad[i]<=target){
                path.push_back(cad[i]);
                backtrack(i+1, sum+cad[i], cad, target, path);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        backtrack(0,0,candidates,target, path);
        return res;
    }
};