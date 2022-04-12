class Solution {
    bool dfs(vector<vector<int>>&adj, vector<bool>&color, vector<bool>&visit, int node, bool fg){
        if(visit[node] && color[node]==fg) return true;
        if(visit[node] && color[node]!=fg) return false;
        visit[node] = true;
        color[node] = fg;
        for(int x : adj[node]){
            if(!dfs(adj,color,visit,x,!fg)) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<bool> color(n+1,false), visit(n+1,false);
        vector<vector<int>> adj(n+1);
        for(auto x : dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=1;i<=n;i++){
            if(visit[i]) continue;
            if(!dfs(adj,color, visit,i, 1)) return false;
        }
        return true;
    }
};