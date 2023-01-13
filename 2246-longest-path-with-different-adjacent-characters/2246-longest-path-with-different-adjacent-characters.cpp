class Solution {
    int res=1;
    int dfs(vector<vector<int>>&tree, string &s, int node){
        if(tree[node].size()==0) return 1;
        int len,mx1=0,mx2=0;
        for(int child : tree[node]){
            len = dfs(tree,s,child);
            if(s[node]==s[child]) continue;
            if(len>mx1){
                mx2 = mx1;
                mx1 = len;
            }
            else
                mx2 = max(mx2,len);
        }
        res = max(res, 1+mx2+mx1);
        return mx1+1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        for(int i=1;i<n;i++)
            tree[parent[i]].push_back(i);
        dfs(tree, s, 0);
        return res;
    }
};