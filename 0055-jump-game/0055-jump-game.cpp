class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = nums[0];
        if(nums.size()==1) return true;
        for(int i=1;i<nums.size()-1;i++){
            if(mx==0) return false;
            mx = max(mx-1,nums[i]);
        }
        if(mx>0) return true;
        return false;
    }
};