class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res=0, n = img1.size();
        vector<pair<int,int>> temp1,temp2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1) temp1.push_back({i,j});
                if(img2[i][j]==1) temp2.push_back({i,j});
            }
        }
        map<pair<int,int>,int> hmap;
        for(auto [a,b]: temp1){
            for(auto [c,d]: temp2){
                hmap[{a-c,b-d}]++;
                res = max(res,hmap[{a-c,b-d}]);
            }
        }
        return res;
    }
};