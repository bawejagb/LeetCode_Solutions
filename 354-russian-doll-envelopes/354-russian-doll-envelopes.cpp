class Solution {
    static bool cmp(const pair<int, int> &A, const pair<int, int> &B){
        return A.first==B.first ? A.second>B.second : A.first<B.first;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int, int> > temp, seq;
        int n = envelopes.size();
        for (int i = 0; i < n; i++) {
            temp.push_back({envelopes[i][0],envelopes[i][1]});
        }
        sort(temp.begin(), temp.end(), cmp);
        vector<int> res;
        for(auto& pr: temp)
        {
            auto itr = lower_bound(res.begin(), res.end(), pr.second);
            if(itr == res.end()) res.emplace_back(pr.second);
            else if(*itr > pr.second) *itr = pr.second;
        }
        return res.size();
    }
};