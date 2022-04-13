class Solution {
    map<int,vector<int>> row,col;
    void dfs(int id, vector<bool>&visit, vector<vector<int>>&stones){
        if(visit[id]) return;
        visit[id] = true;
        int x,y;
        x = stones[id][0];
        y = stones[id][1];
        for(int a : row[x])
            dfs(a,visit,stones);
        for(int b : col[y])
            dfs(b,visit,stones);
        }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visit(n,false);
        
        for(int i=0;i<n;i++){
            int x,y;
            x = stones[i][0];
            y = stones[i][1];
            row[x].push_back(i);
            col[y].push_back(i);
        }
        int res=0;
        for(int j=0;j<n;j++){
            if(!visit[j]){
                dfs(j,visit,stones);
                res++;
            }
            
        }
        return n-res;
    }
};