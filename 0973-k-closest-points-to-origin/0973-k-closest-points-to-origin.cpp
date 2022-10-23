class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        if(n<=k) return points;
        vector<int> dis(n),idx(n);
        vector<vector<int>> res(k);
        for(int i=0;i<n;i++){
            idx[i] = i;
            dis[i] = points[i][0]*points[i][0]+points[i][1]*points[i][1];
        }
        auto cmp = [&dis](int a, int b){
            return dis[a]<dis[b];
        };
        nth_element(idx.begin(),idx.begin()+k,idx.end(),cmp);
        for(int i=0;i<k;i++){
            res[i] = points[idx[i]];
        }
        return res;
    }
};