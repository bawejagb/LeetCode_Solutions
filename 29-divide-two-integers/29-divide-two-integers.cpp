class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=-1;
        long d1,d2;
        d1 = dividend;
        d2 = divisor;
        if(d1==INT_MIN && d2==-1) return INT_MAX;
        if((d1<0&&d2<0)||(d1>=0&&d2>=0))
            sign=1;
        if(d1<0) d1 *= -1;
        if(d2<0) d2 *= -1;
        long cnt=0,res=0;
        while(d1>=d2){
            cnt=0;
            while((d1- (d2<<cnt))>=0) cnt++;
            cnt--;
            res += 1<<cnt;
            d1 -= d2<<cnt;
        }
        return sign*res;
    }
};