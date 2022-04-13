class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> del(n,false),visit(n,false);
        queue<int>qt;
        for(int j=0;j<n;j++){
            if(visit[j]) continue;
            qt.push(j);
            while(!qt.empty()){
                int p = qt.front();
                qt.pop();
                int x,y;
                visit[p] = true;
                x = stones[p][0];
                y = stones[p][1];
                for(int i=0;i<n;i++){
                    if(visit[i]) continue;
                    if(stones[i][0]==x||stones[i][1]==y){
                        qt.push(i);
                        del[i] = true;
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(del[i]) res++;
        }
        return res;
    }
};