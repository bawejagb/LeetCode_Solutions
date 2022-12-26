class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpNeed = -1;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            jumpNeed++;
            if(nums[i]>=jumpNeed)
                jumpNeed=0;
        }
        return jumpNeed==0;
    }
};