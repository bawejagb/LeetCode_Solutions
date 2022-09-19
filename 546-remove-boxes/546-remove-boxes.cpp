class Solution {
    int dp[105][105][105]{};
    int dfs(vector<int> &arr, int left, int right, int streak){
        if(left>right) return 0;
        if(dp[left][right][streak]!=0) return dp[left][right][streak];
        int maxi;
        maxi = dfs(arr, left+1, right, 0)+(streak+1)*(streak+1);
        for(int i = left+1; i <= right; i++){
            if(arr[left]==arr[i])
                maxi =max(maxi, dfs(arr, left+1,i-1,0)+dfs(arr,i,right,streak+1)); 
        }
        return dp[left][right][streak] = maxi;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        return dfs(boxes, 0, n-1, 0);
    }
};