class Solution {
    int findParent(int x, vector<int> &parent){
        if(parent[x]==x) return x;
        return parent[x] = findParent(parent[x], parent);
    }
    bool Union(int u, int v, vector<int> &parent, vector<int> &rank){
        u = findParent(u,parent);
        v = findParent(v, parent);
        if(u != v){
            if(rank[u] > rank[v]){
                parent[v] = u;
                rank[u]++;
            }
            else{
                parent[u] = v;
                rank[v]++;
            }
            return false;
        }
        return true;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n+1,0), parent(n+1), inDeg(n+1,-1);
        int res1=-1,res2=-1;
        for(int i=1;i<=n;i++) parent[i] = i;
        for(int i=0;i<n;i++){
            if(inDeg[edges[i][1]]==-1)
                inDeg[edges[i][1]]=i;
            else{
                res1 = i;
                res2 = inDeg[edges[i][1]];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(i==res1) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            if(Union(u,v,parent,rank)){
                if(res1==-1)
                    return edges[i];
                else
                    return edges[res2];
            }
        }
        return edges[res1];
    }
};