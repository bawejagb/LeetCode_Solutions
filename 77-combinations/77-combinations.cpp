class Solution {
    vector<vector<int>> res;
    void backtrack(int n, int k, int idx, vector<int>&path){
        if(k==0){
            res.push_back(path);
            return;
        }
        for(int i=idx;i<=n;i++){
            path.push_back(i);
            backtrack(n,k-1,i+1,path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        backtrack(n,k,1,path);
        return res;
    }
};