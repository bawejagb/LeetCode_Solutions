class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>indeg(rooms.size(),0);
        queue<int>q;
        q.push(0);
        indeg[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:rooms[node]){
                if(!indeg[it]){
                    q.push(it);
                    indeg[it]=1;
                }
            }
        }
        for(int i=0;i<rooms.size();i++){
            if(indeg[i]==0){
                return false;
            }
        }
        return true;
    }
};