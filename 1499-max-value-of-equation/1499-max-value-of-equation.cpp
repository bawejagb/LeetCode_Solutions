class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res=INT_MIN;
        int n = points.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            while(!pq.empty()&&abs(points[i][0]-pq.top().second)>k) pq.pop();
            if(!pq.empty())
                res = max(res, points[i][0]+points[i][1]+pq.top().first);
            pq.push({points[i][1]-points[i][0],points[i][0]});
        }
        return res;
    }
};