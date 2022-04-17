class Solution {
    int find(int n, vector<int>& parent){
        if(parent[n]==-1) return n;
        return parent[n] = find(parent[n], parent);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra = 0;
        vector<int> parent(n,-1);
        vector<int> rank(n,1);
        for(auto x : connections){
            int f1 = find(x[0],parent);
            int f2 = find(x[1],parent);
            if(f1!=f2){
                if(rank[f1]>rank[f2]){
                    parent[f2] = f1;
                    rank[f1] += rank[f2];
                }
                else{
                    parent[f1] = f2;
                    rank[f2] += rank[f1];
                }
            }
            else
                extra++;
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1) cnt++;
        }
        return extra>=cnt-1? cnt-1: -1;
    }
};