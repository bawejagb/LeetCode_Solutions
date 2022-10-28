class Solution {
public:
    int nthUglyNumber(int n) {
        int res[n];
        int idx=1,two=0, three=0, five=0;
        res[0] = 1;
        while(idx<n){
            int val2 = res[two]*2;
            int val3 = res[three]*3;
            int val5 = res[five]*5;
            int minVal = min({val2,val3,val5});
            if(minVal==val2) two++;
            else if(minVal==val3) three++;
            else five++;
            if(minVal==res[idx-1]) continue;
            res[idx] = minVal;
            idx++;
        }
        return res[n-1];
    }
};