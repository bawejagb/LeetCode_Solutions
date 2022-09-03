class Solution {
    set<int> res;
    void dfs(int n, int k, int num){
        if(n==0){
            res.insert(num);
            return;
        }
        int prev = num%10;
        if(prev+k<10)
            dfs(n-1, k, num*10+prev+k);
        if(prev-k>=0)
            dfs(n-1,k,num*10+prev-k);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1; i<10; i++)
            dfs(n-1,k,i);
        vector<int> ans(res.begin(),res.end()); 
        return ans;
    }
};