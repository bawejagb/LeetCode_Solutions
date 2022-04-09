class Solution {
    map<string,vector<pair<string,double>>> graph;
    void dfs(string u, string v, double &ans, double val, set<string> visit){
        if(graph.find(u)==graph.end()) return;
        if(visit.find(u)!=visit.end()) return;
        visit.insert(u);
        if(u == v){
            ans = val;
            cout << val<< ' ';
            return;
        }
        for(auto x: graph[u]){
            dfs(x.first, v, ans, val*x.second, visit);
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for(int i = 0; i < equations.size(); i++){
            string v, u;
            u = equations[i][0];
            v = equations[i][1];
            graph[u].push_back({v,values[i]});
            graph[v].push_back({u,1/values[i]});
        }
        double ans, val;
        for(auto x: queries){
            string u = x[0];
            string v = x[1];
            ans = -1;
            val = 1;
            set<string> visit;
            dfs(u,v,ans,val,visit);
            res.push_back(ans);
        }
        return res;
    }
};