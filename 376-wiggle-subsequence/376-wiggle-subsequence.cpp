class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int prevDiff = nums[1]-nums[0];
        int cnt = prevDiff==0?1:2;
        for(int i=2;i<nums.size();i++){
            int diff = nums[i]-nums[i-1];
            if((diff>0&&prevDiff<=0)||(diff<0&&prevDiff>=0)){
                cnt++;
                prevDiff = diff;
            }
        }
        return cnt;
    }
};