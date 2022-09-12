class Solution {
    vector<int> low, dis;
    vector<vector<int>> bridge, adj;
    int time;
    void dfs(int node, int prev){
        time++;
        low[node] = dis[node] = time;
        for(auto x : adj[node]){
            if(x==prev) continue;
            if(dis[x]!=-1){
                low[node] = min(low[node], dis[x]);
                continue;
            }
            dfs(x, node);
            low[node] = min(low[node], low[x]);
            if(low[x]>dis[node])
                bridge.push_back({node, x});
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        time = 0;
        dis.resize(n,-1);
        low.resize(n,-1);
        adj.resize(n);
        for(auto c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        for(int i=0;i<n;i++){
            if(dis[i]==-1)
                dfs(i,-1);
        }
        return bridge;
    }
};