class Solution {
    void dfs(vector<vector<int>> &room, int node, vector<bool> &visit, vector<bool> &key){
        if(visit[node]) return;
        if(!key[node]) return;
        visit[node] = true;
        for(int x : room[node]) key[x] = true;
        for(int x : room[node]){
            dfs(room, x, visit, key);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> key(n,false);
        vector<bool> visit(n,false);
        key[0] = true;
        for(int i=0;i<n;i++){
            dfs(rooms,i,visit,key);
        }
        for(int i=0;i<n;i++){
            if(!visit[i]) return false;
        }
        return true;
    }
};