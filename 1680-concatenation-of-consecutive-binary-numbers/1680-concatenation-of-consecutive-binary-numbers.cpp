class Solution {
public:
    int concatenatedBinary(int n) {
        long ans=0;
        for(int i=1;i<=n;i++){
            ans = ans<<(int)(log2(i)+1);
            ans = (ans|i)%((long)1e9+7);
        }
        return ans;
    }
};