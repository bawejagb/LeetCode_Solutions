class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1) return triangle[0][0];
        int ans = INT_MAX;
        int m = triangle.size();
        for(int i=1; i<m; i++){
            int n = triangle[i].size();
            for(int j=0; j<n; j++){
                if(j==0){
                    triangle[i][j] += triangle[i-1][j];
                }
                else if(j==n-1){
                    triangle[i][j] += triangle[i-1][j-1];
                }
                else{
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
                if(i==m-1){
                    ans = min(ans, triangle[i][j]);
                }
            }
        }
        
        return ans;
    }
};