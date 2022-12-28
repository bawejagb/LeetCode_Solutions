class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int res=0;
        int freq[10001]={};
        for(int val : piles)
            freq[val]++;
        for(int i=10000; i and k; i--){
            int rem = min(k,freq[i]);
            freq[i-i/2] += rem;
            freq[i] -= rem;
            k -= rem;
        }
        for(int i=1;i<=10000;i++)
            res += i*freq[i];
        return res;
    }
};