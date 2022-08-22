class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<1){
            return false;
        }
        double lg = log2(n);
        return int(lg) == lg && int(lg) % 2 == 0;
    }
};