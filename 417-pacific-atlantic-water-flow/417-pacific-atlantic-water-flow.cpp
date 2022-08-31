class Solution {
    void dfs(vector<vector<int>>& heights,bool flag[201][201], int row, int col){
        flag[row][col]=true;
        int n = heights.size();
        int m = heights[0].size();
        if(row>0 && !flag[row-1][col] && heights[row-1][col]>=heights[row][col])
            dfs(heights, flag, row-1, col);
        if(row<n-1 && !flag[row+1][col] && heights[row+1][col]>=heights[row][col])
            dfs(heights, flag, row+1, col);
        if(col>0 && !flag[row][col-1] && heights[row][col-1]>=heights[row][col])
            dfs(heights, flag, row, col-1);
        if(col<m-1 && !flag[row][col+1] && heights[row][col+1]>=heights[row][col])
            dfs(heights, flag, row, col+1);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        bool pacaficFlag[201][201]{}, atlanticFlag[201][201]{};
        //Pacific Ocean Visit
        for(int i=0;i<n;i++)
            dfs(heights, pacaficFlag, i,0);
        for(int i=0;i<m;i++)
            dfs(heights, pacaficFlag, 0,i);
        //Atlantic Ocean Visit
        for(int i=0;i<n;i++)
            dfs(heights, atlanticFlag, i,m-1);
        for(int i=0;i<m;i++)
            dfs(heights, atlanticFlag, n-1,i);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacaficFlag[i][j]&&atlanticFlag[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};