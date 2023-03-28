class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366]{};
        unordered_set<int> travelDays;
        for (int day : days)
            travelDays.insert(day);
        for (int i = 1; i <= 365; i++) {
            if (travelDays.find(i) == travelDays.end())
                dp[i] = dp[i-1];
            else
                dp[i] = min(dp[i-1] + costs[0], min(dp[max(0, i-7)] + costs[1], dp[max(0, i-30)] + costs[2]));
        }
        return dp[365];
    }
};