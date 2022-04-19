class Solution {
    int dfs(int node, vector<int> &manager, vector<int> &informTime){
        int time = 0;
        if(manager[node]!=-1){
            informTime[node] += dfs(manager[node],manager,informTime);
            manager[node]=-1;
        }
        return informTime[node];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res=0;
        for(int i=0;i<n;i++){
            res = max(res,dfs(i, manager, informTime));
        }
        return res;
    }
};