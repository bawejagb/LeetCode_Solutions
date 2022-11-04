class Solution {
    const int NO_RANK = -2;
    int dfs(vector<int> graph[], int n, int node, int myRank, vector<int> &rank, vector<vector<int>> &res){
        if(rank[node]!=NO_RANK) return rank[node];
        rank[node] = myRank;
        int lowRank = myRank;
        for(int nbr: graph[node]){
            if(rank[nbr]==myRank-1 || rank[nbr]==n) continue;
            int nbrRank = dfs(graph, n, nbr, myRank+1, rank, res);
            if(nbrRank>myRank) res.push_back({min(nbr, node), max(nbr,node)});
            lowRank = min(lowRank, nbrRank);
        }
        rank[node] = n;
        return lowRank;
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> rank(n,NO_RANK);
        vector<int> graph[n];
        vector<vector<int>> res;
        for(auto pr: connections){
            graph[pr[0]].push_back(pr[1]);
            graph[pr[1]].push_back(pr[0]);
        }
        dfs(graph, n, 0,0, rank,res);
        return res;
    }
};