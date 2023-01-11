class Solution {
    int res;
    bool findCount(vector<vector<int>>& tree,vector<bool>&visit,vector<bool>&hasApple,int node){
        if(visit[node]) return false;
        visit[node] = true;
        bool apple = hasApple[node];
        for(int nb : tree[node]){
            if(findCount(tree,visit,hasApple,nb)){
                res += 2;
                apple= true;
            }
        }
        return apple;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        res=0;
        vector<vector<int>> tree(n);
        vector<bool> visit(n,false);
        for(auto pr : edges){
            tree[pr[0]].push_back(pr[1]);
            tree[pr[1]].push_back(pr[0]);
        }
        findCount(tree, visit, hasApple, 0);
        return res;
    }
};