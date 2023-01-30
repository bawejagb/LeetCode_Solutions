class Solution {
public:
    int tribonacci(int n) {
        vector<int>res={0,1,1};
        int var=0;
        for(int i=3;i<n+1;++i){
           var=res[i-1]+res[i-2]+res[i-3];
           res.push_back(var);
        }
        return res[n];
    }
};