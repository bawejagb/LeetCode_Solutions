class Solution {
    int LCM(int a, int b){
        long long  res = (long long) a*b;
        res = res/(long long)__gcd(a,b);
        return (int)res;
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        int a,b;
        for(int x:nums){
            res.push_back(x);
            b = res.size()-1;
            while(res.size()>1&& __gcd(res[b],res[b-1])>1){
                res.pop_back();
                res.pop_back();
                res.push_back(LCM(res[b],res[b-1]));
                b = res.size()-1;
            }
        }
        return res;
    }
};