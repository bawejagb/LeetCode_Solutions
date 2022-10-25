class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<vector<int>> qt;
        vector<int> dis(n,1e9);
        vector<vector<pair<int,int>>> adj(n);
        //Create adjoint list
        for(auto pr: flights)
            adj[pr[0]].push_back({pr[1],pr[2]});
        //insert source in queue
        qt.push({0,src,0});
        dis[src]=0;
        //BFS in queue
        while(!qt.empty()){
            int stop = qt.front()[0];
            int node = qt.front()[1];
            int cost = qt.front()[2];
            qt.pop();
            if(stop>k) continue;
            for(auto ad : adj[node]){
                if(dis[node]+ad.second<dis[ad.first]){
                    dis[ad.first]=cost+ad.second;
                    qt.push({stop+1,ad.first,dis[ad.first]});
                }
            }
        }
        return dis[dst]==1e9?-1:dis[dst];
    }
};