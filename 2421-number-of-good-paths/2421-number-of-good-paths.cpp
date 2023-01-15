class Solution {
    int find(vector<int>&parent,int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent,parent[x]);
    }
    
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int ans = n;
        vector<vector<int>> tree(n);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            tree[i]= {vals[i],1};
            parent[i] = i;
        }
        sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b){
            return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
        });
        for(int i=0;i<edges.size();i++){
            int a = find(parent,edges[i][0]);
            int b = find(parent,edges[i][1]);
            if(tree[a][0]!=tree[b][0]){
                if(tree[a][0]>tree[b][0])
                    parent[b]=a;
                else
                    parent[a]=b;
            }
            else{
                parent[a]=b;
                ans += tree[a][1]*tree[b][1];
                tree[b][1] += tree[a][1];
            }
        }
        return ans;
    }
};