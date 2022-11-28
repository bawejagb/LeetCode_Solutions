class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int player[100001] = {0}, loss[100001] = {0};
        for(int i = 0; i < matches.size(); i++) {
            player[matches[i][0]]++;
            player[matches[i][1]]++;
            loss[matches[i][1]]++;
        }
        
        vector<vector<int>> ans(2);
        for(int i = 0; i < 100001; i++)   {
            if(player[i] && (loss[i] == 0))
                ans[0].push_back(i);
            if(player[i] && (loss[i] == 1))
                ans[1].push_back(i);
        }
        return ans;
    }
};