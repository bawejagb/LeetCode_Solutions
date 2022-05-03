class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int a,b,mx,mn;
        a = b = -1;
        mx = INT_MIN;
        mn = INT_MAX;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            if(mx>nums[i]) b = i;
        }
        for(int i=n-1;i>=0;i--){
            mn = min(mn,nums[i]);
            if(mn<nums[i]) a = i;
        }
        if(a==b) return 0;
        return b-a+1;
    }
};