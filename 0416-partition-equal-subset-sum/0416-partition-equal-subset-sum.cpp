class Solution {
    template <int N>
    bool canPartitionN(vector<int>& nums, int target) {
        using Set = bitset<N + 1>;
        Set cur;
        cur.set(0);
        for (int val : nums) {
            cur |= cur << val;
            if (cur[target]) {
                return true;
            }
        }
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sm = 0;
        for(int num : nums)
            sm += num;
        if(sm%2) return false;
        sm /= 2;
        return canPartitionN<10000>(nums, sm);
    }
};