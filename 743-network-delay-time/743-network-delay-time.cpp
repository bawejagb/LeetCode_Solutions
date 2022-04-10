class Solution {
    vector<pair<int,int>> adj[101];
    void dijakstra(vector<int> &recTime, int k){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qt;
        qt.push({0,k});
        recTime[k] = 0;
        while(!qt.empty()){
            auto node = qt.top();
            qt.pop();
            if(node.first > recTime[node.second]) 
                continue;
            for(auto edge : adj[node.second]){
                int time = edge.first;
                int des = edge.second;
                int val = time + recTime[node.second];
                if(val < recTime[des]){
                    recTime[des] = val;
                    qt.push({recTime[des],des});
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