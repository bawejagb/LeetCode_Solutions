class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int cnt=1, minDis=points[0][0],maxDis=points[0][1];
        for(auto pr : points){
            if(pr[0]>maxDis){
                maxDis = pr[1];
                cnt++;
            }
            maxDis = min(maxDis, pr[1]);
            minDis = max(minDis, pr[0]);
        }
        return cnt;
    }
};