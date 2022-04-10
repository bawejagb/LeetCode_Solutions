class Solution {
    vector<pair<int,int>> adj[101];
    void dijakstra(vector<int> &recTime, int k){
        set<pair<int,int>> qt;
        vector<bool> visit(101,0);
        qt.insert({0,k});
        recTime[k] = 0;
        while(!qt.empty()){
            auto it = qt.begin();
            int node = it->second;
            qt.erase(it);
            if(visit[node]) 
                continue;
            visit[node] = true;
            for(auto edge : adj[node]){
                int time = edge.first;
                int des = edge.second;
                if(visit[des]) 
                    continue;
                int val = time + recTime[node];
                if(val < recTime[des]){
                    recTime[des] = val;
                    qt.insert({recTime[des],des});
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = INT_MIN;
        for(auto pr: times){
            int src = pr[0];
            int des = pr[1];
            int time = pr[2];
            adj[src].push_back({time, des});
        }
        vector<int> recTime(n+1,INT_MAX);
        dijakstra(recTime, k);
        for(int i=1;i<n+1;i++){
           ans = max(ans, recTime[i]); 
        }
        return ans == INT_MAX ? -1 : ans;
    }
};