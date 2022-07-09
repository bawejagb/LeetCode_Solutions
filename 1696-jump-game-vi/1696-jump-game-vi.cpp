class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int dq[nums.size()],bk=0,fr=0;
        dq[bk++]=0;
        for(int i=1;i<nums.size();++i){
            if(i-dq[fr]>k)++fr;
            nums[i]+=nums[dq[fr]];
            while(bk>fr&&nums[i]>=nums[dq[bk-1]])--bk;
            dq[bk++]=i;
        }
        return nums[nums.size()-1];
    }
};