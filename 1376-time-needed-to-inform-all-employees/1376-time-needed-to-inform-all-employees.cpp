class Solution {
    int dfs(int node, vector<vector<int>> &adj, vector<int> &informTime){
        if(adj[node].size()==0) return 0;
        int time = 0;
        for(int x :adj[node]){
            time = max(dfs(x,adj,informTime),time);
        }
        return time+informTime[node];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1) return 0;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]==-1){
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        int res = dfs(headID, adj, informTime);
        return res;
    }
};