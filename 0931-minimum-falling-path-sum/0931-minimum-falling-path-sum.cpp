class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int m = a.size();
        vector<int> curr(m, -1);
        vector<int> prev(m);
        for(int j=0;j<m;j++){
            prev[j] = a[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<m;j++){
                if(j==0 and j+1<m)
                    curr[j] = a[i][j] + min(prev[j] , prev[j+1]);
                else if(j==m-1 and j-1>=0)
                    curr[j] = a[i][j] + min(prev[j] , prev[j-1]);
                else
                    curr[j] = a[i][j] + min({prev[j] , prev[j-1], prev[j+1]});
            }
            prev = curr;
        }
        return *min_element(begin(prev), end(prev));
    }
};