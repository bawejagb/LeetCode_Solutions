class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> vp;
        for(auto pr : points)
            vp.push_back({pr[0],pr[1]});
        sort(vp.begin(), vp.end());
        int cnt=1, maxDis=vp[0].second;
        for(auto pr : vp){
            if(pr.first>maxDis){
                maxDis = pr.second;
                cnt++;
            }
            maxDis = min(maxDis, pr.second);
        }
        return cnt;
    }
};