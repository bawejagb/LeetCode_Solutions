class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int val, ans, smin = nums[0]+nums[1]+nums[2];
        for(int i = 0; i < n-2; i++){
            int start,end;
            start = i+1;
            end = n-1;
            while(start < end){
                val = nums[i]+nums[start]+nums[end];
                if(val > target)
                    end--;
                else if(val < target)
                    start++;
                else return val;
                
                if(abs(target-val) < abs(target-smin)){
                    smin = val;
                }
            }
        }
        return smin;
    }
};