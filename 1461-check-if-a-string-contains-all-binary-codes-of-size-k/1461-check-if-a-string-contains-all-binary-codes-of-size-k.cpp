class Solution {

public:
    bool hasAllCodes(string s, int k) {
        int len = pow(2,k);
        vector<bool> visit(len,false);
        int n=s.size();
        for(int i=0; i+k-1<n; i++){
            int j=i+k-1;
            int val=0;
            for(int t=i;t<=j;++t) {
                val <<= 1;
                val += (s[t] - '0');
            }
            visit[val] = true;
        }
        for(int i=0;i<len;i++)
            if(!visit[i]) return false;
        return true;
    }
};