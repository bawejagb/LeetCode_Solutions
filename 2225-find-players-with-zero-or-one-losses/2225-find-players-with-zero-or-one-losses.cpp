class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> r1,r2;
        map<int,int> win,loss;
        for(auto pr : matches){
            win[pr[0]]++;
            loss[pr[1]]++;
        }
        for(auto p : win){
            if(loss.find(p.first)==loss.end())
                r1.push_back(p.first);
        }
        for(auto p: loss){
            if(p.second==1)
                r2.push_back(p.first);
        }
        return {r1,r2};
    }
};