class Solution {
    int fun(int x, int K, int N) {
        int ans = 0, r = 1;
        for (int i = 1; i <= K; ++i) {
            r *= x-i+1;
            r /= i;
            ans += r;
            if (ans >= N) break;
        }
        return ans;
    }
public:
    int superEggDrop(int k, int n) {
        int lo = 1, hi = n;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (fun(mi, k, n) < n)
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
    }
};