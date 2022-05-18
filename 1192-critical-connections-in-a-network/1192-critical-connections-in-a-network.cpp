class Solution {
    vector<int> dis,low;
    vector<vector<int>> bridge, adj;
    int time;
    void dfs(int node, int prev){
        time++;
        low[node] = dis[node] = time;
        for(auto x : adj[node]){
            if(x==prev) continue;
            else if(dis[x]!=-1){
               low[node] = min(low[node],dis[x]);
                continue;
            }
            dfs(x,node);
            low[node] = min(low[node],low[x]);
            if(low[x] > dis[node])
                bridge.push_back({node,x});
        }
        
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dis.resize(n,-1);
        low.resize(n,-1);
        adj.resize(n);
        time=0;
        for(auto x : connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            if(dis[i]==-1)
                dfs(i,-1);
        }
        return bridge;
    }
};