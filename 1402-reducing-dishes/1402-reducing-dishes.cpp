class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> score(satisfaction.size(), vector<int>(satisfaction.size(), INT_MIN));
        for (int i = 0; i < satisfaction.size(); ++i) {
            score[i][0] = satisfaction[i];
        }
        int res = 0;
        for (int i = 1; i < satisfaction.size(); ++i) {
            for (int j = 1; j <= i; ++j) {
                score[i][j] = max(score[i - 1][j - 1] + satisfaction[i] * (j + 1), score[i - 1][j]);
                res = max(score[i][j], res);
            }
        }
        return res;
    }

};