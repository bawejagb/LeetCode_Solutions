class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = size(nums);
        int q[n+k];
        int front = 0;
        int back = 0;
        vector<int> ans(n-k+1);
        for (int i=0; i<k; ++i){
            int num = nums[i];
            while(back-front>0 && num>nums[q[back-1]]){
                --back;
            }
            q[back++] = i;
        }
        for (int i=k; i<n; ++i){
            int l = i-k;
            ans[l] = nums[q[front]];
            int num = nums[i];
            while(back-front>0 && num>nums[q[back-1]]){
                --back;
            }
            q[back++] = i;
            if (q[front] <= l){
                ++front;
            }
        }
        ans[n-k] = nums[q[front]];
        return ans;
    }
};