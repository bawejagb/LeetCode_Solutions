class Solution {

public:
    bool hasAllCodes(string s, int k) {
        int len = pow(2,k);
        vector<bool> visit(len,false);
        int n=s.size();
        for(int i=0; i+k-1<n; i++){
            int j=i+k-1;
            int val=0, idx = 0;
            for(int k=j;k>=i;--k){
                int x = s[k] -'0';
                val += x*pow(2,idx);
                idx++;
            }
            visit[val] = true;
        }
        for(int i=0;i<len;i++)
            if(!visit[i]) return false;
        return true;
    }
};