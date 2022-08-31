class Solution {
    void dfs(vector<vector<int>>& heights,bool flag[201][201], int prevheight, int i, int j){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || flag[i][j] || prevheight > heights[i][j]){
            return;
        }
        else{
            flag[i][j] = 1;
            dfs(heights, flag, heights[i][j], i+1, j);
            dfs(heights, flag, heights[i][j], i-1, j);
            dfs(heights, flag, heights[i][j], i, j+1);
            dfs(heights, flag, heights[i][j], i, j-1);
            return;
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        bool pacaficFlag[201][201]{}, atlanticFlag[201][201]{};
        //Pacific Ocean Visit
        for(int i=0;i<n;i++)
            dfs(heights, pacaficFlag, 0,i,0);
        for(int i=0;i<m;i++)
            dfs(heights, pacaficFlag, 0,0,i);
        //Atlantic Ocean Visit
        for(int i=0;i<n;i++)
            dfs(heights, atlanticFlag, 0,i,m-1);
        for(int i=0;i<m;i++)
            dfs(heights, atlanticFlag, 0,n-1,i);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacaficFlag[i][j]&&atlanticFlag[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};