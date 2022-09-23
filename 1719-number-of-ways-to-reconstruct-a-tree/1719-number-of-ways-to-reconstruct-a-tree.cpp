class Solution {
public:
    int checkWays(vector<vector<int>>& ps) {
        int n = 0;
        for (auto& p : ps) {
            n = max(p[0], n);
            n = max(p[1], n);
        }
        vector<bitset<500>> s(n + 1);
        bitset<500> dp;
        for (auto& p : ps) {
            s[p[0]][p[1]] = 1;
            s[p[1]][p[0]] = 1;

            dp[p[0]] = 1;
            dp[p[1]] = 1;
        }
        int i = 0;
        for (auto& v : s)
        {
            v[i] = 1;
            i++;
        }
        bool e = false, m = false;
        int tt = dp.count();
        for (auto& v : s)if (v.count() == tt)e = true;
        if (!e)return 0;
        for (auto p : ps) {
            bool a = ((s[p[0]] | s[p[1]]) == s[p[0]]), b = ((s[p[0]] | s[p[1]]) == s[p[1]]);
            if (!a && !b)return 0;
            m |= a && b;
        }
        return 1 + m;
    }
};