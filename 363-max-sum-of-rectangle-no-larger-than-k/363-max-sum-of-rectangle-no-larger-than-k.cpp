class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN;
        int R = matrix.size();
        int C = matrix[0].size();
        int arr[R];
        for(int l = 0; l < C; ++l) {
            memset(arr, 0, sizeof(arr));
            for(int r = l; r < C; ++r) 
            {
                for(int up = 0; up < R; ++up)
                {
                    arr[up] += matrix[up][r]; 
                }
                int sum = 0, g = INT_MIN;
                for(int up = 0; up < R; ++up) 
                {
                    sum = max(sum + arr[up], arr[up]);
                    g = max(g, sum);
                    if(g == k) 
                        return k;
                }
                if(g < k) 
                {
                    ans = max(ans, g);
                } 
                else 
                {
                    for(int up1 = 0; up1 < R; ++up1) 
                    {
                        sum = 0;
                        for(int up2 = up1; up2 < R; ++up2) 
                        {
                            sum += arr[up2];
                            if(sum <= k) 
                                ans = max(ans, sum);
                        }
                        
                        if(ans == k) return k;
                    }
                }
            }
        }
        return ans;
    }
};