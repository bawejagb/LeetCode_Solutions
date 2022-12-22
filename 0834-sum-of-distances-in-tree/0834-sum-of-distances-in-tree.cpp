class Solution {
    vector<int> res,count;
    void postOrder(vector<vector<int>> &adj, int root, int prev){
        for(int node : adj[root]){
            if(node==prev) continue;
            postOrder(adj, node, root);
            count[root] += count[node];
            res[root] += res[node]+count[node];
        }
        count[root]++;
    }
    void preOrder(vector<vector<int>>&adj, int root, int prev){
        for(int node : adj[root]){
            if(node==prev) continue;
            res[node] = res[root]-count[node]+adj.size()-count[node];
            preOrder(adj, node,root);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n,0);
        count.resize(n,0);
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        postOrder(adj,0,-1);
        preOrder(adj,0,-1);
        return res;
    }
};