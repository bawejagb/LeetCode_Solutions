class Solution {
    vector<pair<int,int>> adj[101];
    void BFS(vector<int> &recTime, int k){
        queue<int> qt;
        qt.push(k);
        while(!qt.empty()){
            int size = qt.size();
            while(size--){
                int node = qt.front();
                qt.pop();
                for(auto pr : adj[node]){
                    int time = pr.first;
                    int des = pr.second;
                    int val = time + recTime[node];
                    if(val < recTime[des]){
                        qt.push(des);
                        recTime[des] = val;
                    }
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
        recTime[k] = 0;
        BFS(recTime, k);
        for(int i=1;i<n+1;i++){
           ans = max(ans, recTime[i]); 
        }
        return ans == INT_MAX ? -1 : ans;
    }
};