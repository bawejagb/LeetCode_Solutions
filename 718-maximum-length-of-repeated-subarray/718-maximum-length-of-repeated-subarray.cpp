class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[1001]{};
        int res=0,prev=0,temp=0;
        for(int i=0;i<nums1.size();i++){
            prev = 0;
            for(int j=0;j<nums2.size();j++){
                temp = dp[j+1];
                if(nums1[i]==nums2[j]){
                    dp[j+1] = prev+1;
                    res = max(res,dp[j+1]);
                }
                else
                    dp[j+1] = 0;
                prev = temp;
            }
        }
        return res;
    }
};