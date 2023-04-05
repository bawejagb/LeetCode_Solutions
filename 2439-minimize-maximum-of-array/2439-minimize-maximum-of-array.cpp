class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long ans=0,sm=0;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            ans=max(ans,(sm+i)/(i+1));
        }
        return ans;
    }
};