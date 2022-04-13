class Solution {
    vector<int> parent,rank;
    int count;
    int findParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionn(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u==v) count++;
        else{
            if(rank[u]<rank[v])
                parent[u] = v;
            else if(rank[u]>rank[v])
                parent[v] = u;
            else
                parent[v] = u;
            rank[u]++;
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int H = grid.size();
        int dots = H+1;
        count = 1;
        parent.resize(dots*dots+1);
        rank.resize(dots*dots+1);
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
            rank[i] = 1;
        }
        for(int i=0;i<dots;i++){
           for(int j=0;j<dots;j++){
               if(i==0||j==0||i==dots-1||j==dots-1){
                   int cell = i*dots+j;
                   if(cell!=0)
                       unionn(0,cell);
               }
           } 
        }
        for(int i=0;i<H;i++){
            for(int j=0;j<H;j++){
                if(grid[i][j]=='/'){
                    int cell1 = i*dots+j+1;
                    int cell2 = (i+1)*dots+j;
                    unionn(cell1,cell2);
                }
                if(grid[i][j]=='\\'){
                    int cell1 = i*dots+j;
                    int cell2 = (i+1)*dots+j+1;
                    unionn(cell1,cell2);
                }
            }
        }
        return count;
    }
};