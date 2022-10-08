class Solution {
    typedef pair<int,int> pii;
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pii> adj[3001];
        int dis[3001];
        for(auto &e : edges){
            adj[e[0]].push_back({e[1],e[2]+1});
            adj[e[1]].push_back({e[0],e[2]+1});
        }
        for(int i=0;i<n;i++) dis[i]=1e9;
        dis[0] = 0;
        int ans=0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,0});
        int u,v,w;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            u = node.second;
            for(auto neb: adj[u]){
                v = neb.first;
                w = neb.second;
                if(dis[v] > dis[u]+w){
                    dis[v] = dis[u]+w;
                    pq.push({dis[v],v});
                }
            }
        }
        for(int i=0;i<n;i++) if(dis[i]<=maxMoves) ans++;
        for(auto &e : edges){
            if(dis[e[0]]<=maxMoves and dis[e[1]]<=maxMoves)
                ans += min(2*maxMoves-dis[e[0]]-dis[e[1]],e[2]);
            else if(dis[e[0]]<=maxMoves)
                ans += min(maxMoves-dis[e[0]],e[2]);
            else if(dis[e[1]]<=maxMoves)
                ans += min(maxMoves-dis[e[1]],e[2]);
        }
        return ans;
    }
};