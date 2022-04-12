class Solution {
   bool bfs(vector<vector<int>>&adj, vector<int>&color, vector<bool>&visit, int node){
       queue<int> qt;
       qt.push(node);
       color[node] = 1;
       while(!qt.empty()){
            int n = qt.front();
            qt.pop();
            if(visit[n]) continue;
            visit[n] = true;
            for(int x : adj[n]){
                if(color[n]==color[x]) return false;
                if(color[n]==1) color[x] = 2;
                else color[x] = 1;
                qt.push(x);
            }
       }
       return true;
   }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<bool> visit(n+1,false);
        vector<int> color(n+1,0);
        vector<vector<int>> adj(n+1);
        for(auto x : dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=1;i<=n;i++){
            if(visit[i]) continue;
            if(!bfs(adj,color, visit,i)) return false;
        }
        return true;
    }
};