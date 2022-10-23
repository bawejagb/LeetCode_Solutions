class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        int n = points.size();
        for(int i=0;i<n;i++){
            int dis = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dis,{points[i][0],points[i][1]}});
        }
        n -= k;
        while(n--) pq.pop();
        vector<vector<int>> res;
        while(k--){
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};