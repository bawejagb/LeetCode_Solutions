class Solution {
    bool dfs(vector<vector<int>> &graph, int node, vector<bool> &visit, vector<bool> &stat){
        if(visit[node]) return stat[node];
        visit[node] = true;
        bool ans = true;
        for(int x: graph[node]){
            ans &= dfs(graph,x,visit,stat);
        }
        return stat[node] = ans;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        vector<bool> stat(n,false);
        vector<bool> visit(n,false);
        for(int i=0;i<n;i++){
            dfs(graph, i,visit,stat);
        }
        for(int i=0;i<n;i++){
            if(stat[i]) res.push_back(i);
        }
        return res;
    }
};