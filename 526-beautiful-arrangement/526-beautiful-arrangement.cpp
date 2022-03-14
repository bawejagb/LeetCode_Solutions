class Solution {
    int res;
    void backtrack(int n,vector<bool> visit, int cnt){
        if(cnt==n+1){
            res++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!visit[i]&&(i%cnt==0||cnt%i==0)){
                visit[i]=1;
                backtrack(n,visit,cnt+1);
                visit[i]=0;
            }
        }
    }
public:
    int countArrangement(int n) {
        res=0;
        vector<bool> visit(n+1,0);
        backtrack(n,visit,1);
        return res;
    }
};