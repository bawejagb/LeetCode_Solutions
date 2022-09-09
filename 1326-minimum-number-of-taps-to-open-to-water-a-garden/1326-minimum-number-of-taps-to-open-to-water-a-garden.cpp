class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> area;
        for(int i = 0; i <=n; i++)
            area.push_back({i - ranges[i], i + ranges[i]});
        sort(area.begin(), area.end());
        int i = 0, start = 0, end = 0, ans = 0;
        while(start < n) {
            while(i < area.size() && area[i][0] <= start) {
                end = max(end, area[i][1]);
                i++;
            }
            if(start == end) return -1;
            start = end;
            ans++;
        }
        return ans;
    }
};