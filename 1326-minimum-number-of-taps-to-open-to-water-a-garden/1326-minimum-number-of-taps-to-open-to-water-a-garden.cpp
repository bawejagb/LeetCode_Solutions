class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1, 0);
        for (int i=0; i<ranges.size(); i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            jumps[l] = max(jumps[l], r-l);
        }
        int count = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i<n; i++) {
            if (i>curFarthest)
                return -1;
            curFarthest = max(curFarthest, i + jumps[i]);
            
            if (i == curEnd) {
                count++;
                curEnd = curFarthest;
            }
        }
        return curFarthest >= n ? count : -1;
    }
};