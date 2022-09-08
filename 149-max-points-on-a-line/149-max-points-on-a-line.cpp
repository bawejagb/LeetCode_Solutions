class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cnt,mx = 2;
        if(n<=2) return n;
        for(int i=0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                cnt=2;
                for(int k = 0; k < n; k++){
                    if(k != i && k != j){
                        if((points[j][1]-points[i][1])*(points[k][0]-points[i][0])==(points[j][0]-points[i][0])*(points[k][1]-points[i][1]))
                            cnt++;
                    }
                }
                mx = max(cnt,mx);
            }
        }
        return mx;
    }
};