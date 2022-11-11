class Solution {
    bool dfs(vector<int> graph[], vector<int> &visit, int node){
        if(visit[node]==2) return true;
        if(visit[node]==1) return false;
        visit[node] = 1;
        bool res = true;
        for(int nbr : graph[node]){
            res &= dfs(graph, visit, nbr);
        }
        if(res) visit[node] = 2;
        return res;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visit(numCourses,0), graph[numCourses];
        for(auto pr : prerequisites)
            graph[pr[0]].push_back(pr[1]);
        for(int i=0;i<numCourses;i++){
            if(visit[i]==2) continue;
            if(!dfs(graph, visit, i)) return false;
        }
        return true;
    }
};