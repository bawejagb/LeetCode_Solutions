class Solution {
public:
    int tribonacci(int n) {
        int res[38]={0,1,1};
        int var=0;
        for(int i=3;i<=n;++i){
           var=res[i-1]+res[i-2]+res[i-3];
           res[i]=var;
        }
        return res[n];
    }
};