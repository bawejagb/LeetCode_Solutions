class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int count = minutesToTest / minutesToDie;
        double a = log2(count + 1);
        double b = log2(buckets);
        
        return ceil(b / a);
    }
};