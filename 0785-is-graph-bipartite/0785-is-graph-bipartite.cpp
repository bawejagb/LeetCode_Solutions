class Solution {
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int u, int col){
        if(color[u]==col) return true;
        if(color[u]!=0) return false;
        color[u] = col;
        for(int x: graph[u]){
            if(!dfs(graph, color, x, col*-1))
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
        
        for(int i=0;i<n;i++){
            if(color[i]==0){
                if(!dfs(graph, color, i, 1)) return false;
            }
        }
        return true;
    }
};